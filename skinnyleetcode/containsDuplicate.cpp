    /*
 *  Problem: https://leetcode.com/problems/contains-duplicate/
 *  Compile: g++ -o containsDuplicate containsDuplicate.cpp -std=c++11 && ./containsDuplicate
 *  Execute: ./containsDuplicate
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

/*
bool containsDuplicate(std::vector<int>& nums) {
    bool ret = false;
    int n = nums.size();
    if(n > 1) {
        for(int i = 0; i < n - 1; i++) {
            int i_v = nums[i];
            for(int j = n - 1; j >= i + 1; j--) {
            //for(int j = i + 1; j < n; j++) {
                int j_v = nums[j];
                if(i_v == j_v) {
                    ret = true;
                    break;
                }
            }
            if(ret) break;
        }
    }
    return(ret);
}
*/
/*
bool containsDuplicate(std::vector<int>& nums) {
    bool ret = false;
    int n = nums.size();
    if(n > 1) {
        auto result = std::minmax_element (nums.begin(),nums.end());
        int mi = *result.first;
        int ma = *result.second;
        std::vector<bool> my_map(ma + mi + 1);
        for(auto v: nums) {
            int v2 = (v >= 0) ? v : 1 + ma - v;
            if(my_map[v2]) {
                ret = true;
                break;
            }
            else {
                my_map[v2] = true;
            }
        }
    }
    return(ret);
}
*/
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    bool ret = false;
    int n = nums.size();
    if(n > 1) {
        std::unordered_set<int> hash;
        for(auto v: nums) {
            if (hash.find(v) == hash.end()) {
                hash.insert(v);
            }
            else {
                ret = true;
                break;                
            }
        }
    }
    return(ret);
}


int main(int argc, char **argv){
    //std::vector<int> nums = {-1200000005,-1200000005};
    std::vector<int> nums = {1,5,-2,-4,0, 1};
    
    printf("containsDuplicate? %d\n", containsDuplicate(nums));
    
    return(0);
}