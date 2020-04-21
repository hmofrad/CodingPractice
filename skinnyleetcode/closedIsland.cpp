/*
 *  https://leetcode.com/problems/number-of-closed-islands/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        if(row < 0 or row >= nrows or col < 0 or col >= ncols) return;
        if(grid[row][col]) return;
        grid[row][col]=1;
        
        dfs(grid,row,col-1);
        dfs(grid,row,col+1);
        dfs(grid,row-1,col);
        dfs(grid,row+1,col);

    }

    int closedIsland(vector<vector<int>>& grid) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(not grid[i][j] and (i == 0 or i == nrows-1 or j == 0 or j == ncols-1)) dfs(grid, i, j);
            }
        }

        int count = 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(not grid[i][j]) {dfs(grid, i, j); count++;}
            }
        }
                   
       return count;
    }
};