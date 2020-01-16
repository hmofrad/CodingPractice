/*
 *  Cracking the coding interview: Problem 18.9: Maintain median for a dynamically size array
 *  Compile & run: g++ -o  maintainMedian maintainMedian.cpp -g -Wall -std=c++11 -fsanitize=address  && ./maintainMedian
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>

int get_median(std::priority_queue<int> max_heap, std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap) {
    int median = 0;
    if(max_heap.size() > min_heap.size()) {
        median = max_heap.top();
    }
    else if (max_heap.size() == min_heap.size()) {
        median = (max_heap.top() + min_heap.top())/2;
    }
    return(median);
}

void refine(std::priority_queue<int>& max_heap, std::priority_queue<int, std::vector<int>, std::greater<int>>& min_heap) {
    if(min_heap.size() > max_heap.size()) {
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
    else if (max_heap.size() == min_heap.size() + 2) {
        min_heap.push(max_heap.top());
        max_heap.pop();
    }
}


void maintain_median(std::vector<int> nums) {
    std::priority_queue<int> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    
    int median = 0;
    max_heap.push(nums[0]);
    for(uint32_t i = 1; i < nums.size(); i++) {
        median = get_median(max_heap, min_heap);
        if(nums[i] > median) {
            min_heap.push(nums[i]);
        }
        else{
            max_heap.push(nums[i]);
        }
        refine(max_heap, min_heap);
        
        for(uint32_t j = 0; j <= i; j++) {
            printf("%2d ", nums[j]);
        }
        printf("\nMedian=%d %lu %lu\n",  get_median(max_heap, min_heap), max_heap.size(), min_heap.size());
        
    }
    
    while(!max_heap.empty()) {
        
        printf("%2d ", max_heap.top());
        max_heap.pop();
    }
    printf("\n");
    
    while(!min_heap.empty()) {
        printf("%2d ", min_heap.top());
        min_heap.pop();
    }
    printf("\n");
}


int main(int argc, char** argv) {
    std::vector<int> nums = {3, 54, 2, 56, 78, 76, 3, 9, 2, 0, 12, 56, 92, 59, 10, 43};
    for(uint32_t i = 0; i < nums.size(); i++) {
        printf("%2d ", nums[i]);
    }
    printf("\n");

    maintain_median(nums);
    
    return(0);
}