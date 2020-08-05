/*
 * https://leetcode.com/problems/permutations-ii/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    void backtrack(std::vector<int>& nums, std::vector<bool>& visited, std::vector<int> temp, std::vector<std::vector<int>>& ans) {
        int size = nums.size();
        if(temp.size() == size) { ans.push_back(temp); return; }
        
        for(int i = 0; i < size; i++) {
            if(visited[i]) continue;
            if(i and nums[i-1] == nums[i] and not visited[i-1]) continue;
            visited[i]=true;
            temp.push_back(nums[i]);
            backtrack(nums, visited, temp, ans);
            temp.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {        
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;
        std::vector<bool> visited(nums.size());
        backtrack(nums, visited, std::vector<int>(), ans);
        
        return ans;
    }
};

class Solution0 {
public:
    void backtrack(std::vector<int>& nums, std::unordered_set<int>& visited, std::vector<int> temp, std::set<std::vector<int>>& set) {
        int size = nums.size();
        if(temp.size() == size) { set.insert(temp); return; }
        
        for(int i = 0; i < size; i++) {
            if(visited.insert(i).second == false) { continue; }
            temp.push_back(nums[i]);
            backtrack(nums, visited, temp, set);
            temp.pop_back();
            visited.erase(i);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {        
        std::set<std::vector<int>> set;
        std::unordered_set<int> visited;
        backtrack(nums, visited, std::vector<int>(), set);
        std::vector<std::vector<int>> ans(set.begin(), set.end());
        return ans;
    }
};