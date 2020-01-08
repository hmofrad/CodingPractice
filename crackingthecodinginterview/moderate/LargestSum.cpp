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
                
                
            //int ss = std::accumulate(nums.begin(), nums.begin()+i, 0);
            //if(ss > sum) {
              //     sum = ss;
                //   idx = j;
            //} 
            }         
            printf("i=%d j=%d s=%d\n", i, j, s);            
            if(s > sum) {
                sum = s;
            }
        }
        
    }
    printf("%d\n", sum);
    return(sum);
}

int largestSum1(std::vector<int> nums) {
    int maxsum = 0;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if(maxsum < sum) {
            maxsum = sum;
        }
        else if(sum < 0){
            sum = 0;
        }
    }
    return(sum);
}


int main(int argc, char** argv) {
    //std::vector<int> nums = {5, -9, 6, -2, 3};
    std::vector<int> nums = {2, 3, -8, -1, 2, 4, -2, 3};
    
    
    int sum = largestSum(nums);
    //for(auto n: nums1) {
      //  printf("%d ", n);
    //}
    printf("%d\n", sum);
    return(0);
}