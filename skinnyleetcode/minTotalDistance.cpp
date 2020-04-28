/*
 *  https://leetcode.com/problems/best-meeting-point/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int nrows = grid.size();
        int ncols = (nrows) ? grid[0].size() : 0;
        std::vector<int> rows;
        std::vector<int> cols;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(grid[i][j]) rows.push_back(i);
            }
        }
        
        for(int j = 0; j < ncols; j++) {
            for(int i = 0; i < nrows; i++) {
                if(grid[i][j]) cols.push_back(j);
            }
        }
        
        int row_dist = 0;
        int row = rows[rows.size()/2];
        for(int r: rows) row_dist += abs(r-row);
        
        int col_dist = 0;
        int col = cols[cols.size()/2];
        for(int c: cols) row_dist += abs(c-col);
        
        return row_dist + col_dist;
    }
    
    int minTotalDistance1(vector<vector<int>>& grid) {
        int nrows = grid.size();
        int ncols = (nrows) ? grid[0].size() : 0;
        std::vector<std::vector<int>> positions;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(grid[i][j]) positions.push_back({i,j});
            }
        }
        int npositions = positions.size();
        int min_distance = INT_MAX;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                int distance = 0;
                for(int k = 0; k < npositions; k++) {
                    distance += abs(positions[k][0]-i) + abs(positions[k][1]-j);
                }
                min_distance = min(distance, min_distance);
            }
        }
        
        
        return min_distance;
    }
};