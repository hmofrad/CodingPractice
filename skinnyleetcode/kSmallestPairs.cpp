/*
 *  Problem: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
 *  Compile: g++ -o kSmallestPairs kSmallestPairs.cpp -std=c++11  -g -Wall -fsanitize=address && ./kSmallestPairs
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>   
#include <queue>
#include <utility>
/*
std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, 
                                             std::vector<int>& nums2, 
                                             int k) {
    std::vector<std::vector<int>> pairs;
    
    uint32_t i1 = 0;
    uint32_t i2 = 0;
    while((pairs.size() < (uint32_t) k) and ((i1 < nums1.size()) and (i2 < nums2.size()))) {
        printf("%d %d\n", i1, i2);
        pairs.push_back({nums1[i1], nums2[i2]});
        if(nums1[i1] < nums2[i2]) {
            i2++;
        }
        else if (nums1[i1] > nums2[i2]){
            i1++;
        }
        else {
            if(((i1+1) < nums1.size()) and ((i2+1) < nums2.size())) {
                if(nums1[i1+1] <= nums2[i2+1]) {
                    i1++;
                }
                else {
                    i2++;
                }
            }
            else if((i1+1) < nums1.size()) {
                i1++;
            }
            else {
                i2++;
            }
        }
    }
    
    
    return(pairs);
}
*/

std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, 
                                             std::vector<int>& nums2, 
                                             int k) {
    std::priority_queue<std::pair<int, std::vector<int>>> q;
    for(uint32_t i = 0; i < nums1.size(); i++) {
        for(uint32_t j = 0; j < nums2.size(); j++) {
            if(q.size() < (uint32_t) k) {
                std::vector<int> b = {nums1[i], nums2[j]};
                //b.push_back(nums1[i]);
                //b.push_back(nums2[i]);
                q.push(std::make_pair((nums1[i] + nums2[j]), b));
            }
            else {
                if((nums1[i] + nums2[j]) < q.top().first) {
                    q.pop();
                    std::vector<int> b = {nums1[i], nums2[j]};
                    //std::vector<int> b;
                    //b.push_back(nums1[i]);
                    //b.push_back(nums2[j]);
                    q.push(std::make_pair((nums1[i] + nums2[j]), b));
                }
            }
        }
    }
    
    std::vector<std::vector<int>> pairs;
    while(!q.empty()) {
        pairs.push_back(q.top().second);
        q.pop();
    }
    
    return(pairs);
}


int main(int argc, char **argv){
    std::vector<int> nums1 = {1, 1, 2};
    std::vector<int> nums2 = {1, 2, 3};
    int k = 10;
    
    std::vector<std::vector<int>> pairs = kSmallestPairs(nums1, nums2, k);
    
    printf("k = %d\n", k);
    for(auto n: nums1) { printf("%d ", n); } printf("\n");
    for(auto n: nums2) { printf("%d ", n); } printf("\n");
    for(auto pair: pairs) { printf("[%d %d] ", pair[0], pair[1]); } printf("\n");
    
    return(0);
}






