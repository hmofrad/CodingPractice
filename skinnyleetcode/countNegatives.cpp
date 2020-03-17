/*
 *  Problem: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = (m) ? grid[0].size() : 0;
        int k = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] < 0) {
                    k += n - j;
                    break;
                }
            }
        }
        return(k);
    }
};