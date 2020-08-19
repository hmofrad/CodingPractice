/*
 * https://leetcode.com/problems/implement-strstr/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int strStr0(string haystack, string needle) {
        if(needle.empty()) { return 0; }
        else if(haystack.empty()) { return -1; }
        int len_h = haystack.length();
        int len_n = needle.length();
        for(int i = 0; i <= len_h-len_n; i++) {
            std::string t = haystack.substr(i, len_n);
            if(t == needle) { return i; }
        }
        return -1;
    }
    
    int strStr(string haystack, string needle) {
        if(needle.empty()) { return 0; }
        else if(haystack.empty()) { return -1; }

        int len_h = haystack.length();
        int len_n = needle.length();
        int i = 0, j = 0, a = 0;
        while(i<len_h) {
            if(haystack[i] == needle[j]) { i++; j++;
            }
            else { j=0; i=++a;
            }
            if(j==len_n) { return a; }
        }
        return -1;
    }
};