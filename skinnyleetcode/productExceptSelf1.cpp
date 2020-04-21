/*
 *  https://leetcode.com/problems/product-of-array-except-self/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> left(size);
        std::vector<int> right(size);
        std::vector<int> output(size);
        left[0]=1;
        for(int i = 1; i < size; i++) {
            left[i] = left[i-1] * nums[i-1];
        }
        right[size-1]=1;
        for(int i = size-2; i >= 0; i--) {
            right[i] = right[i+1]*nums[i+1];
        }
        for(int i = 0; i < size; i++) {
            output[i] = left[i]*right[i];
        }
        
        
        return output;
    }
    
    vector<int> productExceptSelf1(vector<int>& nums) {
    int n = nums.size();
    std::vector<int> nums1(n, 1);
    int left = 1;
    int right = 1;
    int j = 0;
    for(int i = 1; i < n; i++) {
        j = n - i;
        left *= nums[i-1];
        right *= nums[j];
        nums1[i] *= left;
        nums1[j-1] *= right;
    }
    return(nums1);     
    }
};