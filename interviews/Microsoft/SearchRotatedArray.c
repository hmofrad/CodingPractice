/*
 *  Problem: https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
 *  Search an element in a sorted and rotated array [1, 2, 3, 4, 5] --> [3, 4, 5, 1, 2]
 *  Compile: g++ -o SearchRotatedArray SearchRotatedArray.c -std=c++11 -g -Wall -fsanitize=address && ./SearchRotatedArray
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int binarySearch(int nums[], int low, int high, int num) {
    if(low <= high) {
        int mid = (low+high)/2; 
        printf("low=%d mid=%d high=%d\n", low, mid, high);
        if(nums[mid] == num) {
            return(mid);
        }
        else if(nums[mid] < num) {
            return(binarySearch(nums, mid+1, high, num));
        }
        else {
            return(binarySearch(nums, low, mid-1, num));
        }
    }
    return(-1);
}

int findPivot(int nums[], int low, int high) {
    if(low > high) {
        return(-1);
    }
    if(low == high) {
        return(low);
    }
    int mid = (low+high)/2;
    if((mid < high) && (nums[mid] > nums[mid+1])) {
        return(mid);
    }
    if((mid > low) && (nums[mid] < nums[mid-1])) {
        return(mid-1);
    }
    
    if(nums[low] >= nums[mid]) {
        return(findPivot(nums, low, mid-1));
    }
    else {
        return(findPivot(nums, mid+1, high));
    }
}

int pivotedBinarySearch(int nums[], int sz, int num) {
    int pivot = findPivot(nums, 0, sz-1);
    if(pivot == -1) {
        return(binarySearch(nums, 0, sz-1, num));
    }
    
    if(nums[pivot] == num) {
        return(pivot);
    }
    else if(nums[0] <= num) {
        return(binarySearch(nums, 0, pivot-1, num));
    }
    else {
        return(binarySearch(nums, pivot+1, sz-1, num));
    }
}

int search(int nums[], int sz, int num) {
    //return(binarySearch(nums, 0, sz-1, num));
    
    return(pivotedBinarySearch(nums, sz, num));
    
    
}


int main(int argc, char **argv){
    //int nums[] = {1, 2, 3, 4, 5, 6}; // Regular
    int nums[] = {3, 4, 5, 6, 1, 2}; // Shifted
    int sz = sizeof(nums)/sizeof(nums[0]);
    int num = 1;
    int index = search(nums, sz, num);
    
    
    
    printf("nums[%d]=%d\n", index, num);
    return(0);
}
