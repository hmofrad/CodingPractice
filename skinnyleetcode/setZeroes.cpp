/*
 *  Problem: Implement Pow(x, n)
 *  Compile: g++ -o setZeroes setZeroes.cpp -std=c++11 && ./setZeroes
 *  Execute: ./setZeroes
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

void my_zeros(int iz, int jz, std::vector<std::vector<int>>& matrix)
{
    int m = matrix.size();
    int n = (m > 0) ? matrix[0].size() : 0;
    
    for(int i = 0; i < m; i++)
        matrix[i][jz] = 0;
    
    for(int j = 0; j < n; j++)    
        matrix[iz][j] = 0;
}

void setZeroes(std::vector<std::vector<int>>& matrix)
{
    int m = matrix.size();
    int n = (m > 0) ? matrix[0].size() : 0;
    std::vector<int> ijs;
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == 0)
            {
                ijs.insert(ijs.end(), {i, j});
            }
        }
    }
    
    for(int i = 0; i < ijs.size(); i = i + 2)
    {
        printf("i=%d j=%d\n", ijs[i], ijs[i+1]);
        my_zeros(ijs[i], ijs[i+1], matrix);
    }

}

int main(int argc, char **argv)
{
    int m = 3;
    int n = 3;
    std::vector<std::vector<int>> matrix;
    matrix.resize(m);
    for(int i = 0; i < m; i++)
    {
        std::vector<int>& mat = matrix[i];
        mat.resize(n);
        for(int j = 0; j < n; j++)
        {
            mat[j] = 1;
        }
    }
    matrix[1][1] = 0;
    
    setZeroes(matrix);
    
    for(int i = 0; i < m; i++)
    {
        std::vector<int>& mat = matrix[i];
        for(int j = 0; j < n; j++)
        {
            printf("%d ", mat[j]);
        }
        printf("\n");
    }
    
    return(0);
}