/*
 * https://leetcode.com/problems/find-peak-element/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        int right = size-1;
        while(left<right) {
            int mid = left + (right-left)/2;
            
            if(nums[mid]<nums[mid+1]) { left = mid+1; }
            else { right = mid; }
        }
        return left;
    }
    int findPeakElement1(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size-1; i++) {
            if(nums[i]>nums[i+1]) { return i; }
        }
        return size-1; 
    }
    int findPeakElement0(vector<int>& nums) {
        if(nums.size()==0) { return -1; }
        else if(nums.size() == 1) { return 0; }
        else if(nums.size() == 2) { return nums[0]>nums[1] ? 0 : 1; }
        std::stack<int> stack;
        stack.push(0);
        int size = nums.size();
        for(int i = 1; i < size; i++) {
            if(nums[stack.top()]<=nums[i]) {
                stack.pop(); stack.push(i);
            }
            else { return stack.top(); }
        }
        return size-1;
    }
};