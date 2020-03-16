/*
 *  Problem: https://leetcode.com/problems/total-hamming-distance/
 *  Compile: g++ -o totalHammingDistance totalHammingDistance.cpp -std=c++11 -g -Wall -fsanitize=address && ./totalHammingDistance
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

int get_bit(int num, int m) {
    int mask = 1 << m;
    return((num & mask) != 0);
}

int hammingDistance(int a, int b) {
    int d = 0;
    for(int i = 0; i < 31; i++) {
        if((get_bit(a, i)) ^ (get_bit(b, i))) {
            d++;
        }
    }
    return(d);
}

int totalHammingDistance1(std::vector<int>& nums) {
    if(nums.empty()) return(0);
    int d = 0;
    for(int i = 0; i < nums.size()-1; i++) {
        for(int j = i+1; j < nums.size(); j++) {
            d += hammingDistance(nums[i], nums[j]);
        }        
    }
    return(d);    
}

int totalHammingDistance(std::vector<int>& nums) {
    if(nums.empty()) return(0);
    int m = nums.size();
    std::vector<int> bits(32, 0);
    
    for(auto n: nums) {
        for(int i = 0; i < 32; i++) {
            if((1 << i) & n) {
                bits[i]++;
            }
        }
    }
    
    int d = 0;
    for(auto b: bits) {
        d += (m-b) * b;
    }

    return(d);    
}

int main(int argc, char** argv){
    std::vector<int> nums = {4, 14, 2};
    int t = totalHammingDistance(nums);
    printf("\ntotalHammingDistance=%d\n", t);
    return(0);
}