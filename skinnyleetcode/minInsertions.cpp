/*
 *  https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int recur(std::vector<std::vector<int>>& mem, std::string s, int left, int right) {
        if(left >= right) return 0;
        if(mem[left][right] != -1) return mem[left][right];
        return mem[left][right] = s[left]==s[right] ? recur(mem, s, left+1, right-1) : 1 + 
            min(recur(mem, s, left+1, right), recur(mem, s, left, right-1));
    }
    int minInsertions1(string s) {
        int len = s.length();
        std::vector<std::vector<int>> mem(len, std::vector<int>(len,-1));
        return recur(mem, s, 0, len-1);
    }
    
    int minInsertions1(std::string s) {
        int len = s.length();
        std::vector<std::vector<int>> dp(len+1, std::vector<int>(len+1));
        
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len; j++){
                dp[i+1][j+1]= s[i]==s[len-1-j] ? dp[i][j]+1 : max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return len-dp[len][len];
    }
    
    int minInsertions(std::string s) {
        int len = s.length();
        std::vector<std::vector<int>> dp(len+1, std::vector<int>(len+1));
        
    }
    
};