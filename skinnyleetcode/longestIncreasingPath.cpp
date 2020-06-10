/*
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int row, int col, std::vector<std::vector<int>>& cache) {
        if(cache[row][col]) return cache[row][col];
        int nrows = matrix.size();
        int ncols = nrows ? matrix[0].size() : 0;
        int longest_path = 1;
        std::vector<int> r={1,-1,0,0};
        std::vector<int> c={0,0,1,-1};
        for(int k = 0; k < 4; k++) {
            int r0 = row+r[k];
            int c0 = col+c[k];
            if(r0<0 or r0>=nrows or c0<0 or c0>=ncols or matrix[r0][c0]<=matrix[row][col]) continue;
            int length = 1 + dfs(matrix, r0, c0, cache);
            longest_path = max(longest_path, length);
        }
        cache[row][col]=longest_path;
        return longest_path;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int nrows = matrix.size();
        int ncols = nrows ? matrix[0].size() : 0;
        std::vector<std::vector<int>> cache(nrows, std::vector<int>(ncols));
        int longest_path = 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                longest_path = max(longest_path, dfs(matrix, i, j, cache));;
            }
        }
        return longest_path;
    }
    
    
    int dfs1(vector<vector<int>>& matrix, int row, int col, int last, int path_sum) {
        int nrows = matrix.size();
        int ncols = nrows ? matrix[0].size() : 0;
        if(row<0 or row>=nrows or col<0 or col>=ncols or matrix[row][col]<=last or matrix[row][col] == INT_MIN) return path_sum;
        
        int value = matrix[row][col];
        matrix[row][col]=INT_MIN;
        
        int longest_path = max({dfs1(matrix, row+1, col, value, path_sum+1),
                                dfs1(matrix, row-1, col, value, path_sum+1),
                                dfs1(matrix, row, col+1, value, path_sum+1),
                                dfs1(matrix, row, col-1, value, path_sum+1)});
        matrix[row][col]=value;
        return longest_path;
    }

    int longestIncreasingPath1(vector<vector<int>>& matrix) {
        int nrows = matrix.size();
        int ncols = nrows ? matrix[0].size() : 0;
        int longest_path = 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                longest_path = max({longest_path, 
                                    dfs1(matrix, i+1, j, matrix[i][j], 1),
                                    dfs1(matrix, i-1, j, matrix[i][j], 1),
                                    dfs1(matrix, i, j+1, matrix[i][j], 1),
                                    dfs1(matrix, i, j-1, matrix[i][j], 1)});
            }
        }
        return longest_path; 
    }
};