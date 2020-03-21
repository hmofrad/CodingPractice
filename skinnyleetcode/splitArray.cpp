/*
 *  Problem: https://leetcode.com/problems/split-array-largest-sum/
 *  Compile: g++ -o splitArray splitArray.cpp -std=c++11 -g -Wall -fsanitize=address && ./splitArray
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

int splitArray(std::vector<int>& nums, int m) {
    int largestSum = 0;
    std::vector<std::vector<int>> partitions(m);
    std::vector<int> sums(m);
    std::vector<int> szs(m,1);
    int diff = 0;
    
    while(true) {
        int j = 0;
        for(uint32_t i = 0; i < m; i++) {
            partitions[i].push_back(nums[j]);
        
        }
        
    }

    
    
        
}

int main(int argc, char **argv){
    std::vector<int> nums = {[7,2,5,10,8]};
    int m = 2;
    int largestSum = splitArray(nums, m);
    printf("largestSum=%d\n", largestSum);
    return(0);
}






