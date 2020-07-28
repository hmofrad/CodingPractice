/*
 * https://leetcode.com/problems/positions-of-large-groups/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        if(S.empty()) {return std::vector<std::vector<int>>(); }
        std::vector<std::vector<int>> ans;
        int len = S.length();
        int i = 1, j = 0;
        for(; i < len; i++) {
            if(S[i]!=S[j]) { 
                if(i-j>=3) { ans.push_back({j,i-1}); }
                j=i;
            }
        }
        if(i-j>=3) { ans.push_back({j,i-1}); }
        return ans;
    }
};