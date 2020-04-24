/*
 *  https://leetcode.com/problems/surface-area-of-3d-shapes/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        
        int ans = 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(grid[i][j]) {
                    ans += 2;
                    ans += (j-1 >= 0) ? max(grid[i][j]-grid[i][j-1], 0) : grid[i][j];
                    ans += (j+1 < ncols) ? max(grid[i][j]-grid[i][j+1], 0) : grid[i][j];
                    ans += (i-1 >= 0) ? max(grid[i][j]-grid[i-1][j], 0) : grid[i][j];
                    ans += (i+1 < nrows) ? max(grid[i][j]-grid[i+1][j], 0) : grid[i][j];
                }
            }
        }
        return ans;
    }
};