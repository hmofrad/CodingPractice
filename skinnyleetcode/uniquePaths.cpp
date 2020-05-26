/*
 *	https://leetcode.com/problems/unique-paths/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int uniquePaths1(int m, int n) {
        return (m==1 or n==1) ? 1 : uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));
        //for(int j = 0; j < n; j++) {
        //    dp[m-1][j] =2;
        //}
        for(int j = 1; j < n; j++) {
            for(int i = 1; i < m; i++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};