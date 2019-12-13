/*
 *  Problem: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 *  Compile: g++ -o kthSmallest_matrix kthSmallest_matrix.cpp -std=c++11  -g -Wall -fsanitize=address && ./kthSmallest_matrix
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
    k--;
    uint32_t m = matrix.size();
    uint32_t n = matrix[0].size();
    int i = k/m;
    int j = k%n;
    printf("%d %d %d %d %d \n", m, n, i, j, k);
    return(matrix[i][j]);        
}

int main(int argc, char **argv){
    std::vector<std::vector<int>> matrix = {{ 1,  5,  9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    int s = kthSmallest(matrix, k);
    printf("%d smallest = %d\n", k, s);
    return(0);
}






