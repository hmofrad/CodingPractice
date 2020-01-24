/*
 *  Problem: https://leetcode.com/problems/find-all-duplicates-in-an-array/
 *  Compile: g++ -o findDuplicates findDuplicates.cpp -std=c++11 -g -Wall -fsanitize=address && ./findDuplicates
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

/*
   \sum{1, 2, 3, 4, 5, 6, 7, 8} = 36
   == (8 x 9) /2 = 36
   \sum{1..n} = (nx(n+1))/2
*/

std::vector<int> findDuplicates(std::vector<int>& nums) {
    /*
    std::vector<int> dups;
    
    int series_sum = (nums.size() * (nums.size()+1)) / 2;
    
    int current_sum = std::accumulate(nums.begin(), nums.end(), 0);
    
    for(int i = 1; i <= nums.size(); i++) {
        
    }
    
    printf("%d %d\n", series_sum, current_sum);
    
    return(dups);    
    
    
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != i+1) {
            std::swap(nums[i], 
            
        }
    }
    return(dups);
    */
    
    for(auto n: nums) {printf("%+d ", n);} printf("\n");
    std::vector<int> ans ;
        int j ;
        for(uint32_t i = 0 ; i < nums.size() ; i++ ){
            j = abs(nums[i]) ;
            printf("numsi[%d]=%+d, numsj[%d]=%+d | ", i, nums[i], j-1, nums[j-1]);
            
            if(nums[j-1] > 0)
                nums[j-1] = -nums[j-1];
            else
                ans.push_back(j) ;
            for(auto n: nums) {printf("%+d ", n);} printf("|");
            for(auto a: ans) {printf("%+d ", a);} printf("\n");
        }
        
        for(auto n: nums) {printf("%+d ", n);} printf(" | ");
        for(auto a: ans) {printf("%+d ", a);} printf("\n");
        
        return ans ;
    
   
}

int main(int argc, char **argv){
    std::vector<int> nums = {4,3,2,7,8,2,3,1};    
    std::vector<int> dups = findDuplicates(nums);
    for(auto d: dups) {printf("%d\n", d);}
    return(0);
}






