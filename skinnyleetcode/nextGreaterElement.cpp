/*
 *  https://leetcode.com/problems/next-greater-element-i/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::map<int, int> nums;
        std::vector<int> stack;
        int size = nums2.size();
        for(int i = 0; i < size; i++) {
            int m = nums2[i];
            if(stack.empty()) stack.push_back(m);
            else {
                while(not stack.empty() and m > stack.back()) {
                    nums[stack.back()] = m;
                    stack.pop_back();
                }
                stack.push_back(m);
            }
        }
        
        while(not stack.empty()) {
            nums[stack.back()] = -1;
            stack.pop_back();
        }
        
        for(int& num: nums1) {
            num = nums[num];
        }
            
        return(nums1);
    }
    
    
    vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2) {
        std::map<int, int> nums;
        int size = nums2.size();
        for(int i = 0; i < size; i++) {
            int m = nums2[i];
            nums[m] = -1;
            for(int j = i+1; j < size; j++) {
                int n = nums2[j];
                if(n > m) {nums[m] = n; break;}
            }
        }
        
        for(int& num: nums1) {
            num = nums[num];
        }
            
        return(nums1);
    }
};