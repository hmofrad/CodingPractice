/*
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
     
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left<right) {
            if(nums[left]<nums[right]) { return nums[left];}
            int mid = left + (right-left)/2;
            if(nums[mid]>=nums[left]) {left=mid+1;}
            else {right = mid;}
        }
        return nums[left];
        
    }
    
    int findMin0(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        
        int left = 0, right = nums.size()-1;
        
        if(nums[right]>nums[0]) return nums[0];
        
        while(left <= right) {
            int mid = left + (right-left)/2;
            
            if(nums[mid]>nums[mid+1]) { return nums[mid+1]; }
            
            if(nums[mid]<nums[mid-1]) { return nums[mid]; }
            
            if(nums[mid]>nums[0]) { left = mid+1; }
            else { right = mid-1; }
        }
        return -1;
    }
};