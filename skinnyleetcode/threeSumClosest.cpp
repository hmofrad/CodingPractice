/*
 * https://leetcode.com/submissions/detail/135357992/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int size = nums.size();
        for(int i = 0; i < size-2 and diff ; i++) {
            int left = i+1;
            int right = size-1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(target-sum) < abs(diff)) { diff = target-sum; }
                if(sum<target) { left++; }
                else { right--; }
            }
        }
        return target - diff;
    }
};