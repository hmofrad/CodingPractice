    /*
 *  Problem: https://leetcode.com/problems/single-number-iii/
 *  Compile: g++ -o singleNumber3 singleNumber3.cpp -std=c++11 && ./singleNumber3
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


/*
std::vector<int> singleNumber(std::vector<int>& nums) {
    std::vector<int> nums1;
    int max = *std::max_element(nums.begin(), nums.end());
    int min = *std::min_element(nums.begin(), nums.end());
    int s = max - min + 1;
    std::vector<int> tmp(s);
    for(auto& n: nums) {
        tmp[n - min]++; 
    }
    
    for(int i = 0; i < s; i++) {
        if(tmp[i] == 1) {
            nums1.push_back(i + min);
        }
    }
    return(nums1);    
}
*/

std::vector<int> singleNumber(std::vector<int>& nums) {
    std::vector<int> nums1;
    std::map<int, int> tmp;
    
    //std::map<int,int>::iterator it;
    for(auto& n: nums) {
        //it = tmp.find(n);
        //if (it != tmp.end())
        //if(
        tmp[n]++;
    }
    for(auto& t: tmp) {
    //tmp.find('a')->second
        printf("%d %d\n", t.first, t.second);
        if(t.second == 1) {
            nums1.push_back(t.first);
        }
    }
    
    /*
    int max = *std::max_element(nums.begin(), nums.end());
    int min = *std::min_element(nums.begin(), nums.end());
    int s = max - min + 1;
    std::vector<int> tmp(s);
    for(auto& n: nums) {
        tmp[n - min]++; 
    }
    
    for(int i = 0; i < s; i++) {
        if(tmp[i] == 1) {
            nums1.push_back(i + min);
        }
    }
    */
    return(nums1);    
}





int main(int argc, char **argv){
    std::vector<int> nums = {-1, 1,2,1,3,2,5};
    
    for(auto& n: nums) {
        printf("%d ", n);
    }
    printf("\n");
    
    std::vector<int> nums1 = singleNumber(nums);
    
    for(auto& n: nums1) {
        printf("%d ", n);
    }
    printf("\n");
    
    return(0);
}






