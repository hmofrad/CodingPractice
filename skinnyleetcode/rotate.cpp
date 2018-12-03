/*
 *  Problem: Permutation sequence
 *  Compile: g++ -o rotate rotate.cpp && ./rotate
 *  Execute: ./rotate
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

void print(std::vector<std::vector<int> > matrix)
{
    int n = matrix[0].size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%02d ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

void rotate(std::vector<std::vector<int> > &matrix)
{
    print(matrix);
    int n = matrix[0].size();
    std::vector<std::vector<int> > matrix1;
    matrix1.resize(n);
    for(int i = 0; i < n; i++)
        matrix1[i].resize(n);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int ii = j;
            int jj = n - (i+1);
            matrix1[ii][jj] = matrix[i][j];
        }
    }
    print(matrix1);
    
}

void rotate1(std::vector<std::vector<int> > &matrix)
{
    print(matrix);
    int n = matrix[0].size();
    int d = n - 1;
    
    
    
    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int ii = j;
            int jj = n - (i+1);
            std::swap(matrix[i][j], matrix[ii][jj]);
        }
    }
    print(matrix);
    
}

int main(int argc, char **argv)
{
    int n = 2;
    std::vector<std::vector<int> > matrix;
    matrix.resize(n);
    for(int i = 0; i < n; i++)
        matrix[i].resize(n);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            matrix[i][j] = (i * n) + j + 1;
        }
    }
    
    rotate1(matrix);
    printf("%d\n", n/2);
    
    
    return(0);
}