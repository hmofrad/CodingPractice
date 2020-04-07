/*
 *  https://leetcode.com/problems/path-with-maximum-gold/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    vector<vector<int>> my_grid;
    vector<vector<bool>> visited;
    int m;
    int n;
    int mine(int row, int col) {
        if((row < 0 or row >= m or col < 0 or col >= n) or 
           (my_grid[row][col] == 0) or
           (visited[row][col])) return 0;
        
        visited[row][col] = true;
        int gain = my_grid[row][col];
        
        
        std::vector<int> mined(4);
        mined[0] = mine(row-1, col);
        mined[1] = mine(row+1, col);
        mined[2] = mine(row, col-1);
        mined[3] = mine(row, col+1);
        visited[row][col] = false;
        int max_value = *std::max_element(mined.begin(), mined.end());
        return(gain + max_value);
        
        //return(max(gain + mined[0], max(gain + mined[1], ), );
    }
    
    
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = (m) ? grid[0].size() : 0;
        my_grid = grid;
        visited.resize(m);
        for(std::vector<bool>& row: visited) row.resize(n);
        
        int max_value = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(my_grid[i][j]) {
                    int value = mine(i, j);
                    max_value = (value > max_value) ? value : max_value;
                }
            }
        }
        
        return(max_value);    
    }
};