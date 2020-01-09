/*
 *  Cracking the coding interview: Problem 17.12: Pairs with equal sum in an array
 *  Compile & run: g++ -o sumofPairs sumofPairs.cpp -g -Wall -std=c++11 -fsanitize=address && ./sumofPairs
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, int>> findPairs(std::vector<int> nums, int value) {
    std::vector<std::pair<int, int>> pairs;
    for(uint32_t i = 0; i < nums.size()-1; i++) {
        for(uint32_t j = i+1; j < nums.size(); j++) {    
            if((nums[i] + nums[j]) == value) {
                pairs.push_back(std::make_pair(nums[i], nums[j]));
            }
        }
    }
    return(pairs);
}

std::vector<std::pair<int, int>> findPairs1(std::vector<int>& nums, int value) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::pair<int, int>> pairs;
    for(uint32_t i = 0; i < nums.size()-1; i++) {
        for(uint32_t j = i+1; j < nums.size(); j++) {    
            if((nums[i] + nums[j]) == value) {
                pairs.push_back(std::make_pair(nums[i], nums[j]));
            }
            else if((nums[i] + nums[j]) >  value) {
                break;
            }
        }
    }
    return(pairs);
}

std::vector<std::pair<int, int>> findPairs2(std::vector<int>& nums, int value) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::pair<int, int>> pairs;
    int first = 0;
    int last = nums.size() - 1;
    while(first < last) {
        int s = nums[first] + nums[last];
        if(s == value) {
            pairs.push_back(std::make_pair(nums[first], nums[last]));
            first++;
            last--;
        }
        else {
            if(s < value) {
                first++;
            }
            else {
                last--;
            }
        }
    }
    
    return(pairs);
}

int main(int argc, char** argv) {
    std::vector<int> nums = {-2, -1, 0, 3, 5, 6, 7, 9, 13, 14}; //{(0, 6) and (-1, 7) = 6}
    int value = 6;
    //std::vector<std::pair<int, int>> pairs = findPairs(nums, value);
    //std::vector<std::pair<int, int>> pairs = findPairs1(nums, value);
    std::vector<std::pair<int, int>> pairs = findPairs2(nums, value);
    for(auto p: pairs) {
        printf("%d %d\n", p.first, p.second);
    }
    
    return(0);
}