/*
 * https://leetcode.com/problems/one-edit-distance/submissions/ 
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.length()<t.length()) { return isOneEditDistance(t, s); }
        if(s.length()-t.length()>1) { return false; }
        int len_s = s.length();
        int len_t = t.length();
        for(int i = 0; i < len_s; i++) {
            if(s[i]!=t[i]) {
                if(len_s==len_t) { return (i+1<len_s and i+1<len_t) ? s.substr(i+1) == t.substr(i+1) : true; }
                else { return  (i+1<len_s) ? s.substr(i+1) == t.substr(i) : true; }
            }
        }
        return false;
        //return len_s == len_t+1;
    }
};