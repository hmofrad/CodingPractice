/*
 *  https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        if(nums.size()==1 and target == nums[0]) return true;
        else if(nums.size()==1 and target != nums[0]) return false;
        
        int size = nums.size();
        int left = 0;
        int right = size-1;
        while(left<=right) {
            int mid = left + (right-left)/2;
            if(nums[mid]>target) right=mid-1;
            else if(nums[mid]<target) left=mid+1;
            else {left=mid-1; right=mid; break;}
        }
        int count = 0;
        while(true) {
            int b = 0;
            if((left >= 0) and (left <= (size-1)) and (nums[left] == target)) {count++; left--;}
            else b++;
            if((right >= 0) and (right <= (size-1)) and (nums[right] == target)) {count++; right++;}
            else b++;
            if(b==2) break;
        }
        return count > size/2;
    }
    bool isMajorityElement2(vector<int>& nums, int target) {
        int size = nums.size();
        int count = 0;
        for(int n: nums) {
            if(n == target) count++;
        }
        return count > size/2;
    }
    bool isMajorityElement1(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        if(nums.size()==1 and target == nums[0]) return true;
        else if(nums.size()==1 and target != nums[0]) return false;
        
        int size = nums.size();
        std::unordered_map<int, int> map;
        for(int n: nums) {
            map[n]++;
        }
        
        int count = 0;
        int value = 0;
        for(auto m: map) {
            if(m.second > count) {
                value = m.first;
                count = m.second;
            }
        }

        return value == target and count > size/2;
    }
};