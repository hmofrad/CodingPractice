/*
 *  https://leetcode.com/problems/sparse-matrix-multiplication/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int A_nrows = A.size();
        int A_ncols = (A_nrows) ? A[0].size() : 0;
        
        int B_nrows = B.size();
        int B_ncols = (B_nrows) ? B[0].size() : 0;
        
        std::vector<std::vector<std::pair<int, int>>> A1(A_nrows);
        for(int i = 0; i < A_nrows; i++) {
            for(int j = 0; j < A_ncols; j++) {
                if(A[i][j]) A1[i].push_back({j, A[i][j]});
            }
        }
        
        std::vector<std::vector<std::pair<int, int>>> B1(B_nrows);
        for(int i = 0; i < B_nrows; i++) {
            for(int j = 0; j < B_ncols; j++) {
                if(B[i][j]) B1[i].push_back({j, B[i][j]});
            }
        }
        /*
        vector<vector<int>> C(A_nrows, std::vector<int>(B_ncols));
        for(int i = 0; i < A_nrows; i++) {
            for(auto colA: A1[i]) {
                int temp = 0;
                for(auto rowB: B1[colA.first]) {
                    C[i][rowB.first] += colA.second * rowB.second;
                };
            }
        }
        */
        
        
        vector<vector<int>> C;
        for(int i = 0; i < A_nrows; i++) {
            std::vector<int> temp(B_ncols);
            for(auto colA: A1[i]) {    
                for(auto rowB: B1[colA.first]) {
                     temp[rowB.first]+= colA.second * rowB.second;
                }
            }
            C.push_back(temp);
        }

        return C;
    }
    
    
    vector<vector<int>> multiply1(vector<vector<int>>& A, vector<vector<int>>& B) {
        int A_nrows = A.size();
        int A_ncols = (A_nrows) ? A[0].size() : 0;
        
        int B_nrows = B.size();
        int B_ncols = (B_nrows) ? B[0].size() : 0;
        vector<vector<int>> C(A_nrows, std::vector<int>(B_ncols));
        
        for(int i = 0; i < A_nrows; i++) {
            for(int j = 0; j < A_ncols; j++) {
                for(int k = 0; k < B_ncols; k++) {
                   C[i][k] += A[i][j]*B[j][k];
                }
            }
        }
        return C;
    }
};
int main() {
    vector<vector<int>> A = {{1,-5}};
    vector<vector<int>> B = {{12},{-1}};
    vector<vector<int>> C = multiply(A, B);
    
    print(A); print(B); print(C);
}