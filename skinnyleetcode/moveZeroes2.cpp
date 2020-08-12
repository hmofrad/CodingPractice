/*
 * https://leetcode.com/problems/move-zeroes/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */



class Solution {
public:

    void moveZeroes4(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size;
        while(left<right) {
            if(nums[left]==0) {
                for(int j=left+1; j < right; j++) {
                    nums[j-1]=nums[j];
                }
                nums[right-1]=0;
                right--;
            }
            else {left++;}
        }
    }
    
    
    
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
    
    void moveZeroes0(vector<int>& nums) {
        int size = nums.size();
        int j = 0;
        for(int i = 0; i < size; i++) {
            if(nums[i]!=0) { 
                nums[j] = nums[i]; 
                if(i!=j) {nums[i]=0;}
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