/*
 *  Cracking the coding interview: Problem 18.6: Find ith smallest or largest element in an array in linear time
 *  Compile & run: g++ -o  selectionRank selectionRank.cpp -g -Wall -std=c++11 -fsanitize=address  && ./selectionRank
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int rand_gen(int min_range, int max_range) {
    return(min_range + (rand() %(max_range - min_range + 1)));
}

int partition(std::vector<int>& array, int left, int right, int pivot) {
    while(true) {
        while(left <= right and array[left] <= pivot) {
            left++;
        }
        
        while(left <= right and array[right] > pivot) {
            right--;
        }
        if(left > right) {
            return(left-1);
        }
        std::swap(array[left], array[right]);
    }
}

int rank(std::vector<int>& array, int left, int right, int rank_) {
    printf("left=%d right=%d rank=%d\n", left, right, rank_);
    int pivot = array[rand_gen(left, right)];
    int leftEnd = partition(array, left, right, pivot);
    int leftSize = leftEnd - left + 1;
    if(leftSize == rank_ + 1) {
        return(std::max(left, leftEnd));
    }
    else if(rank_ < leftSize) {
        return(rank(array, left, leftEnd, rank_));
    }
    else {
        return(rank(array, leftEnd+1, right, rank_-leftSize));
    }
}

int main(int argc, char** argv) {
    srand(time(NULL));
    std::vector<int> array = {1, 2, 3, 4, 6, 23, 76, 12, 67, 90, 34, 35, 56, 44};
    //std::sort(array.begin(), array.end());
    //printf("%d %d\n", array[9], array[10]);
    int num = rank(array, 0, array.size()-1, 6);
    printf("N=%d %d\n", num, array[num]);
    
    return(0);
}