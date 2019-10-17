    /*
 *  Problem: https://leetcode.com/problems/maximal-square/
 *  Compile: g++ -o maximalSquare maximalSquare.cpp -std=c++11 && ./maximalSquare
 *  Execute: ./maximalSquare
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
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
#include <unordered_set>


void print(std::vector<std::vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");   
    }
    printf("\n");  
}

void print1(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");   
    }
    printf("\n");  
}

int maximalSquare(std::vector<std::vector<char>>& matrix) {
    int maxSquare = 0;
    int n = matrix.size();
    if(n == 0) return(maxSquare);
    int m = matrix[0].size();
    
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1));
    
     
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j]) {
                dp[i+1][j+1] = std::min({dp[i][j], dp[i][j+1], dp[i+1][j]}) + 1;
                maxSquare = std::max(maxSquare, dp[i+1][j+1]);    
            }
        }
        print1(dp);
    }
    
    
    /*
    
    while(n < m) {
        n++;
        matrix.resize(n);
        for(int i = 0; i < m; i++) {
            //printf("%d %lu %lu\n", i, matrix.size(), matrix[n-1].size());
            matrix[n-1].push_back(0);
        }
    }
    
    while(m < n) {
        m++;
        for(int i = 0; i < n; i++) {
            matrix[i].push_back(0);
        }
    }
    */
    //print(matrix);
    /*
    std::vector<std::vector<char>> res(n);
    for(int i = 0; i < n; i++) {
        res[i].resize(m);
    }
    
    print(res);
    */
    
    
  
    
    //print(res);
    /*
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = 0; k < m; k++) {
                row[k] = matrix[i][k] + matrix[j][k];
                //printf("%d ", matrix[i][k]);
            }
        //printf("\n");   
        }
    }
    */
    return(maxSquare*maxSquare);
}

int main(int argc, char **argv){
    std::vector<std::vector<char>> mat = {{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    //std::vector<std::vector<char>> mat = {{1, 0, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}};
    //std::vector<std::vector<char>> mat = {{0}};
    print(mat);
    printf("maximalSquare? %d\n", maximalSquare(mat));
    
    return(0);
}