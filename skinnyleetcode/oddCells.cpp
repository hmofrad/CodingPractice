/*
 *  Problem: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        std::vector<std::vector<int>> grid(n, std::vector<int>(m));
        
        for(auto index: indices) {
            for(int j = 0; j < m; j++) {
                grid[index[0]][j]++;
            }
            for(int i = 0; i < n; i++) {
                grid[i][index[1]]++;
            }
        }
        
        int o = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]%2) o++;
            }
        }
        return(o);
    }
};