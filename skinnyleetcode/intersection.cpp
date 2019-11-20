    /*
 *  Problem: https://leetcode.com/problems/intersection-of-two-arrays/
 *  Compile: g++ -o intersection intersection.cpp -std=c++11 && ./intersection #-fsanitize=address 
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <string.h>
#include <unordered_set>
#include <stack>
#include <numeric>
#include <map>
#include <cmath>
#include <unordered_map>
#include<bits/stdc++.h> 

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> nums;
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    int i1 = 0;
    int i2 = 0;
    while(i1 < nums1.size() and i2 < nums2.size()) {
        printf("%d %d %d \n", i1, i2, nums.empty());
        if(nums1[i1] == nums2[i2]) {
            if(nums.empty()) {
                nums.push_back(nums1[i1]);
            }
            else if(nums.back() != nums1[i1]) {
                nums.push_back(nums1[i1]);
            }
            i1++;
            i2++;
        }
        else if(nums1[i1] < nums2[i2]) {
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
    std::vector<int> nums3 = intersection(nums1, nums2);
    for(auto& n: nums3)
        printf("%d ", n);
    printf("\n");
    
    
    
    return(0);
}






