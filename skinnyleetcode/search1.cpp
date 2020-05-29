/*
 *	https://leetcode.com/problems/binary-search/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high) {
            int mid = (low+high)/2; 
            if(nums[mid]<target) low=mid+1;
            else if(nums[mid]>target) high=mid-1;
            else return mid;
        }
        return -1;
    }
};