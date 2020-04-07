/*
 *  https://leetcode.com/problems/toeplitz-matrix/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        bool tf = true;
        int m = matrix.size();
        int n = (m) ? matrix[0].size() : 0;
        
        for(int i = 0; i < m-1; i++) {
            for(int j = 0; j < n-1; j++) {
                if(matrix[i][j] != matrix[i+1][j+1]) {tf = false; break;}
            }
            if(tf == false) break;
        }
        return(tf);
    }
};