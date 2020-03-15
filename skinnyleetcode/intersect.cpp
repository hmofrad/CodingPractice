/*
 *  Problem: https://leetcode.com/problems/intersection-of-two-arrays-ii/
 *  Compile: g++ -o intersect intersect.cpp -std=c++11 -g -Wall -fsanitize=address && ./intersect
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>

void print(std::vector<int> nums) {
    for(auto n: nums) {
        printf("%d ", n);
    }
    printf("\n");
}

std::vector<int> intersect1(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> nums;
    int m1 = nums1.size();
    int m2 = nums2.size();   

    std::unordered_map<int, int> map;
    
    for(auto n: nums1) map[n]++;
    
    for(auto n: nums2) {
        if(map[n]) {
            map[n]--;
            nums.push_back(n);
        }
    }
    return(nums);
}

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> nums;
    int m1 = nums1.size();
    int m2 = nums2.size();   

    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    
    int i1 = 0;
    int i2 = 0;
    while(i1 < m1 and i2 < m2) {
        if(nums1[i1] == nums2[i2]) {
            nums.push_back(nums1[i1]);
            i1++;
            i2++;
        }
        else if(nums1[i1] < nums2[i2])  {
            i1++;
        }
        else {
            i2++;
        }
    }
    return(nums);
}

int main(int argc, char **argv){
    std::vector<int> nums1 = {4,9,5};
    std::vector<int> nums2 = {9,4,9,8,4};
    
    std::vector<int> nums = intersect(nums1, nums2);
    
    print(nums1); print(nums2); print(nums);
    
    return(0);
}