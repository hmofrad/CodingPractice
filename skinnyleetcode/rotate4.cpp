/*
 * https://leetcode.com/problems/rotate-array/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty() or k<=0) { return; }
        int size = nums.size();
        k = k % size;
        std::reverse(nums.begin(), nums.begin()+(size-k));
        std::reverse(nums.begin()+(size-k), nums.end());
        std::reverse(nums.begin(),nums.end());
    }
};
