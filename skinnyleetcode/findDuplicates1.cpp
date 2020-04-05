/*
 *  https://leetcode.com/problems/find-all-duplicates-in-an-array/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
// The idea is to use the nums as indices as they're in range [1, n]
// we can mark the number at a particular index as negative
// and if the number is already negative that means we've already marked it
// and thus the current number in nums is duplicate 

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::vector<int> dups;
        int m = nums.size();
        for(int i = 0; i < m; i++) {
            int j = abs(nums[i])-1;
            if(nums[j]<0) dups.push_back(j+1);
            else nums[j] = -nums[j];
        }
        return(dups);
    }
    
    vector<int> findDuplicates1(vector<int>& nums) {
    std::vector<int> ans ;
        int j ;
        for(uint32_t i = 0 ; i < nums.size() ; i++ ){
            j = abs(nums[i]) ;
            if(nums[j-1] > 0)
                nums[j-1] = -nums[j-1];
            else
                ans.push_back(j) ;
        }
        return ans ;
    
    }
};