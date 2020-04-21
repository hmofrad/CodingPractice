/*
 *  https://leetcode.com/problems/minimum-falling-path-sum-ii/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

    int minFallingPathSum1(vector<vector<int>>& arr, int row, int col, int sum) {
        int nrows = arr.size();
        int ncols = (nrows) ? arr[0].size() : 0;
        if(row < 0 or row > nrows or col < 0 or col > ncols) return INT_MAX;
        if(row == nrows-1 and col >= 0 and col < ncols) return arr[row][col] + sum;
        
        sum += arr[row][col];
        
        std::vector<int> s1(ncols-1);
        int k = 0;
        for(int j = 0; j < ncols; j++) {
            if(j != col) {
                s1[k] = minFallingPathSum1(arr, row+1, j, sum);
                k++;
            }
        }
        
        for(auto ss: s1) printf("%d ", ss); printf("[%d %d]\n", row, col);
        return *std::min_element(s1.begin(), s1.end());
    }
    int minFallingPathSum(vector<vector<int>>& arr) {
        int nrows = arr.size();
        int ncols = (nrows) ? arr[0].size() : 0;
        int sum = INT_MAX;
        for(int j = 2; j < 3; j++) {sum = min(sum, minFallingPathSum1(arr, 0, j, 0));}
        return sum;
    }


int main() {
    vector<vector<int>> arr = {{2,2,1,2,2},
                               {2,2,1,2,2},
                               {2,2,1,2,2},
                               {2,2,1,2,2},
                               {2,2,1,2,2}};
    int r = minFallingPathSum(arr);
    printf("Ret=%d ? 7\n", r);
    return 0;
}