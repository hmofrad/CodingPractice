/*
 * https://leetcode.com/problems/range-sum-query-2d-immutable/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */
class NumMatrix {
public:
    int nrows = 0;
    int ncols = 0;
    std::vector<std::vector<int>> sums;
    NumMatrix(vector<vector<int>>& matrix) {
        nrows = matrix.size();
        ncols = nrows ? matrix[0].size() : 0;
        
        sums.resize(nrows+1);
        for(std::vector<int>& sum: sums) { sum.resize(ncols+1); }
        
        for(int i = 1; i <= nrows; i++) {
            for(int j = 1; j <= ncols; j++) { sums[i][j] = matrix[i-1][j-1] + 
                                                           sums[i-1][j]     + 
                                                           sums[i][j-1]     -
                                                           sums[i-1][j-1]; }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        //return 0;
        return sums[row2+1][col2+1] -
               sums[row2+1][col1]   -
               sums[row1][col2+1]   +
               sums[row1][col1];

    }
};


class NumMatrix0 {
public:
    int nrows = 0;
    int ncols = 0;
    std::vector<std::vector<int>> rows;
    NumMatrix0(vector<vector<int>>& matrix) {
        nrows = matrix.size();
        ncols = nrows ? matrix[0].size() : 0;
        
        rows.resize(nrows);
        for(std::vector<int>& row: rows) { row.resize(ncols+1); }
        
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) { rows[i][j+1] = rows[i][j] + matrix[i][j]; }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++) { sum += rows[i][col2+1]-rows[i][col1]; }
        return sum; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */