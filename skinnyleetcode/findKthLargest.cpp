/*
 *  Problem: https://leetcode.com/problems/kth-largest-element-in-an-array/
 *  Compile: g++ -o findKthLargest findKthLargest.cpp -std=c++11 && ./findKthLargest
 *  Execute: ./findKthLargest
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

int findKthLargest(std::vector<int>& nums, int k) {
    //std::sort(nums.begin(),nums.end());
    //return(nums[nums.size()-k]);    
    //std::vector<int> kth_maxes(k);
    
    for(int i = 0; i < k; i++) {
        printf("%d\n", i);
        int l = i;
        for(int j = i+1; j < nums.size(); j++) {
            if(nums[l] < nums[j]) {
                l = j;
            }
        }
        if(l != i)
            std::swap(nums[i], nums[l]);
    }
    for(auto n: nums)
        printf("%d ", n);
    printf("\n");
    /*
    int l = 0;
    int r = nums.size() - 1;
    int kth = 0;
    
    while(true) {
        if(nums[i] 
        
    }
    */
    return(nums[k-1]);
}
 

int main(int argc, char **argv)
{
	std::vector<int> nums = {3,2,1,5,6,4};
    int k = 6;
    printf("findKthLargest=%d\n", findKthLargest(nums, k));
}