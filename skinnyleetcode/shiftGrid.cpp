/*
 *  https://leetcode.com/problems/shift-2d-grid/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    
    
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int nrows = grid.size();
        int ncols = (nrows) ? grid[0].size() : 0;
        for(int l = 0; l < k; l++) {
        int temp = grid[nrows-1][ncols-1];
        for(int i = nrows-1; i >= 0; i--) {
            int temp = 0;
            if(i-1>=0)
                temp = grid[i-1][ncols-1];
            for(int j = ncols-1; j > 0; j--) {
                grid[i][j] = grid[i][j-1];
            }
            if(i-1>=0)
                grid[i][0] = temp;
        }
        grid[0][0] = temp;
        }
        return(grid);
    }
};