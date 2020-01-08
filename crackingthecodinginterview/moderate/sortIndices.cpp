/*
 *  Cracking the coding interview: Problem 17.6: Find smallest indices m and n in an array s.t. if you sort the range represented by them array become sorted.
 *  Compile & run: g++ -o sortIndices sortIndices.cpp -g -Wall -std=c++11 -fsanitize=address && ./sortIndices
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <tuple>

std::pair<int, int> getIndices(std::vector<int> nums) {
    int m = -1;
    int n = -1;
   // std::vector<int> nums1 = nums;
    for(uint32_t i = 0; i < nums.size()-1; i++) {
        for(uint32_t j = i+1; j < nums.size(); j++) {    
            //if(nums1[i] > nums1[j]) {
            //    std::swap(nums1[i], nums1[j]);
            //}
            if(nums[i] > nums[j]){
                m = i; 
                break;
            }
        }
        if(m>=0) break;
    }
    
    for(int32_t i = nums.size()-1; i > 0 ; i--) {
        for(int32_t j = i-1; j >= 0; j--) {    
            //if(nums1[i] > nums1[j]) {
            //    std::swap(nums1[i], nums1[j]);
            //}
            if(nums[i] < nums[j]){
                n = i; 
                break;
            }
        }
        if(n>=0) break;
    }
    
    
    /*
    int i = 0;
    int j = nums.size()-1;
    while(i < j) {
        printf("nums[%d]=%d, nums[%d]=%d\n", i, nums[i], j, nums[j]);
        if((nums[i] <= nums[i+1]) and (nums[j] >= nums[j-1])){
            i++;
            j--;
        }
        else{
            break;
        }
    }
    printf("nums[%d]=%d, nums[%d]=%d\n", i, nums[i], j, nums[j]);
    */
    
    return(std::make_pair(m,n));
}

int main(int argc, char** argv) {
    std::vector<int> nums = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    
    int m = 0;
    int n = 0;
    std::tie(m, n) = getIndices(nums);

    printf("m=%d--n=%d\n", m, n);
    return(0);
}