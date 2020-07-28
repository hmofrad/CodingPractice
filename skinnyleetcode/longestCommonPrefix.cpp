/*
 * https://leetcode.com/problems/longest-common-prefix/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) { return std::string(); }
        int size = strs.size();
        int ans = 0;
        int i = 0, j = 0;
        while(j < strs[0].size()) {
            bool b = false;
            char c = strs[i][j];
            for(int i = 1; i < size; i++) {
                if(j>strs[i].size() or strs[i][j] != c) { b=true; } 
            }
            if(b) { break; }
            else { j++; }
        }
        return strs[0].substr(0, j);
    }
};