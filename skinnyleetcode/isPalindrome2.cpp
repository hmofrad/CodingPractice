/*
 * https://leetcode.com/problems/valid-palindrome/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:

    bool is_digit(char c) {
        return c>='0' and c<='9';
    }
    bool is_alpha(char c) {
        return (c>='a' and c<='z') or (c>='A' and c<='Z');
    }
    bool is_alphanumeric(char c) {
        return is_digit(c) or is_alpha(c);
    }
    char to_lower(char c) {
        return is_digit(c) ? c : (c>='a' and c<='z') ? c : c-'A'+'a';
    }
    bool is_empty(std::string s) {
        for(char c: s) {
            if(is_alphanumeric(c)) return false;
        }
        return true;
    }
    
    void preprocess(std::string& s) {
        int j = 0;
        int len = s.length();
        for(int i = 0; i < len; i++) {
            char c = s[i];
            if(is_alphanumeric(c)) {
                if(is_alpha(c)) c=to_lower(c);
                s[j++]=c;
            }
        }
        s.erase(s.begin()+j, s.end());
    }
    
    bool isPalindrome1(string s) {
        preprocess(s);
        std::string t(s); std::reverse(t.begin(), t.end());
        return s==t;
    }
    
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;
        bool empty = true;
        while(left<right) {
            while(left<right and not is_alphanumeric(s[left])) left++;
            while(left<right and not is_alphanumeric(s[right])) right--;
            if((left<right) and (to_lower(s[left]) != to_lower(s[right]))) return false;
            left++;
            right--;
        }
        return true;
    }
};