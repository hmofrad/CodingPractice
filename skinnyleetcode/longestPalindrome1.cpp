/*
 *  https://leetcode.com/problems/longest-palindromic-substring/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::string ans;
    void extend(std::string s, int left, int right) {
        int length = s.length();
        while(left>=0 and right<length and s[left]==s[right]) {left--; right++;}
        
        if(ans.length() < right-left-1) ans = s.substr(left+1, right-left-1);
    }
    string longestPalindrome(string s) {
        int len = s.length();
        if(len<2) return s;
        
        for(int i = 0; i < len-1; i++) {
            extend(s, i, i);
            extend(s, i, i+1);
        }
        return ans;
    }
    string longestPalindrome3(string s) {
        if(s.empty()) return s;
        
        int l = s.length();
        std::vector<std::vector<bool>> dp(l, std::vector<bool>(l));
        
        for(int i = 0; i < l; i++) {
            dp[i][i]=true;
            if(i<l-1) {dp[i][i+1]=s[i]==s[i+1];}
        }
        
        for(int i = l-3; i >= 0; i--) {
            for(int j = i+2; j < l; j++) {
                dp[i][j]= dp[i+1][j-1] and (s[i]==s[j]);
                
            }
        }
        
        int mx = 0;
        std::string mx_str;
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < l; j++) {
                int m = j-i+1;
                if(dp[i][j]==true and m>mx) {mx = m; mx_str = s.substr(i, m);}
            }
        }
        return mx_str;
    }
    
    
    bool ispalindrome(std::string s) {
        int l = s.length();
        for(int i = 0; i < l/2; i++) if(s[i]!=s[l-i-1]) return false;
        return true;
    }
    
    string longestPalindrome2(string s) {
        if(s.empty() or ispalindrome(s)) return s;
        
        std::string left = s.substr(1);
        std::string right = s.substr(0, s.size()-1);
        
        std::string l= longestPalindrome(left), r= longestPalindrome(right);
        return l.length() > r.length() ? l : r;
    }
    
    
    string longestPalindrome1(string s) {
        int len = s.length();
        std::string longest;
        for(int i = 0; i < len; i++) {
            for(int j = i; j < len; j++) {
                std::string t = s.substr(i, j-i+1);
                longest = ispalindrome(t) and t.length() > longest.length() ? t : longest;
            }
        }
        return longest;
    }
};