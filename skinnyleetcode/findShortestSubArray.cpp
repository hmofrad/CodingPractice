/*
 *  Problem: https://leetcode.com/problems/degree-of-an-array/
 *  Compile: g++ -o findShortestSubArray findShortestSubArray.cpp -std=c++11 -g -Wall -fsanitize=address && ./findShortestSubArray
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

int degree(std::vector<int> nums, uint32_t l, uint32_t r) {
    std::unordered_map<int, int> map;
    for(uint32_t i = l; i <= r; i++) {
        map[nums[i]]++;
    }
    int d = 0;
    for(auto m: map) {
        if(m.second > d) {
            d = m.second;
        }
    }
    return(d);
}

int findShortestSubArray1(std::vector<int>& nums) {
    if(nums.empty()) return(0);
    int max_d = degree(nums, 0, nums.size()-1);

    uint32_t left = 0;
    uint32_t right = nums.size()-1;
    uint32_t len = 0;
    uint32_t len0 = 0;

    do{    
        len = left - right + 1;
        if(left < right-1) {
            int dr = degree(nums, left, right-1);
            if(dr == max_d) {
                right--; 
            }
        }

        if(left+1 < right) {
            int dl = degree(nums, left+1, right);
            if(dl == max_d) {
                left++; 
            }
        }
        len0 = left - right + 1;
    } while(len != len0);
    
    return(right-left+1);    
}

int findShortestSubArray(std::vector<int>& nums) {
    std::unordered_map<int, uint32_t> left;
    std::unordered_map<int, uint32_t> count;
    uint32_t max_c = 0;
    uint32_t max_i = 0;
    uint32_t max_l = 0;
    for(uint32_t i = 0; i < nums.size(); i++) {
        int j = nums[i];
        
        count[j]++;  
        if(count[j] == 1) {
            left[j] = i;  
        }
        
        if(count[j] > max_c) {
            max_c = count[j];
            max_i = left[j];
            max_l = i - left[j] + 1;
        }
        else if((count[j] == max_c) and (i - left[j] + 1 < max_l)){
            max_l = i - left[j] + 1;
            max_i = left[j];
        }
    }
    /*
    printf("%d %d %d\n", max_c, max_i, max_l);
    
    for(auto l: left) {
        printf("[%d %d] ", l.first, l.second);
    }
    printf("\n");
    for(auto c: count) {
        printf("[%d %d] ", c.first, c.second);
    }
    */
    return(max_l);
}

int main(int argc, char **argv){
    std::vector<int> nums = {1, 2, 2, 3, 1, 3, 2};
    
    int ret = findShortestSubArray(nums);
    
    printf("%d\n", ret);
    
    return(0);
}