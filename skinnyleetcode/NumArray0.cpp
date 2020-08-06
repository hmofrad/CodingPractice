/*
 * https://leetcode.com/problems/range-sum-query-immutable/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class NumArray {
public:
    int size = 0;
    std::vector<int> sums;
    NumArray(std::vector<int>& nums) {
        if(nums.empty()) { return; }
        size = nums.size();
        sums.resize(size+1);
        for(int i = 1; i <= size; i++) { sums[i] = sums[i-1] + nums[i-1]; }
    }
    
    int sumRange(int i, int j) {
        if(j<0 or i<0 or i>=size or j>=size or i>j) { return 0; }
        return sums[j+1]-sums[i];
    }
};


class NumArray0 {
public:
    std::vector<int> nums;
    int size;
    NumArray0(std::vector<int>& nums_) {
        nums = nums_;
        size = nums.size();
    }
    
    int sumRange(int i, int j) {
        /*
        int sum = 0;
        
        if((i < 0) or ( j > size - 1))
            return(0);
        
        for(int k = i; k <= j; k++) 
            sum += nums[k];
        return(sum);
        */
        
        if((i < 0) or ( j > size - 1))
            return(0);
        
        return(std::accumulate(nums.begin()+i, nums.end()-(size - 1 - j), 0));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */