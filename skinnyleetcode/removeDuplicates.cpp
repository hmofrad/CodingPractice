/*
 *  Problem: removeDuplicates
 *  Compile: g++ -o removeDuplicates removeDuplicates.cpp -std=c++11 && ./removeDuplicates
 *  Execute: ./removeDuplicates
 *  (c) Mohammad Mofrad, 2018
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

int removeDuplicates(std::vector<int>& nums) {
    int n = nums.size();
    int length = n;
    for(int i = 0; i < n; i++) 
        printf("%d ", nums[i]);
    printf("\n");
    int i = 0;
    int i1 = 0;
    int i2 = 0;
    while((i + 1) < length) {
        if(nums[i] == nums[i + 1]) {
            i1 = i + 2;
            i2 = i + 2;
            while(i2 < length) {
                if(nums[i2] == nums[i + 1])
                    i2++;
                else
                    break;  
            }
            i = i1;
            for(int j = i2; j < length; j++) {
                nums[i1] = nums[j];
                i1++;
            }
            length -= (i2 - i);
        } 
        else
            i++;
   }
    return(length);
}

int main(int argc, char** argv) {
    //std::vector<int> nums = {1, 1, 1, 1, 2, 2, 3};
    std::vector<int> nums = {0,0,1,1,1,1,2,3,3};
    
    int length = removeDuplicates(nums);
    for(int i = 0; i < length; i++)
        printf("%d ", nums[i]);
    printf("\n");

}