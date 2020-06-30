/*
 * https://leetcode.com/problems/combination-sum-ii/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::set<vector<int>> set;
    vector<vector<int>> ans;
    void backtrack(vector<int>& candidates, int target, int index, std::vector<int> temp) {
        if(target == 0) { if(set.insert(temp).second) ans.push_back(temp); return; }
        else if(target<0) { return ; }
        if(index == candidates.size()) {return ; }
        int size = candidates.size();
        for(int i = index; i < size; i++) {
            int value = candidates[i];
            temp.push_back(value);
            backtrack(candidates, target-value, i+1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, std::vector<int>());
        return ans;
    }
};	