/*
 *	https://leetcode.com/problems/combination-sum/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& candidates, std::vector<int> temp, int target, int index) {
        if(target == 0) { ans.push_back(temp); return; }
        else if (target<0) return;
        
        int size = candidates.size();
        for(int i = index; i < size; i++) {
            temp.push_back(candidates[i]);
            backtrack(candidates, temp, target-candidates[i], i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        backtrack(candidates, std::vector<int>(), target, 0);
        return ans;
    }
    
    
    std::vector<std::vector<int>> backtrack(vector<int>& candidates, std::map<int,int> temp, int sum, int target) {
        std::vector<std::vector<int>> anses;
        if(sum == target) {
            std::vector<int> a;
            for(auto t: temp) {
                for(int i = 0; i < t.second; i++) a.push_back(t.first);
            }
            anses.push_back(a);
            return anses;
        }
        else if (sum>target) return anses;
        
        int size = candidates.size();
        for(int i = 0; i < size; i++) {
            temp[candidates[i]]++;
            std::vector<std::vector<int>> ans = backtrack(candidates, temp, sum+candidates[i], target);
            temp[candidates[i]]--;
            for(std::vector<int>& a: ans) {
                //anses.push_back(a);
                //std::sort(a.begin(), a.end());
                if(std::find(anses.begin(), anses.end(), a) == anses.end()) anses.push_back(a);
            }
            //anses.insert(anses.end(), ans.begin(), ans.end());
        }
        return anses;        
    }
    vector<vector<int>> combinationSum1(vector<int>& candidates, int target) {
        return backtrack(candidates, std::map<int, int>(), 0, target);
    }
    
    
    vector<vector<int>> backtrack1(vector<int>& candidates, std::vector<int> temp, int sum, int target) {
        std::vector<std::vector<int>> anses;
        //int sum = std::accumulate(temp.begin(), temp.end(),0);
        if(sum==target) {anses.push_back(temp); return anses;}
        else if (sum>target) return anses;
        
        int size = candidates.size();
        for(int i = 0; i < size; i++) {
            temp.push_back(candidates[i]);
            std::vector<std::vector<int>> ans = backtrack1(candidates, temp, sum+candidates[i], target);
            temp.pop_back();
            for(std::vector<int>& a: ans) {
                std::sort(a.begin(), a.end());
                if(std::find(anses.begin(), anses.end(), a) == anses.end()) anses.push_back(a);
            }
            //anses.insert(anses.end(), ans.begin(), ans.end());
        }
        return anses;        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        return backtrack1(candidates, std::vector<int>(), 0, target);
    }
};