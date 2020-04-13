/*
 *  https://leetcode.com/problems/max-area-of-island/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    int search2(vector<vector<int>>& grid, int row, int col) {
        int nrows = grid.size();
        int ncols = (nrows) ? grid[0].size() : 0;
        
        if((row<0 or row>=nrows) or (col<0 or col>=ncols)) return 0;
        
        if(grid[row][col] <= 0) return 0;

        int sum = grid[row][col];
        grid[row][col] = -1;
        sum += search2(grid, row, col-1) + search2(grid, row, col+1) + search2(grid, row-1, col) + search2(grid, row+1, col);
        
        return sum;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        int max_area = 0;
        
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                max_area = max(max_area, search2(grid, i, j));
            }
        }
        return max_area;
    }
    
    
    int search(vector<vector<int>>& grid, int row, int col, std::set<std::pair<int, int>>& visited) {
        int nrows = grid.size();
        int ncols = (nrows) ? grid[0].size() : 0;
        
        if((row<0 or row>=nrows) or (col<0 or col>=ncols)) return 0;
        
        if(grid[row][col] == 0 or visited.count({row, col})) return 0;
        
        visited.insert({row,col});
        int sum = grid[row][col] + search(grid, row, col-1, visited) + search(grid, row, col+1, visited) + search(grid, row-1, col, visited) + search(grid, row+1, col, visited);
        
        return sum;
    }
    
    int maxAreaOfIsland1(vector<vector<int>>& grid) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        int max_area = 0;
        /*
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        */
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                std::set<std::pair<int, int>> visited;
                max_area = max(max_area, search(grid, i, j, visited));
                //printf("%d %d %d\n", i, j, max_area);
            }
        }
        return max_area;
    }
};
