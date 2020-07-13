/*
 * https://leetcode.com/problems/24-game/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    
    bool judgePoint24(vector<int>& nums) {
        vector<double> nums1(nums.begin(), nums.end());
        return solve(nums1);
    }
    
    bool solve(std::vector<double>& nums) {
        if(nums.empty()) { return false; }
        if(nums.size() == 1) { return fabs(nums[0]-24) < 1e-6; }
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums.size(); j++) {
                if(i != j) {
                    std::vector<double> nums2;
                    for(int k = 0; k < nums.size(); k++) {
                        if(k!=i and k!=j) { nums2.push_back(nums[k]); }
                    }
                    
                    for(int k = 0; k < 4; k++) {
                        if(k<2 and j>i) { continue; }
                        else if(k == 0) { nums2.push_back(nums[i] + nums[j]); }
                        else if(k == 1) { nums2.push_back(nums[i] * nums[j]); }
                        else if(k == 2) { nums2.push_back(nums[i] - nums[j]); }
                        else if(k == 3) {
                            if(nums[j] != 0) { nums2.push_back(nums[i]/nums[j]); }
                            else { continue; }
                        }
                        if(solve(nums2)) { return true; }
                        else { nums2.pop_back(); }
                    }
                }
            }
        }
        return false;
    }
};