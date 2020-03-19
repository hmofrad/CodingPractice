/*
 *  Problem: https://leetcode.com/problems/flipping-an-image/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        int n = (m) ? A[0].size() : 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n/2; j++) {
                if(A[i][j] == A[i][n-1-j]) {
                    A[i][j] = not A[i][j];
                    A[i][n-1-j] = not A[i][n-1-j];
                }
            }
            if((n%2)) A[i][n/2] = not A[i][n/2];
        }
        return(A);
    }
};