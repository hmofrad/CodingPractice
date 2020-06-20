/*
 * https://leetcode.com/problems/wildcard-matching/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        //s="acdcb";
        //p="a*c?b";
        int i = 0, j = 0;
        int m = s.length(), n = p.length();
        int last_i = -1, starj = -1;
        while(i<m) {
            if(j<n and (s[i]==p[j] or p[j] == '?')) { i++; j++; }
            else if(j<n and p[j] == '*') { starj=j++; last_i=i; }
            else if(starj != -1) { j=starj+1; i=++last_i; }
            else {return false;}
        }
        while(j<n and p[j]=='*') { j++; }
        return j==n;
    }
    bool isMatch1(string s, string p) {
        if(s.empty()) {
            if((p.empty() or (p.size()==1 and p.front()=='*'))) return true;
            else return false;
        }
        if(p.empty()) {
            if(s.empty()) return true;
            else return false;
        }
        
        int len_s = s.length();
        int len_p = p.length();
        int j = 0;
        char lookahead = '\0';
        for(int i = 0; i < len_s; i++) {
            char c_s = s[i];
            char c_p = (j<len_p) ? p[j] : '\0';
            //printf("%d %c %c\n", i, c_s, c_p);
            if(c_p == '*') {
                char l_s = (i+1<len_s) ? s[i+1] : '\0';
                char l_p = (j+1<len_p) ? p[j+1] : '\0';
                //printf("%c %c\n", l_s, l_p);
                if(l_s == '\0' or l_p == '\0') continue;
                else if(l_s==l_p) {j++;}
                else if(c_s==l_p) {i--; j++;}
            }
            else if((c_p == '?') or (c_p == c_s)) { j++; }
            else if((c_p != c_s) or (c_p == '\0')) { return false; }
        }
        
        while(j<len_p and p[j]=='*') { j++; }
        
        return j==len_p;
    }
};