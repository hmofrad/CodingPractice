/*
 * https://leetcode.com/problems/valid-palindrome-ii/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool is_palindrome_range(std::string s, int i, int j) {
        for(int k = i; k <= i+(j-i)/2; k++) {
            if(s[k] != s[j-k+i]) return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int l = s.length();
        for(int i = 0; i < l/2; i++) {
            int j = l-1-i;
            if(s[i] != s[j]) {
                return is_palindrome_range(s, i+1, j) or 
                       is_palindrome_range(s, i, j-1);
            }
        }
        return true;
    }
    
    bool is_palindrome(std::string s) {
        std::string t(s);
        std::reverse(t.begin(), t.end());
        return t==s;
    }
    
    bool validPalindrome1(string s) {
        for(int i = 0; i < s.length(); i++) {
            std::string t=s.substr(0,i);
            t += s.substr(i+1);
            //printf("%s\n", t.c_str());
            if(is_palindrome(t)) return true;
        }
        return false;
    }
};