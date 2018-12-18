/*
 *  Problem: Implement Pow(x, n)
 *  Compile: g++ -o searchMatrix searchMatrix.cpp -std=c++11 && ./searchMatrix
 *  Execute: ./searchMatrix
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <string.h>

static int t = 0;

int matrixBinarySearch(std::vector<std::vector<int>>& matrix, int target, int left, int right) {
    t++;

    int row = 0;
    int m = matrix.size();
    int n = matrix[0].size();
        
    if(left == right)
        row = left;
    else if((left + 1) == right) {
        if(matrix[left][n-1] >= target)
            row = left;
        else
            row = right;
    } 
    else {
        
        int mid = ((right - left)+1)/2 + left;
        printf("%d %d %d %d %d\n", left, mid, mid+1, right, matrix[mid][n-1] > target);
        //if(t == 3)
        //exit(0);
        if(matrix[mid][n-1] > target)
            row = matrixBinarySearch(matrix, target, left, mid);
        else  
            row = matrixBinarySearch(matrix, target, mid+1, right);
    }
    printf("%d %d %d %d\n", left, right, matrix[left][n-1] > target, row);
    return(row);
}


bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    bool found = false;
    int m = matrix.size();
    if(m == 0)
        return(found);
    int n = matrix[0].size();
    int row = matrixBinarySearch(matrix, target, 0, m-1);
    int col = 0;
    for(int j = 0; j < n; j++) {
        if(matrix[row][j] == target) {
            found = true;
            col = j;
        }
    }
    printf("row=%d col=%d\n", row, col);
    return(found);
}

int main(int argc, char **argv)
{
    int target = 2;
    int m = 2;
    int n = 1;
    std::vector<std::vector<int>> matrix;
    matrix.resize(m);
    for(int i = 0; i < m; i++) {
        matrix[i].resize(n);
        for(int j = 0; j < n; j++) {
            matrix[i][j] = (i * (n + 2)) + (j + 2);
        }
    }
    
    for(int i = 0; i < m; i++) {
        matrix[i].resize(m);
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("searchMatrix(%d)=%d\n", target, searchMatrix(matrix, target));
    
    
    return(0);
}