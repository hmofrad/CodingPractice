/*
 * https://leetcode.com/problems/regular-expression-matching/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:

    
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        std::vector<std::vector<bool>> dp(m+1, std::vector<bool>(n+1, false));
        dp[0][0]=true;
        for(int i = 0; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') { dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')); } 
                else { dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.'); }
            }
        }
       return dp[m][n];
    }
};