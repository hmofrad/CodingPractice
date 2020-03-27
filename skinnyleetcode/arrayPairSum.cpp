/*
 *  https://leetcode.com/problems/array-partition-i/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int s = 0;
        for(int i = 0; i < nums.size(); i+=2) {
            //s += (nums[i] < nums[i+1]) ? nums[i] : nums[i+1];
            s += nums[i];
        }
        return(s);
    }
};