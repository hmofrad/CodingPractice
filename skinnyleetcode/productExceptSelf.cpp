    /*
 *  Problem: https://leetcode.com/problems/product-of-array-except-self/
 *  Compile: g++ -o productExceptSelf productExceptSelf.cpp -std=c++11 && ./productExceptSelf
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
#include <stack>
#include <numeric>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

/*
std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> nums1(n, 1);
    for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++) {
           if(i != j) {
                nums1[i] *= nums[j];
           }
       }
    }
    return(nums1);    
}
*/

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> nums1(n, 1);
    int left = 1;
    int right = 1;
    int j = 0;
    for(int i = 1; i < n; i++) {
        j = n - i;
        left *= nums[i-1];
        right *= nums[j];
        nums1[i] *= left;
        nums1[j-1] *= right;
    }
    return(nums1);    
}

int main(int argc, char **argv){
    std::vector<int> nums = {1,2,3,4};
    for(auto& n: nums)
        printf("%d ", n);
    printf("\n");
    
    std::vector<int> nums1 = productExceptSelf(nums);
    
    for(auto& n: nums1)
        printf("%d ", n);
    printf("\n");
    
    
    return(0);
}






