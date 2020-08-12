/*
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    bool backtrack0(std::vector<int>& nums, int index, int target, std::vector<int> temp) {
        if(index<0) { return true; }
        for(int i = 0; i < temp.size(); i++) {
            if(temp[i]+nums[index] <= target) { 
                temp[i] += nums[index]; 
                if(backtrack0(nums, index-1, target, temp)) { return true; }
                temp[i] -= nums[index];
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets0(vector<int>& nums, int k){
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum%k) { return false; }
        int target = sum/k;
        return backtrack0(nums, nums.size()-1, target, std::vector<int>(k));
    }
    
    bool backtrack(std::vector<int>& nums, int index, int target, std::vector<int> temp) {
        if(index<0) { return true; }
        int value = nums[index--];
        for(int i = 0; i < temp.size(); i++) {
            if(temp[i]+value <= target) { 
                temp[i] += value; 
                if(backtrack(nums, index, target, temp)) { return true; }
                temp[i] -= value;
            }
            if(temp[i]==0) { break; }
        }
        return false;
    }    

    bool canPartitionKSubsets(vector<int>& nums, int k){
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum%k) { return false; }
        int target = sum/k;
        
        std::sort(nums.begin(), nums.end());
        int index = nums.size()-1;
        if(nums[index]>target) { return false; }
        while(index>=0 and nums[index]==target) { index--; k--; }
        return backtrack(nums, index, target, std::vector<int>(k));
    }
};