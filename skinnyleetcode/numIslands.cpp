/*
 *  https://leetcode.com/problems/number-of-islands/submissions/
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
    int search(vector<vector<char>>& grid, int row, int col) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        if(row < 0 or row >= nrows) return 0;
        if(col < 0 or col >= ncols) return 0;
        if(grid[row][col] <= '0') return 0;
        grid[row][col]='0';
        search(grid, row, col+1);
        search(grid, row, col-1);
        search(grid, row-1, col);
        search(grid, row+1, col);
        return 1;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        int nislands = 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                nislands += search(grid, i, j);
            }
        }
        return nislands;
    }
}; 
 