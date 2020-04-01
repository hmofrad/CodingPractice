/*
 *  https://leetcode.com/problems/projection-area-of-3d-shapes/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
/*

[[2]] means on top of grid cell (0, 0), there is a block with size 2.
[[1,2],[3,4]] means on top of grid cell (0, 0), there is a block with size 1.
on top of grid cell (0, 1), there is a block with size 2.
on top of grid cell (1, 0), there is a block with size 3.
on top of grid cell (1, 1), there is a block with size 4.

in example 2, you can see it clearly.
*/
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = (m) ? grid[0].size() : 0;
        for(int i = 0; i < m; i++) {
            int row = 0;
            int col = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j]>0) ans++;
                row = (grid[i][j] > row) ? grid[i][j] : row;
                col = (grid[j][i] > col) ? grid[j][i] : col;
            }
            ans += (row + col);
        }
        return(ans);
    }
};