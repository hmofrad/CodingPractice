/*
 *  https://leetcode.com/problems/move-zeroes/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int j = 0;
        for(int i = 0; i < size; i++) {
            if(nums[i]) {
                std::swap(nums[i], nums[j]);
                j++;
            }
        }
        
    }
    
    
    
    void moveZeroes2(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size-1; i++) {
            for(int j = i+1; j < size; j++) {
                if(nums[i] == 0) std::swap(nums[i], nums[j]);
            }
        }
    }

    void moveZeroes1(vector<int>& nums) {
           int n = nums.size();
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }   
    }
   // print(nums);
    while(j < n) {
        nums[j] = 0;
        j++;
    }
    }
};