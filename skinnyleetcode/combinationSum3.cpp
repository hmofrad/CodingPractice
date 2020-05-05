/*
 *	https://leetcode.com/problems/combination-sum-iii/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<std::vector<int>> backtrack(int k, int n, int index, std::vector<int> temp) {
        //printf("%d %d %d %d\n", k, n, index, nums.size());
        std::vector<std::vector<int>> ans;
        if(temp.size()==k) {if(std::accumulate(temp.begin(), temp.end(), 0) == n) {ans.push_back(temp);} return ans;}
        //if(temp.size()==k) {ans.push_back(temp); return ans;}
        
        
        for(int i = index; i <= 9; i++) {
            //temp.push_back(nums[i]);
            temp.push_back(i);
            //if((std::accumulate(temp.begin(), temp.end(), 0) == n)))
            std::vector<std::vector<int>> t = backtrack(k, n, i+1, temp);
            if(not t.empty()) ans.insert(ans.end(), t.begin(), t.end());
            temp.pop_back();
        }
        return ans;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<int> nums(k); std::iota(nums.begin(), nums.end(), 1); 
        std::vector<std::vector<int>> ans = backtrack(k, n, 1, std::vector<int>());
        for(std::vector<int>& a: ans) {
            for(int v: a) printf("%d ", v); printf("\n");
        }
        return ans;
    }
};