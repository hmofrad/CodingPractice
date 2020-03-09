/*
 *  Problem: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
 *  Compile: g++ -o minMoves minMoves.cpp -std=c++11 -g -Wall -fsanitize=address && ./minMoves
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

bool verify(std::vector<int> nums) {
    bool u = true;
    for(uint32_t i = 1; i < nums.size(); i++) {
        if(nums[0] != nums[i]) {
            u = false;
            break;
        }
    }
    return(u);    
}

int minMoves1(std::vector<int>& nums) {
    
    bool u = verify(nums);
    if(u) return(0);
    
    int k = 0;
    while(true) {
        auto it = std::max_element(nums.begin(), nums.end());
        //int max_val = *it;
        uint32_t max_idx = std::distance(nums.begin(), it);    
        
        for(uint32_t i = 0; i < nums.size(); i++) {
            if(i != max_idx) {
                nums[i]++;
            }
        }
        k++;
        
        bool u = verify(nums);
        if(u) break;
    }
    
    //for(uint32_t i = 0; i < nums.size(); i++) {
     //   printf("%d ", nums[i]);
    //}
    //printf("\n");
    
    return(k);    
}

int minMoves0(std::vector<int>& nums) {

    return std::accumulate(nums.begin(), nums.end(), 0L) - (*min_element(nums.begin(), nums.end()) * nums.size());
}

int minMoves(std::vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0L);
    int min = *min_element(nums.begin(), nums.end());
    int ops = sum - (nums.size() * min);
    return(ops);
}
/*
1, 2, 3
1, 1, 2
1, 0, 1
0, 0, 0

5 - 3 = 2;
*/


int main(int argc, char **argv){
    std::vector<int> nums = {1,2,3};
    int r = minMoves(nums);
    printf("R=%d\n", r);
    return(0);
}






