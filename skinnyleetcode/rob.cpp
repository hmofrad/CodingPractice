/*
 *  URL: https://leetcode.com/problems/house-robber/
 *  Compile & Execute: g++ -o rob rob.cpp -std=c++11 && ./rob
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
    /*
    static int dig(std::vector<int>& nums, int d) {
        if(nums.size()) {
            printf("%lu %d\n", nums.size(), d);
            d++;
            dig((nums.begin() + 2), d);
        }
        else 
            return(d);
    }
    */
    /*
    static int min_idx(std::vector<int> nums) {
        int n = nums.size();
        int min_value = nums[0];
        int min_index = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] < min_value) {
                min_value = nums[i];
                min_index = i;
            }
        }
        return(min_index);
    }
    */
    
    static int max(int n1, int n2) {
        if(n1 > n2) return(n1);
        else
            return(n2);
    }
    
    static int rob(std::vector<int>& nums) {
        /*
        if(nums.empty()) {
            return(0);
        }
        
        int len = nums.size();
        
        int get_money[len + 1] = {0};
        get_money[1] = nums[0];
        for(int i = 2; i < len; i++) {
            int n1 = get_money[i-1];
            int n2 = (get_money[i-2] + nums[i-1]);
            get_money[i] = max(n1, n2);
        }
        return get_money[len];
        */
        
        int v = 0;
        int sz = nums.size();
        if(sz == 0) {
            return(0);
        }
        if (sz == 1) {
            return(nums[0]);
        }
        if (sz == 2) {
            return(*std::max_element(nums.begin(), nums.end()));
        }
        else {
            int v1 = nums[0];
            std::vector<int> new_nums1(nums.begin()+2, nums.end());
            int v2 = rob(new_nums1);
            int v3 = v1 + v2;
            
            std::vector<int> new_nums(nums.begin()+1, nums.end());
            int v4 = rob(new_nums);
            //printf("v1=%d v2=%d v3=%d\n", v1, v2, v3);
            if(v3 > v4) {
                v += v3;
                
                
                //return(v);
            }
            else {
                v += v4;
            }
            return(v);
        }
        
        //int d = 0;
        //dig(nums, d);
        //return(d);
    }
};
int main(int argc, char **argv) {
    //std::vector<int> v = {2,7,9,3,1};
    std::vector<int> v = {183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
    //std::vector<int> v = {2, 7, 9};
    printf("%d\n", Solution::rob(v));
    return(0);
}    

