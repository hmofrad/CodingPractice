/*
 *  Problem: merge2
 *  Compile: g++ -o merge0 merge0.cpp -std=c++11 && ./merge0
 *  Execute: ./merge2
 *  (c) Mohammad Mofrad, 2018
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


void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    
    std::vector<int> nums;
    int j1 = 0;
    int j2 = 0;
    while((j1 < m) and (j2 < n)) {
        if(nums1[j1] == nums2[j2]) {
            nums.push_back(nums1[j1]);
            nums.push_back(nums2[j2]);
            j1++;
            j2++;
        }
        else if(nums1[j1] < nums2[j2]) {
            nums.push_back(nums1[j1]);
            j1++;
        }
        else {
            nums.push_back(nums2[j2]);
            j2++;
        }
    }
    
    if(j1 < m) {
        for(int i = j1; i < m; i++) {
            nums.push_back(nums1[i]);
        }
    }
    else if(j2 < n) {
        for(int i = j2; i < n; i++) {
            nums.push_back(nums2[i]);
        }
    }
    nums1 = nums;
    
    for(int j: nums) {
        printf("%d ", j);
    }
    printf("\n");
}


int main(int argc, char** argv) {
    int m = 3;
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0, 0};
    int n = 4;
    std::vector<int> nums2 = {1, 2, 5, 6};
    
    for(int i = 0; i < m; i++)
        printf("%d ", nums1[i]); 
    printf("\n");
    
    for(int i = 0; i < n; i++)
        printf("%d ", nums2[i]);
    printf("\n");
    
    merge(nums1, m, nums2, n);
    
    for(int i = 0; i < m+n; i++)
        printf("%d ", nums1[i]);
    printf("\n");
    
    return(0);
}