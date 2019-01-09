/*
 *  Problem: subsetsWithDup
 *  Compile: g++ -o subsetsWithDup subsetsWithDup.cpp -std=c++11 && ./subsetsWithDup
 *  Execute: ./merge2
 *  (c) Mohammad Mofrad, 2018
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


std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    int m = nums.size();
    std::vector<std::vector<int>> powerset;
    // Find unique members
    std::vector<int> unique;
    std::vector<int> counts;
    bool found = false;
    int u = 0;
    for(int i = 0; i < m; i++) {
        found = false;
        for(u = 0; u < unique.size(); u++) {
            if(nums[i] == unique[u]) {
                found = true;
                break;
            }
        }
        if(found)
            counts[u]++;
        else {
            unique.push_back(nums[i]);
            counts.push_back(1);
        }
    }
    
    int n = unique.size();
    for(int i = 0; i < m; i++) {
        printf("[%d %d] ", unique[i], counts[i]);
    }
    printf("\n");
    
    int k = 0;
    //powerset.resize(n);
    for(int i = 0; i < n; i++) {
        printf("%d\n", unique[i]);
        if(counts[i] > 1) {
            for(int j = 0; j < counts[i]; j++) {
                printf("%d ", unique[i]);
            }
            printf("\n");
        }
            //k++;
    }
    //printf("k=%d\n", k);
    //powerset.resize(n+1);
    //for(int i = 0; i < n; i++) {
    //    powerset[k].push_back(unique[i]);
    //}
    
    
    // 
    
    
    return(powerset);
}


int main(int argc, char** argv) {
    int m = 3;
    std::vector<int> nums = {1, 2, 2};
    
    for(int i = 0; i < m; i++)
        printf("%d ", nums[i]); 
    printf("\n");
    
    std::vector<std::vector<int>> powerset = subsetsWithDup(nums);
    
    printf("[");
    for(int i = 0; i < powerset.size(); i++) {
        printf("[");
        for(int j = 0; j < powerset[i].size(); j++) {
            if((j + 1) < powerset[i].size()) 
                printf("%d,", powerset[i][j]);
            else
                printf("%d", powerset[i][j]);
        }
        if((i + 1) < powerset.size()) 
            printf("], ");
        else
            printf("]");
    }
    printf("]\n");
    
    
    return(0);
}