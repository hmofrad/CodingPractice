/*
 *	https://leetcode.com/problems/number-of-distinct-islands/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    void dfs1(std::vector<std::vector<int>>& grid, int row, int col, std::vector<int>& path, int d) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        if(row<0 or row>=nrows or col<0 or col>=ncols or not grid[row][col]) return;
        grid[row][col]=0;
        path.push_back(d);
        dfs1(grid, row+1, col, path, 1), dfs1(grid, row-1, col, path, 2), dfs1(grid, row, col-1, path, 3), dfs1(grid, row, col+1, path, 4);
       path.push_back(0);
    }

    
    int numDistinctIslands(vector<vector<int>>& grid) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        std::set<std::vector<int>> paths;
        
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(grid[i][j]) {
                    std::vector<int> path;
                    dfs1(grid, i, j, path, 0);
                    
                   // for(int p: path) printf("%d ", p); printf("\n");
                    
                    paths.insert(path);
                }
            }
        }
        return paths.size();
    }
    
    
    void dfs(std::vector<std::vector<int>>& grid, int row, int col, std::map<int, std::set<int>>& points) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        if(row<0 or row>=nrows or col<0 or col>=ncols or not grid[row][col]) return;
        grid[row][col]=0;
        points[row].insert(col);
        dfs(grid, row+1, col, points), dfs(grid, row-1, col, points), dfs(grid, row, col-1, points), dfs(grid, row, col+1, points);
       // return;
    }

    int numDistinctIslands1(vector<vector<int>>& grid) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        std::vector<std::map<int, std::set<int>>> points_all;
        
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(grid[i][j]) {
                    std::map<int, std::set<int>> points;
                    dfs(grid, i, j, points);
                    points_all.push_back(points);
                }
            }
        }
        
        return points_all.size(); 
    }
};