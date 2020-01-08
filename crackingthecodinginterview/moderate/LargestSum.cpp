/*
 *  Cracking the coding interview: Problem 17.8: Continues sequence with the largest sum
 *  Compile & run: g++ -o LargestSum LargestSum.cpp -g -Wall -std=c++11 -fsanitize=address && ./LargestSum
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include<bits/stdc++.h> 



int largestSum(std::vector<int> nums) {
    std::vector<int> nums1;
    int sum = INT_MIN;
    int idx = 0;
    
    for(int i = 1; i < (int)nums.size(); i++) {
        for(int j = 0; j < (int)(nums.size()-i); j++) {
            int s = 0;
            for(int k = j; k < i+j+1; k++) {
                s += nums[k];
                printf("i=%d j=%d k=%d\n", i, j, k);
                
            //int ss = std::accumulate(nums.begin(), nums.begin()+i, 0);
            //if(ss > sum) {
              //     sum = ss;
                //   idx = j;
            //} 
            }            
            if(s > sum) {
                sum = s;
            }
        }
        
    }
    printf("%d\n", sum);
    return(sum);
}



int main(int argc, char** argv) {
    std::vector<int> nums = {2, -8, 3, -2, 4, -10};
    
    
    int sum = largestSum(nums);
    //for(auto n: nums1) {
      //  printf("%d ", n);
    //}
    printf("%d\n", sum);
    return(0);
}