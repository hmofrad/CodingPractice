/*
 *	https://leetcode.com/problems/missing-element-in-sorted-array/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int missing(std::vector<int>& nums, int i) {
        return nums[i]-(nums[0]+i);
    }
    int missingElement(vector<int>& nums, int k) {
        int size = nums.size();
        
        //if(k>missing(nums, size-1)) return nums[0]+((nums[size-1]-missing(nums, size-1))-k);
        if(k>missing(nums, size-1)) return nums[size-1]+k-missing(nums, size-1);
        
        int left = 0, right = size-1;
        while(left!=right) {
            int mid = left + (right-left)/2;
            if(missing(nums, mid)<k) left = mid+1;
            else right = mid;
        }
        return nums[left-1]+k-missing(nums,left-1);
    }
    int missingElement1(vector<int>& nums, int k) {
        int size = nums.size();
        int v = 0;
        bool found = false;
        for(int i = 0; i < size-1; i++) {
            int d = nums[i+1]-nums[i]-1;
            if(d>=1) {
                d=min(d, k);
                v=nums[i]+d;
                k-=d;
                //printf("n[%d]=%d k=%d d=%d v=%d\n", i, nums[i], k, d, v);
                if(k==0) {found = true; break;}
            }
        }
        
        return found ? v : nums.back()+k;
    }
};