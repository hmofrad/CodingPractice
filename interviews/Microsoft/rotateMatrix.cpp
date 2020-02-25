/*
 *  Problem: https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/
 *  Rotate a matrix 90 degree clock wise
 *  Compile: g++ -o rotateMatrix rotateMatrix.cpp -g -Wall -fsanitize=address && ./rotateMatrix   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

void print_mat(std::vector<std::vector<int>> mat) {
    for(auto row: mat) {
        for(auto col: row) {
            printf("%2d ", col);
        }
        printf("\n");
    }
    printf("\n");
}

void rotate_mat1(std::vector<std::vector<int>>& mat) {
    std::vector<std::vector<int>> mat1 = mat;
    for(uint32_t i = 0; i < mat.size(); i++) {
        for(uint32_t j = 0; j < mat[i].size(); j++) {    
            mat[j][mat[i].size()-i-1] = mat1[i][j];
        }
    }        
}


void rotate_mat(std::vector<std::vector<int>>& mat) {
    uint32_t n = mat.size();
    uint32_t n_cycles = n/2;
    for(uint32_t i = 0; i < n_cycles; i++) {
        for(uint32_t j = 0; j < n-i-1; j++) {
            int t = mat[i][j];
            mat[i][j] = mat[n-1-j][i];
            mat[n-1-j][i] = mat[n-1-j][n-1-j];
            mat[n-1-i][n-1-j] = mat[j][n-1-j];
            mat[j][n-1-j] = t; 
        }
    }
}



int main(int argc, char** argv){
    //std::vector<std::vector<int>> mat = {{1,2,3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> mat = {{1,2},{3, 4}};
    
    print_mat(mat);
    rotate_mat(mat);
    print_mat(mat);
    
    return(0);
}