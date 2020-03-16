/*
 *  Problem: https://leetcode.com/problems/decompress-run-length-encoded-list/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        std::vector<int> v;
        int m = nums.size();
        int i = 0;
        while(i < m) {
            for(int j = 0; j < nums[i]; j++) {
                v.push_back(nums[i+1]);
            }
            i+=2;
        }
        return(v);
    }
};