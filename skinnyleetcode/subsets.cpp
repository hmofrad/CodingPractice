/*
 *  https://leetcode.com/problems/subsets/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */



class Solution {
public:
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
    
    vector<vector<int>> subsets(vector<int>& nums) {
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