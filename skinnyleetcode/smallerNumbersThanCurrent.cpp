/*
 *  Problem: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
 *  Compile: g++ -o smallerNumbersThanCurrent smallerNumbersThanCurrent.cpp -std=c++11 -g -Wall -fsanitize=address && ./smallerNumbersThanCurrent
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>

std::vector<int> smallerNumbersThanCurrent1(std::vector<int>& nums) {
     int m = nums.size();
    std::vector<int> smallers(m);
    if(m) {
        for(int i = 0; i < m; i++) {
            int k = 0;
            for(int j = 0; j < m; j++) {
                if(nums[i] > nums[j]) {
                    k++;
                }
            }           
            smallers[i] = k;    
        }
    }
    return(smallers);    
}

std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
    int m = nums.size();
    std::vector<int> smallers(m);
    if(m) {
        std::unordered_map<int, int> map1;
        std::unordered_map<int, std::deque<int>> map2;
        for(int i = 0; i < m; i++) {
            map1[nums[i]]++;
            map2[nums[i]].push_back(i);
        }
        std::sort(nums.begin(), nums.end(), [](int a, int b){return(a>b);});
        for(int i = 0; i < m; i++) {
            auto& v = map2.find(nums[i])->second;
            smallers[v.front()] = m - map1.find(nums[i])->second - i;
            //printf("%d %d %d %d\n", i, nums[i], v.front(), v.size());
            v.pop_front();
            map1[nums[i]]--;
        }
    }
    return(smallers); 
}

int main(int argc, char** argv){
    std::vector<int> nums = {8,1,2,2,3};
    std::vector<int> nums1 = smallerNumbersThanCurrent(nums);
    for(auto n: nums1){printf("%d ", n);} printf("\n");
    return(0);
}