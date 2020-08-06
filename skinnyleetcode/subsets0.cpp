/*
 * https://leetcode.com/problems/subsets/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    void backtrack(std::vector<int>& nums, int index, std::vector<int> temp, std::vector<std::vector<int>>& ans) {
        ans.push_back(temp);
        int size = nums.size();
        for(int i = index; i < size; i++) {
            temp.push_back(nums[i]);
            backtrack(nums, i+1, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, 0, std::vector<int>(), ans);
        return ans;
    }
};



























class Solution0 {
public:
    vector<vector<int>> ans;
    void backtrack(std::vector<int>& nums, int m, int n, int index, std::vector<int> temp){//, std::unordered_set<int> visited) {
        if(temp.size() == n) {ans.push_back(temp); }
        if(n == m) return;
        
        int size = nums.size();
        for(int i = index; i < size; i++) {
           // if(visited.count(nums[i])) continue;
            //visited.insert(nums[i]);
            temp.push_back(nums[i]);
            //if(temp.size()==n+1) ans.push_back(temp);
            backtrack(nums, m, n+1, i+1, temp);//, visited);
            temp.pop_back();
            //visited.erase(nums[i]);
        }
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        //std::unordered_set<int> visited;
        backtrack(nums, nums.size(), 0, 0, std::vector<int>());//, visited);
        return ans;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    vector<vector<int>> permutations1(vector<int>& nums) {
        vector<vector<int>> perms;
        perms.push_back(std::vector<int>());
        
        for(int num: nums) {
            vector<vector<int>> perms1;
            for(std::vector<int> p: perms) {
                std::vector<int> temp;
                temp.insert(temp.begin(), p.begin(), p.end());
                temp.push_back(num);
                perms1.push_back(temp);
            }
            for(std::vector<int> p: perms1) {
                perms.push_back(p);
            }
        }
        return perms;
    }
    vector<vector<int>> permutations(vector<int>& nums) {
        vector<vector<int>> perms;
        if(nums.empty()) {perms.push_back(std::vector<int>()); return perms;}
        
        int first = nums.front();
        nums.erase(nums.begin());
        
        vector<vector<int>> perms1 = permutations(nums);
        for(std::vector<int> p: perms1) {
            int size = p.size();
            std::sort(p.begin(), p.end());
            if(std::find(perms.begin(), perms.end(), p) == perms.end()) perms.push_back(p);
            for(int i = 0; i <= size; i++) {
                std::vector<int> temp;
                temp.insert(temp.begin(), p.begin(), p.begin()+i);
                temp.push_back(first);
                temp.insert(temp.end(), p.begin()+i, p.end());
                std::sort(temp.begin(), temp.end());
                if(std::find(perms.begin(), perms.end(), temp) == perms.end()) perms.push_back(temp);
            }
        }
        
        return perms;
    }
    std::vector<std::vector<int>> perms;
    void backtrack(std::vector<int> nums, std::vector<int> temp, int index) {
        //printf("%d %d %d\n", n, k, index);
        //if(temp.size() == k) { perms.push_back(temp); return; }
        perms.push_back(temp);
        int n = nums.size();
        for(int i = index; i < n; i++) {
            temp.push_back(nums[i]);
            backtrack(nums, temp, i+1);
            //printf("%d ?\n", temp.size());
            temp.pop_back();
            //printf("1.%d ?\n", temp.size());
        }
    }
    
    vector<vector<int>> subsets0(vector<int>& nums) {
        //vector<vector<int>> perms = permutations(nums);
        //vector<vector<int>> perms = permutations1(nums);
        
        std::vector<int> temp;
        int n = nums.size();
        //for(int k = 0; k < n+1; k++)
        backtrack(nums, temp, 0);
        
        /*
        for(auto perm: perms) {
            for(auto p: perm) {
                printf("%d,", p);
            }
            printf("\n");
        }
        */

        return perms;
    }
    
};