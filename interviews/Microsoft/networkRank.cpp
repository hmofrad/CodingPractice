/*
 *  Problem: https://leetcode.com/discuss/interview-question/364760/
 *  Compile: g++ -o networkRank networkRank.cpp -std=c++11 -g -Wall -fsanitize=address && ./networkRank
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

int networkRank(std::vector<int> A, std::vector<int> B, int N) {
    N = N+1;
    int maximalRank = 0;
    std::vector<std::vector<int>> Mat(N, std::vector<int>(N));
    uint32_t M = A.size();
    for(uint32_t i = 0; i < M; i++) {
        auto e1 = A[i];
        auto e2 = B[i];
        Mat[e1][e2] = 1;
        Mat[e2][e1] = 1;
    }
    
    for(auto r: Mat) {
        for(auto c: r) {
            printf("%d ", c);
        }
        printf("\n");
    }
    
    
    for(int32_t i = 0; i < N; i++) {
        printf("%d ",i );
        int e1_rowSum = 0;
        for(int32_t j = i; j < N; j++) {
        //for(int32_t j = 0; j < N; j++) {
            e1_rowSum += Mat[i][j];
        }
        
        for(int32_t j = 0; j < N; j++) {
            if(Mat[i][j]) {
                printf("%d ",j);
                int e2_rowSum = 0;
                for(int32_t k = 0; k < N; k++) {
                    e2_rowSum += Mat[j][k];
                }
                int e_sum = e1_rowSum + e2_rowSum;
                if(e_sum > maximalRank) { 
                    printf("[%d > %d ]", e_sum, maximalRank);
                    maximalRank = e_sum;
                }
            }
        }
        printf("\n");
    }
    
    
    
    
    
    
    return(maximalRank);
}

int main(int argc, char **argv){
    std::vector<int> A = {1, 2, 3, 3};
    std::vector<int> B = {2, 3, 1, 4};
    int N = 4;
    int maximalRank = networkRank(A, B, N);
    printf("Maximal Rank=%d\n", maximalRank);
    
    return(0);
}
