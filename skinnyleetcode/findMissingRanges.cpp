/*
 * https://leetcode.com/problems/missing-ranges/submissions/	
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::string form_range(int a, int b) {
        return (a==b) ? to_string(a) :
                        to_string(a)+"->"+to_string(b);
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        std::vector<std::string> ranges;
        if(nums.empty()) {
            ranges.push_back(form_range(lower, upper));
            return ranges;
        } 
        
        int size = nums.size();
        if(nums[0] > lower) { ranges.push_back(form_range(lower, nums[0]-1)); }
            
        for(int i = 0; i < size-1; i++) {
            if(nums[i] != nums[i+1] and nums[i]+1<nums[i+1]) {
                ranges.push_back(form_range(nums[i]+1, nums[i+1]-1));
            }
        }
        if(nums[size-1]<upper) { ranges.push_back(form_range(nums[size-1]+1, upper)); }
            
        return ranges;
    }
};