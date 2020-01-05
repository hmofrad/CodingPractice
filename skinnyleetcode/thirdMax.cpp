/*
 *  Problem: https://leetcode.com/problems/third-maximum-number/
 *  Compile: g++ -o thirdMax thirdMax.cpp -std=c++11  -g -Wall -fsanitize=address && ./thirdMax
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

int thirdMax(std::vector<int>& nums) {
    int third_maximum = 0;
    if(not nums.empty()) {
        std::sort(nums.begin(), nums.end());
        third_maximum = nums.back();
        int i = 1;
        //printf("%d %d %d\n", i, nums.back(), third_maximum);
        for(auto rit = nums.rbegin()+1; rit != nums.rend(); rit++) {
                        
            if(*rit < third_maximum) {
                if(i < 3) {
                    third_maximum = *rit;
                    i++;
                    //if(i == 3) {
                      //  break;
                    //}
                }
                else {
                    break;
                }
            }
printf("%d %d %d\n", i, *rit, third_maximum);
        }
        printf("%d %d \n", i, third_maximum);
        if(i != 3) {
            third_maximum = nums.back();
        }
    }
    return(third_maximum);
}

int main(int argc, char **argv){
    std::vector<int> nums = {1, 2, 2, 5, 3, 5};
    int third = thirdMax(nums);
    
    printf("%d\n", third);
    return(0);
}






