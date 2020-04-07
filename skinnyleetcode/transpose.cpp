/*
 *  https://leetcode.com/problems/transpose-matrix/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int nrows = A.size();
        int ncols = (nrows) ? A[0].size() : 0;
        if(nrows == ncols) {
            for(int i = 0; i < nrows; i++) {
                for(int j = i; j < ncols; j++) {
                    if(i!=j)std::swap(A[i][j], A[j][i]);
                }
            }
            return(A);
        }
        
        std::vector<std::vector<int>> B(ncols, std::vector<int>(nrows, 0));
        
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                B[j][i] = A[i][j];
            }
        }
        
        return(B);
        
    }
};
