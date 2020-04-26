/*
 *  https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    void binarySearch(vector<int>& nums, int low, int high, int& target) {
        if(low > high) return;
        
        int mid = low + (high-low)/2;
        std::vector<int> win;
        if(mid-1 >= low and mid+1 <= high) {
            if(nums[mid-1] != nums[mid] and nums[mid] != nums[mid+1]) {
                target = nums[mid];
                return;
            }
        }
        else if(mid-1 >= low) {
            if(nums[mid] != nums[mid-1]) {
                target = nums[mid];
                return;
            }
        }
        else if(mid+1 <= high) {
            if(nums[mid] != nums[mid+1]) {
                target = nums[mid];
                return;
            }
        }
        
        binarySearch(nums, low, mid-1, target);
        binarySearch(nums, mid+1, high, target);
        
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();
        int low = 0;
        int high = size-1;
        while(low < high) {
            int mid = low + (high-low)/2;
            bool rightIsEven = (high-mid)%2 == 0;
            if(nums[mid] == nums[mid+1]) {
                if(rightIsEven) low = mid+2;
                else high = mid-1;
            }
            else if(nums[mid-1] == nums[mid]) {
                if(rightIsEven) high = mid-2;
                else low = mid+1;
            }
            else return nums[mid];
        }
        return nums[low];
    }
        
    int singleNonDuplicate1(vector<int>& nums) {
        int size = nums.size();
        
        for(int i = 0; i < size-1; i+=2) {
            if(nums[i]!=nums[i+1]) {
                return nums[i];
            }
        }
        
        return nums[size-1];
    }
};