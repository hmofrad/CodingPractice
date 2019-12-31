/*
 *  Cracking the coding interview: Problem 5.7: Find a missing number in an array using bit manipulation
 *  Compile & run: g++ -o missingNumber missingNumber.cpp -g -Wall -std=c++11 -fsanitize=address && ./missingNumber
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

bool fetch(std::vector<int> nums, int index, int bit) {
    int n = nums[index];
    int mask = 1 << bit;
    return((n & mask) != 0);
}

int missingNumber(std::vector<int> nums, uint32_t sz) {
    uint32_t missing =  sz;
    for(uint32_t i = 0; i < sz; i++) {
        missing ^= (i ^ nums[i]);
    }
    //printf("%d %d\n", nums[0], fetch(nums, 0, 0));
    return(missing);
}

int main(int argc, char** argv) {
    std::vector<int> nums = {0, 1, 2, 4, 5};
    int missedOne = missingNumber(nums, nums.size());
    printf("%d\n", missedOne);
    return(0);
}