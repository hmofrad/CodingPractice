/*
 *  https://leetcode.com/problems/unique-paths-iii/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    vector<vector<int>> mat;
    int m;
    int n;
    int ans;
    //int total;
    int target_row;
    int target_col;
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = (m) ? grid[0].size() : 0;
        int total = 0;
        int source_row = 0;
        int source_col = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != -1) total++;
                if(grid[i][j] == 1) {
                    source_row = i;
                    source_col = j;
                }
                else if(grid[i][j] == 2) {
                    target_row = i;
                    target_col = j;
                }
            }            
        }
        //printf("%d\n", total);
        mat = grid;
        ans = 0;
        dfs(source_row, source_col, total);
        return(ans);
    }
    void dfs(int row, int col, int total) {
        //printf("%d %d %d\n", row, col, total);
        //if(row < 0 or row >= m) return;
        //if(col < 0 or col >= n) return;    
        total--;
        if(total < 0) return;
        
        if((target_row == row) and (target_col == col)) {
            if(total == 0) ans++;
            //printf("ans=%d\n", ans);
            return;
        }
        
        mat[row][col] = 3;
        
        if ((row-1 >= 0) and (mat[row-1][col] % 2 == 0)) dfs(row-1, col, total);
        if ((row+1 < m) and (mat[row+1][col] % 2 == 0)) dfs(row+1, col, total);
        if ((col-1 >= 0) and (mat[row][col-1] % 2 == 0)) dfs(row, col-1, total);
        if ((col+1 < n) and (mat[row][col+1] % 2 == 0)) dfs(row, col+1, total);
        
        mat[row][col]=0;
        
    }
};
