/*
 *  Problem: https://leetcode.com/problems/split-a-string-in-balanced-strings/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    int balancedStringSplit(string s) {
        int b = 0;
        int p = 0;
        for(auto c: s) {
            if(c == 'R') p++;
            if(c == 'L') p--;
            if(not p) b++;
        }
        return(b);
    }
};