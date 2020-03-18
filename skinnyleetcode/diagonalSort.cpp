/*
 *  Problem: https://leetcode.com/problems/sort-the-matrix-diagonally/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    void diag_sort(vector<vector<int>>& mat, int i, int j) {
        int curr = mat[i][j];
        i--;
        j--;
        while(i>=0 and j>=0 and mat[i][j]>curr) {
            mat[i+1][j+1] = mat[i][j];
            i--;
            j--;  
        }
        mat[i+1][j+1] = curr;
        
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if(not mat.empty()) {
            int m = mat.size();
            int n = mat[0].size();
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    diag_sort(mat, i, j);
                }
            }
        }
        return(mat);
    }
};