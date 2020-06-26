/*
 * https://leetcode.com/problems/set-matrix-zeroes/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nrows = matrix.size();
        int ncols = nrows ? matrix[0].size() : 0;
        bool firstcol = false;
        for(int i = 0; i < nrows; i++) {
            if(matrix[i][0]==0) { firstcol=true; }
            for(int j = 1; j < ncols; j++) {
                if(matrix[i][j]==0) {matrix[i][0]=0; matrix[0][j]=0;}
            }
        }
        for(int i = 1; i < nrows; i++) {
            for(int j = 1; j < ncols; j++) {
                if(matrix[i][0]==0 or matrix[0][j]==0) matrix[i][j]=0;
            }
        }
        
        if(matrix[0][0]==0) {
            for(int j = 0; j < ncols; j++) { matrix[0][j]=0; }    
        }
        
        if(firstcol) {
            for(int i = 0; i < nrows; i++) {
                matrix[i][0]=0;
            }
        }
    }
    
    
    void setZeroes2(vector<vector<int>>& matrix) {
        std::unordered_set<int> cols;
        int nrows = matrix.size();
        int ncols = nrows ? matrix[0].size() : 0;
        for(int i = 0; i < nrows; i++) {
            bool zero = false;
            for(int j = 0; j < ncols; j++) {
                if(matrix[i][j]==0) { 
                    cols.insert(j);
                    zero = true;
                    //if(zero==-1) zero=j;
                }
                //else if(zero != -1) {matrix[i][j]=0;}
            }
            if(zero) {
                for(int j = 0; j < ncols; j++) { matrix[i][j]=0; }
            }
        }
        
        for(auto c: cols) {
            for(int i = 0; i < nrows; i++) {
                matrix[i][c]=0;
            }
        }
        
    }
    
    
    void zeros(vector<vector<int>>& matrix, int row, int col) {
        int nrows = matrix.size();
        int ncols = nrows ? matrix[0].size() : 0;
        for(int i = 0; i < nrows; i++) { matrix[i][col]=0; }
        for(int j = 0; j < ncols; j++) { matrix[row][j]=0; }
    }
    void setZeroes1(vector<vector<int>>& matrix) {
        std::vector<std::pair<int, int>> pairs;
        int nrows = matrix.size();
        int ncols = nrows ? matrix[0].size() : 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(matrix[i][j] == 0) pairs.push_back({i,j});
            }
        }
        
        for(std::pair<int, int>& pair: pairs) {zeros(matrix, pair.first, pair.second);}
        
    }
};	