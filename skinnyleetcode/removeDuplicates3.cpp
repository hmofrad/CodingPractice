/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int size = nums.size();
        int j = 1;
        for(int i = 1; i < size; i++) {
            if(nums[i]!=nums[i-1]) nums[j++]=nums[i];
        }
        return j;
    }
};