/*
 * https://leetcode.com/problems/4sum/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //nums={-3,-2,-1,0,0,1,2,3};
        //target=0;
        std::vector<std::vector<int>> ans; 
        std::sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
        //return twoSum(nums, target, 0);
    }
    
    std::vector<std::vector<int>> kSum(std::vector<int>& nums, int target, int start, int k) {  
        std::vector<std::vector<int>> ans; 
        //std::unordered_set<int> set;
        int size = nums.size();
        if(start == size) return ans;
        
        if(k==2) { return twoSum(nums, target, start); }
        
        for(int i = start; i < size; i++) {
            if(i== start or nums[i-1] != nums[i]) {
                std::vector<std::vector<int>> temp = kSum(nums, target-nums[i], i+1, k-1);
                for(std::vector<int>& t: temp) {
                    t.push_back(nums[i]);
                    ans.push_back(t);
                }
            }
        }
        
        return ans;
    }
    
    std::vector<std::vector<int>> twoSum(std::vector<int>& nums, int target, int start) {
        std::vector<std::vector<int>> ans; 
        int size = nums.size();
        int left = start;
        int right = size-1;
        while(left < right) {
            int sum = nums[left] + nums[right];
            if(sum < target or (left>start and nums[left]==nums[left-1])) { left++; }
            else if(sum > target or (right<size-1 and nums[right]==nums[right+1])) {right--;}
            else { ans.push_back({nums[left++], nums[right--]}); }
        }
        return ans;
    }
};


class Solution0 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        std::set<std::vector<int>> set;
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 1; i < size-2; i++) {
            //if(i and nums[i-1] == nums[i]) continue;
            for(int j = i+1; j < size-1; j++) {
                int left = 0;
                int right = size-1;

                while(left<i and right>j) {
                    int sum = nums[left] + nums[i] + nums[j] + nums[right];
                    std::vector<int> vec = {nums[left], nums[i], nums[j], nums[right]};
                    //if(sum<target or (left))
                    if(sum==target and set.insert(vec).second) { ans.push_back(vec); left++; right--; }
                    else if(sum>target) {right--;}
                    else { left++; }
                }
            }
        }
        return ans;
    }
};