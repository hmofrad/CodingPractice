    /*
 *  Problem: https://leetcode.com/problems/move-zeroes/
 *  Compile: g++ -o moveZeroes moveZeroes.cpp -std=c++11 -fsanitize=address && ./moveZeroes
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
#include <map>
#include <cmath>
#include <unordered_map>

void print(std::vector<int> nums) {
    for(auto n: nums)
        printf("%d ", n);
    printf("\n");
}
/*
int moveZeroes(std::vector<int>& nums) {
    int n = nums.size();
    //int j = n;
    int t = 0;
    int i = 0;
    while(i < n) {
    //for(int i = 0; i < n; i++) {
        if(not nums[i]) {
            for(int k = i; k < n-1; k++) {
                //printf("<%d %d %d>\n", i, k, n);
                std::swap(nums[k], nums[k+1]);
            }
            n--;
        }
        if(nums[i]) 
            i++;
        //print(nums);
        //printf("%d %d\n", i, n);
    }

}
*/
void moveZeroes(std::vector<int>& nums) {
    int n = nums.size();
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }   
    }
    print(nums);
    while(j < n) {
        nums[j] = 0;
        j++;
    }
}
    
int main(int argc, char **argv){
    //std::vector<int> nums = {0, 0, 1};//{0,1,0,3,12};
    std::vector<int> nums = {0,1,0,3,12};
    print(nums);
    
    
    moveZeroes(nums);
    print(nums);
    
    return(0);
}






