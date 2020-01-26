/*
 *  Problem: https://leetcode.com/discuss/interview-question/365872/
 *  Compile: g++ -o equalSumDigits equalSumDigits.cpp -std=c++11 -g -Wall -fsanitize=address && ./equalSumDigits
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

int sumDigits(int num) {
    int s = 0;
    do{
        s += (num%10);
        num = num/10;
    } while(num%10);
    return(s);
}

int equalSumDigits(std::vector<int> nums) {
    int maxSum = -1;
    std::unordered_map<int, std::vector<int>> map;
    for(auto n: nums) {
        int s = sumDigits(n);
        map[s].push_back(n);
    }
    
    for(auto m: map) {
        printf("%d: ", m.first);
        for(auto v: m.second) {
            printf("%d ", v);
        }
        printf("\n");
    }
    
    for(auto m: map) {
        auto values = m.second;
        for(uint32_t i = 0; i < values.size()-1; i++) {
            for(uint32_t j = i+1; j < values.size(); j++) {    
                int sum = values[i] + values[j];
                if(sum > maxSum) {
                    maxSum = sum;
                }
            }
        }
    }
  
    return(maxSum);
}


int main(int argc, char **argv){
    //std::vector<int> nums = {51, 71, 17, 42, 60};
    //std::vector<int> nums = {42, 33, 60};
    std::vector<int> nums = {51, 32, 43};
    int sum = equalSumDigits(nums);
    printf("Sum=%d\n", sum);
    
    return(0);
}
