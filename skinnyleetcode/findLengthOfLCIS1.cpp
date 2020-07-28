/*
 * https://leetcode.com/problems/longest-continuous-increasing-subsequence/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    
    
    int findLengthOfLCIS1(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;
        int count = 0;
        for(int i = 0; i < size; i++) {
            if(i==0 or nums[i-1] < nums[i]) { ans = max(ans, ++count); }
            else { count = 1; }
        }
        return ans;
    }
    
    int findLengthOfLCIS2(vector<int>& nums) {
        int size = nums.size();
        int j = 0;
        int l = 0;
        for(int i = 0; i < size-1; i++) {
            l = max(l, i-j+1);
            if(nums[i+1]<=nums[i]) {
                j=i+1;
            }
        }
        l = max(l, size-j);
        return l;
    }
    
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        
        int size = nums.size();
        int j = 0;
        int l = 1;
        for(int i = 1; i < size; i++) {
            if(nums[i]<=nums[i-1]) {
                l = max(l, i-j);
                j=i;
            }
        }
        
        return max(l, size-j);
    }
};