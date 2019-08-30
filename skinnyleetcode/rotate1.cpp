/*
 *  URL: https://leetcode.com/problems/rotate-array/
 *  Compile & Execute: g++ -o rotate1 rotate1.cpp -std=c++11 && ./rotate1
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

class Solution {
public:
    static void rotate(std::vector<int>& nums, int k) {
        int s = nums.size();
        int l = k;
        if(k > s)
            l = k % s;
        std::vector<int> nums1 = nums;
        if(l) {
        for(int i = 0; i < s; i++) {
            int j = (i+l)%s;
            nums[j] = nums1[i];
            //int t = nums[j];
            //nums[i] = nums[j];
            //nums[j] = t;
            printf("i=%d,%d --> j=%d,%d\n", i, nums[i], j, nums[j]);
            //printf("%d ", nums[j]);
            //break;
        }
        //printf("\n");
        }
        
        //for(int i = 0; i < l; i++) {
            
        //}
        //if(s > 1 and k > 0) {
            
            //printf("%d %d %d\n", k, s, j);
            //for(int i = 0; i < k; i++) {
                
            //}
        //}
        ;
    }
};
int main(int argc, char **argv) {
    std::vector<int> v = {1,2,3,4,5,6,7};
    //int k = 3;
    int k = 3;
    
    for(int i: v)
        printf("%d ", i);
    printf("\n");
    
    Solution::rotate(v, k);
    for(int i: v)
        printf("%d ", i);
    printf("\n");
    return(0);
}    



