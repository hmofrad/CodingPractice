    /*
 *  Problem: https://leetcode.com/problems/range-sum-query-immutable/
 *  Compile: g++ -o sumRange sumRange.cpp -std=c++11 -fsanitize=address && ./sumRange
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

/*
class NumArray {
public:
    std::vector<int> nums;
    int size;
    NumArray(std::vector<int>& nums_) {
        nums = nums_;
        size = nums.size();
    }
    
    int sumRange(int i, int j) {
        if((i < 0) or ( j > size - 1))
            return(0);
        
        return(std::accumulate(nums.begin()+i, nums.end()-(size - 1 - j), 0));
    }
};
*/


class NumArray {
public:
    std::vector<int> prefix_sum;
    NumArray(std::vector<int>& nums) {
        prefix_sum = nums;
        for(int i = 1; i < prefix_sum.size(); i++) {
            prefix_sum[i] += prefix_sum[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        /*
        for(auto s: prefix_sum)
            printf("%d ", s);
        printf("\n");
        */
        int sum = 0;
        if((i < 0) or ( j > prefix_sum.size() - 1))
            return(0);
        sum = prefix_sum[j] - prefix_sum[i];
        if(i == 0)
            sum += prefix_sum[i];
        else 
            sum += prefix_sum[i] - prefix_sum[i-1];
        
        return(sum);
    }
};




int main(int argc, char **argv){
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    
    NumArray* obj = new NumArray(nums);
    int i = 0;
    int j = 2;
    int param_1 = obj->sumRange(i,j);
    printf("%d\n", param_1);
    delete obj;
    
    return(0);
}






