/*
 *  Problem: https://leetcode.com/problems/to-lower-case/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string toLowerCase(string str) {
        int d = 'A'- 'a';
        for(auto& c: str) {
            if(c >= 'A' and c <= 'Z') {
                c -= d;
            }
        }
        return(str);
    }
};