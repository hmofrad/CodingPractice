/*
 *  Problem: https://leetcode.com/problems/random-pick-index/
 *  Compile: g++ -o randomPickIndex randomPickIndex.cpp -std=c++11 -g -Wall -fsanitize=address && ./randomPickIndex
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<int, std::vector<int>> map;
    Solution(std::vector<int>& nums) {
        srand(time(NULL));
        //std::sort(nums.begin(), nums.end());
        for(uint32_t i = 0; i < nums.size(); i++) {
            int& n = nums[i];
        //    printf("%d-->%d\n", i, n);
            if(map.find(n) == map.end()) {
                map[n].push_back(i);
            }
            else {
                map[n].push_back(i);
            }
        }
        /*
        for(auto m: map) {
            printf("%d: ", m.first);
            for(auto v: m.second) {
                printf("%d ", v);
            }
            printf("\n");
        }
        */
        
    }
    
    int pick(int target) {
        return(map[target][rand_gen(map[target].size())]);
    }
    
    int rand_gen(uint32_t range) {
        return((rand() % range));
    }
    
};

int main(int argc, char **argv){
    std::vector<int> nums = {1,-3, 2,-3,4,-3};
    Solution* obj = new Solution(nums);
    int target = -3;
    int param_1 = obj->pick(target);
    printf("%d=nums[%d]\n", target, param_1);
    delete obj;
    printf("%d\n", 10%1);
    return(0);
}






