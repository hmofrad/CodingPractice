/*
 *  https://leetcode.com/problems/palindromic-substrings/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        std::vector<std::vector<bool>> dp(len, std::vector<bool>(len));
        int count = 0;
        
        for(int i = 0; i < len; i++) {
            dp[i][i] = true;
            count++;
        }
        
        for(int i = 0; i < len-1; i++) {
            if(s[i] == s[i+1]) {dp[i][i+1] = true; count++;}
        }
        
        for(int i = 2; i < len; i++) {
            for(int j = 0; j < len-i; j++) {
                int k = i+j;
                printf("s[%d]=%c s[%d]=%c, k=%d dp[%d][%d]=%d\n", i, s[i], j, s[j], k, j+1, k-1, dp[j+1][k-1]==true);
                if((s[j] == s[k]) and (dp[j+1][k-1])) {dp[j][k] = true; count++;}
            }
        }
        
        return count;
        
    }
    bool isPalindrome(std::string t) {
        int length = t.length();
        for(int i = 0; i < length/2; i++) {
            if(t[i] != t[length-1-i]) return false;
        }
        return true;
    }
    int countSubstrings1(string s) {
        std::unordered_map<std::string, bool> valid;
        std::unordered_map<std::string, bool> invalid;
        int len = s.length();
        int count = 0;
        for(int i = 0; i < len; i++) {
            for(int j = i; j < len; j++) {
                std::string t = s.substr(i, len-j);
                if(valid.count(t)) count++;
                else if(invalid.count(t)) continue;
                else if(isPalindrome(t)) {valid[t]=true; count++;}
                else invalid[t]=true;
            }
        }
        
        //for(auto m: map) {
          //  if(isPalindrome(m.first))  count += m.second;
            //printf("%s %d %d\n", m.first.c_str(), m.second, isPalindrome(m.first));
        //}
        return count;
    }
};