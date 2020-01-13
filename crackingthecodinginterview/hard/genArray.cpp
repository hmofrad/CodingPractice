/*
 *  Cracking the coding interview: Problem 18.2: Generate array
 *  Compile & run: g++ -o genArray genArray.cpp -g -Wall -std=c++11 -fsanitize=address  && ./genArray
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>

int my_rand(int min, int max) {
    
    return(min + (rand() % (max - min + 1)));
}

std::vector<int> gen_arry(std::vector<int> nums, int n) {
    std::vector<int> arr;
    for(int32_t i = 0; i < n; i++) {
        int k = my_rand(0, nums.size()-1);
        printf("%d %d %d\n", i, k, nums[k]);
        //std::swap(cards[k], cards[i]);
        arr.push_back(nums[k]);
    }
    return(arr);
}

int main(int argc, char** argv) {
    srand(time(NULL));
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int n = 10;
    std::vector<int> array = gen_arry(nums, n);
    
    for(auto a: array) {
        printf("%d ", a);
    }
    printf("\n");
    
    return(0);
}