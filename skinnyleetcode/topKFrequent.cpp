/*
 *  Problem: https://leetcode.com/problems/top-k-frequent-elements/
 *  Compile: g++ -o topKFrequent topKFrequent.cpp -std=c++11 && ./topKFrequent #-fsanitize=address 
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
#include<bits/stdc++.h> 

/*
std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::vector<int> topk(k);
    
    std::unordered_map<int, int> map;
    
    for(auto& n: nums) {
        if(map.find(n) == map.end()) {
            map[n] = 1;
        }
        else {
            map[n]++;
        }
    }
    
    for(auto& k: topk) {
        int key = 0;
        int val = 0;
        for(auto& it: map) {
            printf("%d %d\n", it.first, it.second);
            if(it.second > val) {
                key = it.first;
                val = it.second;
            }
        }
        map.erase(key);
        k = key;
        printf("\n");
    }
    
    
    return(topk);
}
*/

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::vector<int> topk(k);
    
    std::sort(nums.begin(), nums.end());
    
    std::vector<int> keys;
    std::vector<int> vals;
    
    keys.push_back(nums[0]);
    vals.push_back(1);
    
    
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i-1]) {
            vals.back()++;
        }
        else {
            keys.push_back(nums[i]);
            vals.push_back(1);
        }
    }
    
    //for(int i = 0; i < keys.size(); i++) {
    //    printf("%d %d %d\n", i, keys[i], vals[i]);
        
    //}
    
    for(auto &k: topk) {
        int idx = 0;
        int val = 0;
        for(int i = 0; i < vals.size(); i++) {
            if(vals[i] > val) {
                val = vals[i];
                idx = i;
            }
        }
        k = keys[idx];
        vals[idx] = 0;
    }

    return(topk);
}
        
    

int main(int argc, char **argv){
    std::vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    std::vector<int> topk = topKFrequent(nums, k);
    for(auto& k: topk) printf("%d ", k); printf("\n");
    
    return(0);
}






