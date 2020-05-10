/*
 *	https://leetcode.com/problems/next-greater-element-ii/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
   vector<int> nextGreaterElements(vector<int>& nums) {
        
        std::stack<int> stack;
        int size = nums.size();
        std::vector<int> ans(size);
        for(int i = 2*size-1; i >= 0; i--) {
            int j = i%size;
            if(stack.empty()) {
                stack.push(j);
                ans[j]=-1;
            }
            else {
                while(not stack.empty() and nums[stack.top()]<=nums[j]) stack.pop();
                if(not stack.empty()) {
                    int t = stack.top(); 
                    stack.push(j); 
                    ans[j]=nums[t];
                }    
                else {
                    ans[j]=-1; 
                    stack.push(j);
                }
            }
        }
        return ans;
    }
    vector<int> nextGreaterElements3(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> ans(size);
        for(int i = 0; i < size; i++) {
            ans[i]=-1;
            for(int j = 1; j < size; j++){
                int k=(j+i)%(size);
                if(nums[k]>nums[i]) {ans[i]=nums[k]; break;}
            }
        }
        return ans;
    }
        
    vector<int> nextGreaterElements2(vector<int>& nums) {
        std::vector<int> nums1(nums.begin(), nums.end());
        nums1.insert(nums1.end(), nums.begin(), nums.end());
        int size = nums.size();
        int size1 = nums1.size();
        for(int i = 0; i < size; i++) {
            nums[i]=-1;
            for(int j = i+1; j < i+size; j++) {
                if(nums1[j] > nums1[i]) {
                    nums[i]=nums1[j];
                    break;
                }
            }
        }
        return nums;
    }
    vector<int> nextGreaterElements1(vector<int>& nums) {
        std::stack<int> stack;
        int size = nums.size();
        for(int i = size-1; i >= 0; i--) {
            if(stack.empty()) {
                stack.push(nums[i]);
                nums[i]=-1;
            }
            else {
                while(not stack.empty() and stack.top()<nums[i]) stack.pop();
                if(not stack.empty()) {
                    int t = stack.top(); 
                    stack.push(nums[i]); 
                    nums[i]=t;
                }    
                else {
                    nums[i]=-1; 
                    stack.push(nums[i]);
                }
            }
        }
        return nums;
    }
};