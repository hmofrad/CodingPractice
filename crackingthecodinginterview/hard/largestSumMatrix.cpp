/*
 *  Cracking the coding interview: Problem 18.12: Find the largest sum submatrix in a nxn matrix
 *  Compile & run: g++ -o  largestSumMatrix largestSumMatrix.cpp -g -Wall -std=c++11 -fsanitize=address  && ./largestSumMatrix
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h> 

int largestSum(std::vector<std::vector<int>> matrix) {
    int sum = matrix[0][0];
    
    
    for(uint32_t i = 0; i < matrix.size(); i++) {
        for(uint32_t j = 0; j < matrix[0].size(); j++) {    
            
        }
    }
    
    return(sum);
}


int main(int argc, char** argv) {
    std::vector<std::vector<int>> matrix = {{ 1,  2,  6, -4,  3, 45},
                                            { 2, 23, 36,  35, 72, -59},
                                            { 45, 6, 6,  3, 12, 39},
                                            { 4, 9, 7,  32, 25, 69},
                                            { 7, 23, 2,  3, -22, 29},
                                            { 9, 2, 4,  3, 52, 98}};
                                            
    
    //printf("Is=%d\n", isSubStr("ana", "bananana"));
    
    return(0);
}