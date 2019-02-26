/*
 *  Compile & Execute: g++ -o singleNumber singleNumber.cpp -std=c++11 && ./singleNumber
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

int singleNumber(std::vector<int>& nums) {
    int num = 0;
    int size = nums.size()/2 + nums.size()%2;
    std::vector<int> values(size);
    std::vector<int> counts(size);
    
    /*
    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < size; j++) {
            if(values[j] == nums[i])
        }            
        if(not(std::find(values.begin(), values.end, values) != 
    }
    */
    for(int i = 0; i < nums.size(); i++) {
        bool found = false;
        for(int j = 0; j < nums.size(); j++) {
            printf("%d %d %d %d\n", i, j, nums[i], nums[j]);
            if((i != j) and (nums[i] == nums[j])) {
                found = true;
                break;
            }    
        }
        if(not found) {
            num = nums[i];
            break;
        }
    }
    return(num);
}


int main(int argc, char** argv) {
    std::vector<int> nums = {1, 2, 1, 2, 4};
    printf("%d\n", singleNumber(nums));
    return(0);
}