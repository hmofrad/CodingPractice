/*
 * https://leetcode.com/problems/excel-sheet-column-title/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string convertToTitle(int n) {
        if(n<1) return std::string();

        std::string s;
        while(n) {
            int r = ((n-1)%26);
            n = (n-1)/26;
            s.push_back(r+'A');
        } 
        std::reverse(s.begin(), s.end());
        return s;
    }
};