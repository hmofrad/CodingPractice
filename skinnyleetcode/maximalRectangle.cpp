/*
 * https://leetcode.com/problems/maximal-rectangle/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int nrows = matrix.size();
        int ncols = nrows ? matrix[0].size() : 0;
        if(nrows == 0 or ncols == 0) { return 0; }
        std::vector<std::vector<int>> dp(nrows, std::vector<int>(ncols+1));
        int maxarea = 0;
        
        for(int i = 0; i < nrows; i++) {
            for(int j = 1; j <= ncols; j++) {
                if(matrix[i][j-1] == '1') {
                    dp[i][j] = dp[i][j-1] + 1;
                    int width = dp[i][j];
                    for(int k = i; k >= 0; k--) {
                        width = min(width, dp[k][j]);
                        maxarea = max(maxarea, width *(i-k+1));
                    }
                }
            }
        }
        return maxarea;
    }
};