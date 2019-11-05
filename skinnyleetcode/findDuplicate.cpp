    /*
 *  Problem: https://leetcode.com/problems/find-the-duplicate-number/
 *  Compile: g++ -o findDuplicate findDuplicate.cpp -std=c++11 -fsanitize=address && ./findDuplicate
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
int findDuplicate(std::vector<int>& nums) {
    int n = nums.size();
    int sum_sq = ((n - 1) * n)/2;
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    return((sum - sum_sq));
}
*/
/*
int findDuplicate(std::vector<int>& nums) {
    bool tf = false;
    int dup = 0;
    int n = nums.size();
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(nums[i] == nums[j]) {
                tf = true;
                dup = nums[i];
                break;
            }
        }
        if(tf) break;
    }
    return(dup);
}
*/

int findDuplicate(std::vector<int>& nums) {
    int dup = 0;
    std::sort(nums.begin(), nums.end());
    print(nums);

    int begin = 0;
    int end = nums.size()-1;
    
    while(begin <= end) {
        int mid = (begin + end) / 2;
        if(nums[mid] == mid + 1) {
            if(nums[mid] == nums[mid+1]) {
                return(nums[mid]);
            }
            else {
                begin = mid + 1;
            }
        }
        else if(nums[mid] < mid + 1) {
            end = mid - 1;
        }
        else if(nums[mid] > mid + 1) {
            begin = mid + 1;
        }
        
    }
    
    return(nums[begin]);
}
    
int main(int argc, char **argv){
    //std::vector<int> nums = {3,1,3,4,2};
    
    //std::vector<int> nums = {1,3,4,2,2};
    std::vector<int> nums = {2,2,2,2,2};
    print(nums);
    
    int n = findDuplicate(nums);
    printf("findDuplicate ? %d\n", n);
    
    return(0);
}






