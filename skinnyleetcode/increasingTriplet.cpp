    /*
 *  Problem: https://leetcode.com/problems/increasing-triplet-subsequence/
 *  Compile: g++ -o increasingTriplet increasingTriplet.cpp -std=c++11 && ./increasingTriplet #-fsanitize=address 
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

/*
bool increasingTriplet(std::vector<int>& nums) {
    bool triplet = false;
    for(int i = 0 ; i < nums.size(); i++) {
        int m = i + 3;
        if(m <= nums.size()) {
            printf("%d %d %d\n", i, nums[i], m);
            bool found = true;
            for(int j = i; j < m-1; j++) {
                if(nums[j] >= nums[j+1]) {
                    found = false;
                    break;
                }                    
            }
            if(found) {
                triplet = true;
                break;
            }
        }
    }
    return(triplet);    
}
*/
/*
bool increasingTriplet(std::vector<int>& nums) {
    if(nums.size() < 3) return(false);
    int n = nums.size();
    std::vector<bool> dp(n, false);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                if(dp[j]) return(true);
                else dp[i] = true;
            }
        }
        
        for(int i = 0; i < n; i++) {
            printf("%d ", dp[i] == true);
        }
        printf("\n");
    }
    return(false);
}
*/

bool increasingTriplet(std::vector<int>& nums) {
    if(nums.size() < 3) return(false);
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    for(int n: nums) {
        if(n < min1) min1 = n;
        if(n > min1) min2 = (n > min2) ? min2: n;//std::min_element(n, min2);
        if(n > min2) return(true);
    }
    return(false);
}


int main(int argc, char **argv){
    std::vector<int> nums = {5,1,5,5,2,5,4};//{1,1,1,1,1,1};// {1,2,3,4,5}; //{5,4,3,2,1};//
    bool found = increasingTriplet(nums);
    for(auto& n : nums)
        printf("%d ", n);
    printf("? %d\n", found);
    
    return(0);
}






