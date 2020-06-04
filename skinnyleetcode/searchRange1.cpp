/*
 *  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size-1;
        while(left<size and nums[left]!=target) left++; 
        while(right>=0 and nums[right]!=target) right--;
        return left!=size ? std::vector<int>({left, right}) : std::vector<int>({-1, -1});
    }
    vector<int> searchRange1(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right) {
            int mid = left + (right-left)/2;
            if(nums[mid]<target) { left=mid+1;}
            else if(nums[mid]>target) {right=mid-1;}
            else { 
                left = right = mid;
                while(left-1 >= 0 and nums[left-1]==target) left--;
                while(right+1 < nums.size() and nums[right+1]==target) right++;
                return {left, right};
             }
        }
        return {-1,-1};
    }
};