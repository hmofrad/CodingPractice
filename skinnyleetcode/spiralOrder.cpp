/*
 *  Problem: Implement Pow(x, n)
 *  Compile: g++ -o spiralOrder spiralOrder.cpp -std=c++11 && ./spiralOrder
 *  Execute: ./spiralOrder
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

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    int d = n > m ? std::ceil((double) n/2) : std::ceil((double) m/2);
    int off = 0;
    printf("d=%d\n", d);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
           printf("%d ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
    int i = 0, j = 0;
    for(j = 0; j < m; j++)
        printf("%d ", matrix[i][j]);
    printf(" ");
    j = m-1;
    for(i = 1; i < n-1; i++)
        printf("%d ", matrix[i][j]);
    printf(" ");    
    
    i = n - 1;
    for(j = m-1; j >= 0; j--)
        printf("%d ", matrix[i][j]);
    printf(" \n");   
    
    j = 0;
    for(i = 1; i < n-1; i++)
        printf("%d ", matrix[i][j]);
    printf(" ");        

    
    
    //for(int i = 0; i < n; i++)
    //{
    //    for(int j = 0; j < m; j++)
    //        printf("%d ", i*n + j);
    //}
    //printf("\n");
    
    
    
    
    std::vector<int> vector;
    return(vector);
}

int main(int argc, char **argv)
{
    int n = 3;
    int m = 3;
    
    std::vector<std::vector<int>> matrix(n);
    for(int i = 0; i < n; i++)
        matrix[i].resize(m);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            //matrix[i][j] = 1; 
            matrix[i][j] = i*n + j; 
    }
    std::vector<int> vector = spiralOrder(matrix);
    return(0);
}