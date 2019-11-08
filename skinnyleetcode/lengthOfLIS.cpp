    /*
 *  Problem: https://leetcode.com/problems/longest-increasing-subsequence/
 *  Compile: g++ -o lengthOfLIS lengthOfLIS.cpp -std=c++11 -fsanitize=address && ./lengthOfLIS
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

/*
int lengthOfLIS(std::vector<int>& nums) {
    int longest = 0;
    int n = nums.size();
    if(n == 1) return(1);
    for(int i = 0; i < n-1; i++) {
        std::vector<int> s;
        int len = 1;
        int i1 = nums[i];
        s.push_back(i1);
        for(int j = i + 1; j < n; j++) {    
            int i2 = nums[j];
            if(i2 > i1) {
                s.push_back(i2);
                i1 = i2;
                len++;
            }
        }
        for(auto s: s) {printf("%d ", s);} printf("\n");
        //printf("%d\n", len);
        if(longest < len) longest = len;
    }
    
    return(longest);
}
*/

int lengthOfLIS(std::vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    
    std::vector<int> dp(n,1);
    int res = 1;
    
    for(int i = 1; i < n; i++) {
        printf("%d: ", i);
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
                res = std::max(res, dp[i]);
            }
            printf("%d ", j);
        }
        printf("\n");
        for(auto s: dp) {printf("%d ", s);} printf("\n");
    }
    
    
    
    return(res);
}


int main(int argc, char **argv){
std::vector<int> seq = {10,9,2,5,3,4};// {2,2}; //{10,9,2,5,3,7,101,18};
    for(auto s: seq) {printf("%d ", s);} printf("\n");
    int longest = lengthOfLIS(seq);
    printf("lengthOfLIS() ? %d\n", longest);
    return(0);
}






