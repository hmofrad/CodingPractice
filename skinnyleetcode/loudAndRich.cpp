/*
 *  https://leetcode.com/problems/loud-and-rich/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<int> ans;
    std::unordered_map<int, std::vector<int>> richer0;
    
    int dfs(int i, std::vector<int>& quiet) {
        if(ans[i]>=0) return ans[i];
        ans[i]=i;
        for(int j: richer0[i]) { if(quiet[ans[i]] > quiet[dfs(j, quiet)]) ans[i]=ans[j]; }
        return ans[i];
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        for(std::vector<int>& rich: richer) 
            richer0[rich[1]].push_back(rich[0]);
        ans.resize(quiet.size(), -1);
        for(int i = 0; i < quiet.size(); i++) dfs(i, quiet);
        return ans;
    }
};