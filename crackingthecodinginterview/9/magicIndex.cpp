/*
 *  Cracking the coding interview: Problem 9.2: Possible path from (0,0) to (x,y)
 *  Compile & run: g++ -o magicIndex magicIndex.cpp -g -Wall -std=c++11 -fsanitize=address  && ./magicIndex
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>


//int ways(std::vector<std::vector<int>> grid, uint32_t i, uint32_t j) {
//    if((grid.size()-1 == i) and grid[0].size()-1 == i)
//}

int binarySearch(std::vector<int> nums, uint32_t start, uint32_t end) {
    printf("%d %d\n", start, end);
    if(end < start or start < 0 or end >= nums.size()) return(-1);
    int mid = (start + end)/2;
    if(nums[mid] == mid) {
        return(mid);
    }
    else if(nums[mid] < mid) {
        start = mid+1;
        return(binarySearch(nums, start, end));
    }
    else {
        end = mid-1;
        return(binarySearch(nums, start, end));
    }
    return(-1);
}


int magicIndex(std::vector<int> nums) {
    
    return(binarySearch(nums, 0, nums.size()-1));
    
    /*
    for(uint32_t i = 0; i < nums.size(); i++) {
        if((uint32_t) nums[i] == i)
            return(i);
    }
    
    return(-1);   
    */
    
}



int main(int argc, char** argv) {
    std::vector<int> nums = {-2, -1, 0, 1, 2, 3, 6, 8};
    for(auto n: nums) {
        printf("%d ", n);
    }
    printf("\n");
    
    int n = magicIndex(nums);
    printf("%d\n", n);
    
    return(0);
}