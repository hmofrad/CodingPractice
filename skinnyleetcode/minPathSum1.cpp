/*
 * https://leetcode.com/problems/minimum-path-sum/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        std::vector<std::vector<int>> dp(nrows, std::vector<int>(ncols));

        for(int i = nrows-1; i >= 0; i--) {
            for(int j = ncols-1; j >= 0; j--) {
                if     (i == nrows-1 and j == ncols-1) { dp[i][j] = grid[i][j]; }
                else if(i == nrows-1 and j <  ncols-1) { dp[i][j] = grid[i][j] +    dp[i][j+1]; }
                else if(i <  nrows-1 and j == ncols-1) { dp[i][j] = grid[i][j] +    dp[i+1][j]; }
                else if(i <  nrows-1 and j <  ncols-1) { dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]); }
                
            }
        }
        /*
        for(auto row: dp) {
            for(auto col: row) {
                printf("%d ", col);
            }
            printf("\n");
        }
        */
        return dp[0][0];
    }
};


class Solution0 {
public:
    int dfs(vector<vector<int>>& grid, int row, int col, int path) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;   
        
        if(row == nrows or col == ncols) return INT_MAX;
        path+=grid[row][col];
        if(row == nrows-1 and col == ncols-1) return path;
        
        return min(dfs(grid, row+1, col, path), dfs(grid, row, col+1, path));
    }
    int minPathSum(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, 0);
    }
    int dfs2(vector<vector<int>>& grid, int row, int col) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;   
        
        if(row == nrows or col == ncols) return INT_MAX;
        
        if(row == nrows-1 and col == ncols-1) return grid[row][col];
        return grid[row][col] + min(dfs2(grid, row+1, col), dfs2(grid, row, col+1));
    }
    int minPathSum2(vector<vector<int>>& grid) {
        return dfs2(grid, 0,0);
    }
    int minPathSum1(vector<vector<int>>& grid) {
        /*
        grid = {{5,4,2,9,6,0,3,5,1,4,9,8,4,9,7,5,1},{3,4,9,2,9,9,0,9,7,9,4,7,8,4,4,5,8},{6,1,8,9,8,0,3,7,0,9,8,7,4,9,2,0,1},{4,0,0,5,1,7,4,7,6,4,1,0,1,0,6,2,8},{7,2,0,2,9,3,4,7,0,8,9,5,9,0,1,1,0},{8,2,9,4,9,7,9,3,7,0,3,6,5,3,5,9,6},{8,9,9,2,6,1,2,5,8,3,7,0,4,9,8,8,8},{5,8,5,4,1,5,6,6,3,3,1,8,3,9,6,4,8},{0,2,2,3,0,2,6,7,2,3,7,3,1,5,8,1,3},{4,4,0,2,0,3,8,4,1,3,3,0,7,4,2,9,8},{5,9,0,4,7,5,7,6,0,8,3,0,0,6,6,6,8},{0,7,1,8,3,5,1,8,7,0,2,9,2,2,7,1,5},{1,0,0,0,6,2,0,0,2,2,8,0,9,7,0,8,0},{1,1,7,2,9,6,5,4,8,7,8,5,0,3,8,1,5},{8,9,7,8,1,1,3,0,1,2,9,4,0,1,5,3,1},{9,2,7,4,8,7,3,9,2,4,2,2,7,8,2,6,7},{3,8,1,6,0,4,8,9,8,0,2,5,3,5,5,7,5},{1,8,2,5,7,7,1,9,9,8,9,2,4,9,5,4,0},{3,4,4,1,5,3,3,8,8,6,3,5,3,8,7,1,3}};
        */
        
        
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;     
        
        for(int j = max(0,ncols-1); j > 0; j--) {
            grid[nrows-1][j-1] += grid[nrows-1][j];
        }

        if(nrows>1 and ncols>1) {
        for(int i = max(0,nrows-2); i >= 0; i--) {
            for(int j = max(0,ncols-1); j >= 0; j--) {
                if(j==ncols-1) grid[i][j] += grid[i+1][j];//min(grid[i+1][j], grid[i][j-1]+grid[i+1][j-1]);
                else if(j==0) grid[i][j] += min(grid[i+1][j], grid[i][j+1]);
                //else grid[i][j] += min({grid[i+1][j], grid[i][j-1]+grid[i+1][j-1], grid[i][j+1]});
                else grid[i][j] += min(grid[i+1][j], grid[i][j+1]);
            }
        }
    }
        /*
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        */
       return grid[0][0];
    }
};