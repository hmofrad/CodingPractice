/*
 * https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //nums={4,5,6,7,0,1,2};
        //target=3;
        int left = 0;
        int right = nums.size()-1;
        while(left<=right) {
            int mid = left + (right-left)/2;
            if(nums[mid]==target) { return mid; }
            else if(nums[left]<=nums[mid]) {
                if(target>=nums[left] and target<nums[mid]) { right=mid-1; }
                else { left=mid+1; }
            }
            else {
                if(target>nums[mid] and target<=nums[right]) { left=mid+1; }
                else { right=mid-1;  }
            }
        }
        return -1;
    }
};