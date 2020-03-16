/*
 *  Problem: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
 *  Compile: g++ -o findMaximumXOR findMaximumXOR.cpp -std=c++11 -g -Wall -fsanitize=address && ./findMaximumXOR
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

int findMaximumXOR(std::vector<int>& nums) {
    int max_val = 0;
    for(uint32_t i = 0; i < nums.size()-1; i++) {
        for(uint32_t j = i+1; j < nums.size(); j++) {    
            int xor_val = nums[i] ^ nums[j];
            if(xor_val > max_val) {
            max_val = xor_val;
            }
        }
    }        
    return(max_val);
}

int findMaximumXOR1(std::vector<int>& nums) {
    int max_val = 0;
    for(uint32_t i = 0; i < nums.size(); i++) {

    }        
    return(max_val);
}

int main(int argc, char** argv){
    std::vector<int> nums = {3, 10, 5, 25, 2, 8};
    int m = findMaximumXOR1(nums);
    printf("%d\n", m);
    return(0);
}