/*
 *  Cracking the coding interview: Problem 11.3: Find an element in sorted array which has been rotated multiple times
 *  Compile & run: g++ -o findInSortedRotated findInSortedRotated.cpp -g -Wall && ./findInSortedRotated
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
/*
uint32_t find_index(std::vector<int32_t> nums, int32_t element) {
    uint32_t index = 0;
    for(uint32_t i = 0; i < nums.size(); i++) {
        if(nums[i] == element) {
            index = i;
            break;
        }
    }
    return(index);
}
*/

int32_t search(std::vector<int32_t> nums, int32_t left, int32_t right, int32_t x) {
    uint32_t mid = (right + left)/2;
    if(nums[mid] == x) {
        return(mid);
    }
    if(right < left) {
        return(-1);
    }
    
    if(nums[left] < nums[mid]) { // left is sorted
        if(x >= nums[left] and x <= nums[mid]) {
            return(search(nums, left, mid-1, x));
        }
        else {
            return(search(nums, mid+1, right, x));
        }
    }
    else if(nums[mid] < nums[left]) { //right is sorted
        if(x >= nums[mid] and x <= nums[right]) {
            return(search(nums, mid+1, right, x));
        }
        else {
            return(search(nums, left, mid-1, x));
        }
    }
    else if(nums[left] == nums[mid]) { // left half is all repeats
        if(nums[mid] != nums[right]) {
            return(search(nums, mid+1, right, x));
        }
        else {
            int result = search(nums, left, mid-1, x);
            if(result == -1) {
                return(search(nums, mid+1, right, x));
            }
            else {
                return(result);
            }
        }
    }

    return(-1);
}


int32_t find_index(std::vector<int32_t> nums, int32_t x) {
    int32_t left = 0;
    int32_t right = nums.size()-1;
    int32_t index = search(nums, left, right, x);
    return(index);
}


int main(int argc, char** argv) {
    std::vector<int32_t> nums = {15, 16, 19, 20, 25,1, 3, 4, 5, 7, 10, 14};
    int x = 5;
    int index = find_index(nums, x);
    printf("%d, %d == %d\n", index, nums[index], x);
}