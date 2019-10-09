/*
 *  Problem: https://leetcode.com/problems/minimum-size-subarray-sum/
 *  Compile: g++ -o minSubArrayLen minSubArrayLen.cpp -std=c++11 && ./minSubArrayLen
 *  Execute: ./minSubArrayLen
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

int minSubArrayLen(int s, std::vector<int>& nums) {
    //std::vector<std::vector<int>> sums(nums.size());
    bool has_not_found = true;
    int min_s = 0;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum = nums[i];
        if(sum >= s) {
            min_s = 1;
            break;
        }
        else if(i != nums.size() - 1) { 
            for(int j = i+1; j < nums.size(); j++) {
                sum += nums[j]; 
                if(sum >= s) {
                    //printf("%d %d [%d %d]\n", i, j, j - i + 1, min_s);
                    if(has_not_found) {
                        min_s = j - i + 1;
                        has_not_found = false;
                    }
                    else if((j - i + 1) < min_s) {
                            min_s = j - i + 1;    
                    }
                    
                    break;
                }
            }
        }
    }
    return(min_s);
}

int main(int argc, char **argv) {
	std::vector<int> nums = {5,1,3,5,10,7,4,9,2,8};//{2,3,1,2,4,3};
    int s = 15; // 7;
    printf("minSubArrayLen=%d\n", minSubArrayLen(s, nums));
}