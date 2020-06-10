/*
 * https://leetcode.com/problems/range-sum-query-mutable/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class NumArray {
public:
    std::vector<int> nums;
    std::vector<int> prefixes;
    NumArray(vector<int>& nums_) {
        nums=nums_;
        prefixes.resize(nums.size()+1);
        for(int i = 0; i < nums.size(); i++) prefixes[i+1]=prefixes[i]+nums[i];
        //for(int p: prefixes) printf("%d ", p); printf("\n");
    }
    
    void update(int i, int val) {
        int diff = val-nums[i];
        nums[i]=val;
        for(int j = i+1; j < prefixes.size(); j++) {
            prefixes[j]+=diff;
        }
        //for(int p: prefixes) printf("%d ", p); printf("\n");
    }
    
    int sumRange(int i, int j) {
        return prefixes[j+1]-prefixes[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */