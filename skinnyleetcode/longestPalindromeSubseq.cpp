/*
 *	https://leetcode.com/problems/longest-palindromic-subsequence/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(n));
        for(int i = 0; i < n; i++) dp[1][i]=1;
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j <= n-i; j++) {
                dp[i][j] = s[j]==s[i+j-1] ? dp[i-2][j+1]+2 : max(dp[i-1][j], dp[i-1][j+1]);
            }
        }
        return dp[n][0];
    }
	
    int dfs(std::string& s, int left, int right, std::vector<std::vector<int>>& mem) {
        if(left>right) return 0;
        if(left==right) return 1;
        if(mem[left][right]) return mem[left][right];
        
        return mem[left][right] = s[left]==s[right] ? dfs(s, left+1, right-1, mem) + 2 : max(dfs(s, left+1, right, mem), dfs(s, left, right-1, mem));
        
    }
    int longestPalindromeSubseq(string s) {
        std::vector<std::vector<int>> mem(s.length(), std::vector<int>(s.length()));
        return dfs(s, 0, s.length()-1, mem);
    }
    int longestPalindromeSubseq2(string s) {
        int len = s.length();
        std::vector<std::vector<int>> dp(len, std::vector<int>(len));
        for(int i = len-1; i >= 0; i--) {
            dp[i][i]=1;
            for(int j = i+1; j < len; j++) {
                if(s[i]==s[j]) { dp[i][j]=dp[i+1][j-1]+2; }
                else { dp[i][j] = max(dp[i+1][j], dp[i][j-1]); }
            }
        }
        return dp[0][len-1];
    }
    int longestPalindromeSubseq1(string s) {
        std::vector<int> m(26);
        for(char c: s) m[c-'a']++;
        int len = 0;
        int odd = 0;
        for(int i = 0; i < 26; i++) {
            if(m[i]%2) {odd=max(odd, m[i]);}
            else len +=m[i];
        }
        return len+odd;
    }
};