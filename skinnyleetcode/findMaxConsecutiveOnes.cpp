/*
 *	https://leetcode.com/problems/max-consecutive-ones/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ones = 0;
        int size = nums.size();
        int count = 0;
        for(int i = 0; i < size; i++) {
            if(nums[i]==1) {
                count++;
                max_ones = max(count, max_ones);
            }
            else count = 0;
        }
        return max_ones;
    }
    int findMaxConsecutiveOnes1(vector<int>& nums) {
        int max_ones = 0;
        int j = 0, i = 0;
        int size = nums.size();
        for(i = 0; i < size; i++) {
            if(nums[i]==0) {
                max_ones = max(max_ones, i-j);
                j=i+1;
            }
        }
        max_ones = max(max_ones, i-j);
        return max_ones;
    }
};