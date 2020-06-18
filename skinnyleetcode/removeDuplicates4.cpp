/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        if(size<3) return size;
        
        int j = 0;
        for(int i = 0; i < size; i++) {
            if(j<2 or nums[i]!=nums[j-2]) {
                nums[j++]=nums[i];
            }
        }
        return j;
    }
    
    int removeDuplicates1(vector<int>& nums) {
        if(nums.empty()) return 0;
        int size=nums.size();
        int j = 1;
        int c = 1;
        for(int i = 1; i < size; i++) {
            if(nums[i]!=nums[i-1]) {
                nums[j++]=nums[i];
                c = 1;
            }
            else if(c<2) {
                nums[j++]=nums[i];
                c++;
            }
        }
        return j;
    }
};