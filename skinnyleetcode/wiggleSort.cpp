/*
 *  https://leetcode.com/problems/wiggle-sort/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.empty()) return;
        for(int i = 0; i < nums.size()-1; i++) {
            if(((i%2==0) and nums[i] > nums[i+1]) or ((i%2) and nums[i] < nums[i+1])) std::swap(nums[i], nums[i+1]); 
        }
        
    }
    
    void wiggleSort2(vector<int>& nums) {
        bool less = true;
        for(int i = 0; i < nums.size()-1; i++) {
            if(less) {
                if(nums[i] > nums[i+1]) std::swap(nums[i], nums[i+1]);
            }
            else {
                if(nums[i] < nums[i+1]) std::swap(nums[i], nums[i+1]);
            }
            less = not less;
        }
    }
    void wiggleSort1(vector<int>& nums) {
        if(nums.empty()) return;
        std::sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size()-1; i+=2) {
           // printf("[%d %d]", i, i+1);
            std::swap(nums[i], nums[i+1]);
        }
    }
};