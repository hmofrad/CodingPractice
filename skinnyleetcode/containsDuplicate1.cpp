    /*
 *  Problem: https://leetcode.com/problems/contains-duplicate-ii/
 *  Compile: g++ -o containsDuplicate1 containsDuplicate1.cpp -std=c++11 && ./containsDuplicate1
 *  Execute: ./containsDuplicate1
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




/*
bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    bool ret = false;
    int n = nums.size();
    for(int i = 0; i < n - 1; i++) {
        //printf("[%d %d]\n", i, nums[i]);
        for(int j = i + 1; (j < n and j < i + 1 + k); j++) {
            //printf(" [%d %d] ? %d\n", j, nums[j], nums[i] == nums[j]);
            if(nums[i] == nums[j]) {
                ret = true;
                break;
            }
            if(ret) break;
        }
    }
    return(ret);
}
*/

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    bool ret = false;
    int n = nums.size();
    int i = 0;
    int j = (n > 1) ? 1 : 0;
    while((i < n - 1) and (j < n)) {
        printf("[%d %d] [%d %d] ? %d\n", i, nums[i], j, nums[j], nums[i] == nums[j]);
        if(j < i + 1 + k) {
            if(nums[i] == nums[j]) {
                ret = true;
                break;
            }
            j++;
        }
        else {
            i++;
            j = i + 1;
        }
        if(j == n) {
            i++;
            j = i + 1;
        }
        //printf("(%d %d)\n", i, j);
    }
    
    return(ret);
}




int main(int argc, char **argv){
    std::vector<int> nums = {1,2,3,4,5,6,7,8,9,9};
    int k = 3;
    printf("containsNearbyDuplicate? %d\n", containsNearbyDuplicate(nums, k));
    
    return(0);
}