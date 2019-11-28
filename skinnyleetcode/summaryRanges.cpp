    /*
 *  Problem: https://leetcode.com/problems/implement-stack-using-queues/
 *  Compile & execute: g++ -o summaryRanges summaryRanges.cpp -std=c++11 -fsanitize=address && ./summaryRanges
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
#include <queue>
std::vector<std::string> summaryRanges(std::vector<int>& nums) {
    std::vector<std::string> ranges;
    int n = nums.size();
    int i = 0;
    while(i < n) { 
        printf("%d: ", nums[i]);
        int j = i;
        while(j+1 < n) {
            printf("%d ", nums[j]);
            if((nums[j] + 1) == nums[j+1])
                j++;
            else 
                break;
        }
        if(i == j) {
            ranges.push_back(std::to_string(nums[i]));
            i++;
        }
        else {
            std::string s = std::to_string(nums[i]) + "->" + std::to_string(nums[j]);
            ranges.push_back(s);
            i = j + 1;
            //printf("%d\n", i);
        }
        printf("\n");
    }
    return(ranges);        
}

int main(int argc, char **argv) {
    std::vector<int> nums ={0,1,2,4,5,7};// {0,2,3,4,6,8,9, 3};// 
        
    for(auto& n: nums) 
        printf("%d ", n);
    printf("\n");
    std::vector<std::string> str = summaryRanges(nums);
    for(auto& s: str) 
        printf("%s ", s.c_str());
    printf("\n");
    return(0);
}






