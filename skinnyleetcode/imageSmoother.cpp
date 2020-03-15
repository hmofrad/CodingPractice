/*
 *  Problem: https://leetcode.com/problems/image-smoother/
 *  Compile: g++ -o imageSmoother imageSmoother.cpp -std=c++11 -g -Wall -fsanitize=address && ./imageSmoother
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>



void print(std::vector<std::vector<int>> image) {
    for(auto row: image) {
        for(auto col: row) {
            printf("%d ", col);
        }
        printf("\n");
    }
    printf("\n");
}

void paint(std::vector<std::vector<int>>& N, std::vector<std::vector<int>>& M, uint32_t i, uint32_t j) {
    uint32_t m = M.size();
    uint32_t n = (m) ? M[0].size() : 0;

    N[i][j] = M[i][j];
    int k = 1;    
    if(i == 0) {
        if(j == 0) {
            if(n > 1) {
                N[i][j] += M[i][j+1];
                k++;
            }
            if(m > 1) {
                N[i][j] += M[i+1][j];
                k++;
            }
            if((n>1) and (m>1)) {
                N[i][j] += M[i+1][j+1];
                k++;
            }
            N[i][j] = floor(N[i][j]/k);
        }
        else if(j == n-1) {
            if(n > 1) {
                N[i][j] += M[i][j-1];
                k++;
            }
            if(m > 1) {
                N[i][j] += M[i+1][j];
                k++;
            }
            if((n>1) and (m>1)) {
                N[i][j] += M[i+1][j-1];
                k++;
            }
            N[i][j] = floor(N[i][j]/k);
        }
        else {
            N[i][j] += M[i][j-1];
            N[i][j] += M[i][j+1];
            k+=2;
            if(m>1) {
                N[i][j] += M[i+1][j-1];
                N[i][j] += M[i+1][j];    
                N[i][j] += M[i+1][j+1];    
                k +=3;
            }
            N[i][j] = floor(N[i][j]/k);
        }
    }
    else if(i == m-1) {
        if(j == 0) {
            if(n > 1) {
                N[i][j] += M[i][j+1];
                k++;
            }
            if(m > 1) {
                N[i][j] += M[i-1][j];
                k++;
            }
            if((n>1) and (m>1)) {
                N[i][j] += M[i-1][j+1];
                k++;
            }
            N[i][j] = floor(N[i][j]/k);
        }
        else if(j == n-1) {
            if(n > 1) {
                N[i][j] += M[i][j-1];
                k++;
            }
            if(m > 1) {
                N[i][j] += M[i-1][j];
                k++;
            }
            if((n>1) and (m>1)) {
                N[i][j] += M[i-1][j-1];
                k++;
            }
            N[i][j] = floor(N[i][j]/k);
        }
        else {
            N[i][j] += M[i][j-1];
            N[i][j] += M[i][j+1];
            k+=2;
            if(m>1) {
                N[i][j] += M[i-1][j-1];
                N[i][j] += M[i-1][j];    
                N[i][j] += M[i-1][j+1];    
                k +=3;
            }
            N[i][j] = floor(N[i][j]/k);
        }
    }
    else {
        N[i][j] += M[i+1][j+1];
        N[i][j] += M[i+1][j];
        N[i][j] += M[i+1][j+1];
        N[i][j] += M[i][j-1];
        N[i][j] += M[i][j+1];
        N[i][j] += M[i-1][j-1];
        N[i][j] += M[i-1][j];
        N[i][j] += M[i-1][j+1];
        k += 7;
        N[i][j] = floor(N[i][j]/k);
    }

}

std::vector<std::vector<int>> imageSmoother1(std::vector<std::vector<int>>& M) {
    int m = M.size();
    int n = (m) ? M[0].size() : 0;
    
    std::vector<std::vector<int>> N(m, std::vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {   
            int total = 0;
            int sum = 0;
            for(int y = i - 1; y <= i + 1; y++) {
                for(int x = j - 1; x <= j + 1; x++) {
                    if(y >= 0 and y < m and x >= 0 and x < n) {
                        total++;
                        sum += M[y][x];
                    }
                }
            }
            N[i][j] += (total) ? floor(sum/total) : 0;
        }
    }
    
    return(N);
}

std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& M) {
    int m = M.size();
    int n = (m) ? M[0].size() : 0;
    
    std::vector<std::vector<int>> N(m, std::vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {   
            int k = 1;
            N[i][j] += M[i][j];
            if(i+1 < m) {
                N[i][j] += M[i+1][j];
                k++;
            }
            
            if(i-1 >= 0){
                N[i][j] += M[i-1][j];
                k++;
            }
            
            if(j+1 < n){
                N[i][j] += M[i][j+1];
                k++;
            }
            
            if(j-1 >= 0){
                N[i][j] += M[i][j-1];
                k++;
            }
            
            if((i+1 < m) && (j+1 < n)){
                N[i][j] += M[i+1][j+1];
                k++;
            }
            
            if((i+1 < m) && (j-1 >= 0)){
                N[i][j] += M[i+1][j-1];
                k++;
            }

            if((i-1 >= 0) && (j+1 < n)){
                N[i][j] += M[i-1][j+1];
                k++;
            }

            if((i-1 >= 0) && (j-1 >= 0)){
                N[i][j] += M[i-1][j-1];
                k++;
            }
            N[i][j] /= k;
        }
    }
    
    return(N);
}


int main(int argc, char **argv){
    std::vector<std::vector<int>> M = {{1,1,1},
                                       {1,0,1},
                                       {1,1,1}};
    std::vector<std::vector<int>> N = imageSmoother(M);                                    
    
    print(M);
    print(N);
    
    return(0);
}