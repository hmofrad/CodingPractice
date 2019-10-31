    /*
 *  Problem: https://leetcode.com/problems/missing-number/
 *  Compile: g++ -o missingNumber missingNumber.cpp -std=c++11 && ./missingNumber
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

int missingNumber(std::vector<int>& nums) {
    //int missed = 0;
    int min = 2147483647;
    int max = 0;
    int sum = 0;
    int n = nums.size();
    
    for(int i = 0; i < n; i++) {
        if(nums[i] < min) {
            min = nums[i];
        }
        if(nums[i] > max) {
            max = nums[i];
        }
        sum += nums[i];
    }
    /*
    if(min != 0)
        return(0);
    else if(max != n) {
        return(n);
    }
    else {
        */
        int accu = (n * (n + 1)) / 2;
        return(accu - sum);
    //}
    


    /*
    //int min = (std::find(nums.begin(), nums.end(), 0) == nums.end()) ? -1 : 0;
    std::pair<int, int> bounds = *std::minmax(nums.begin(), nums.end());
    if(min == -1) 
        return(missed);
    int max = nums.size();
    printf("%d %d\n", min, max);
    if(max == nums.size()) {
        //int sum = (max * (max + 1)) / 2;
    }
    else {
        return(max);
    }
    */
    //int n = nums.size();
    printf("%d %d %d\n", min, max, sum);
    //for(int i = 0; i < n; i++) {
    //    if(nums[i] < 
    //}
    //std::pair<int, int> bounds = *std::minmax(nums.begin(), nums.end());
    /*
    int s = (max * (max + 1)) / 2;
    printf("%d\n", max);
    printf("%d\n", s);
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    printf("%d\n", s - sum);
    */
    return(-1);    
}

    
int main(int argc, char **argv){
    std::vector<int> nums = {8,6,4,2,3,5,7,1,0};

    for(auto& i: nums) {
        printf("%d ", i); 
    }
    printf("\n");

    
    int missed = missingNumber(nums);
    printf("missingNumber ? %d\n", missed);
    
    return(0);
}






