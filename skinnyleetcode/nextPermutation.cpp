/*
 * https://leetcode.com/problems/next-permutation/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int k=0;
        int l=0;
        for(k = size-2; k>= 0;k--) {
            if(nums[k]<nums[k+1]) { break; }
        }
        if(k<0) { std::reverse(nums.begin(), nums.end()); }
        else {
            for(l = size-1; l>k; l--) {
                if(nums[l]>nums[k]) { break; }
            }
            std::swap(nums[k], nums[l]);
            std::reverse(nums.begin()+k+1, nums.end());
        }
    }
    void nextPermutation2(vector<int>& nums) {
        nums={2,3,1};
        int size = nums.size();
        int pivot = -1;
        for(int i = size-1; i>0; i--) {
            if(nums[i-1]<nums[i]) {pivot+=i; break;}
        }
        int next_prefix = 0;
        if(pivot!=-1) {
            for(int i = size-1; i>=0; i--) {
                if(nums[i]>pivot) {next_prefix = i; break;}
            }
            std::swap(nums[pivot], nums[next_prefix]);
        }
        
        std::reverse(nums.begin()+pivot, nums.end());
        
    }
    std::vector<std::vector<int>> permutations(std::vector<int> nums) {
        //printf("%d\n", nums.size());
        std::vector<std::vector<int>> ans;
        if(nums.empty()) {ans.push_back(std::vector<int>()); return ans;}
        
        int front = nums.front();
        nums.erase(nums.begin());
        std::vector<std::vector<int>> temp = permutations(nums);
        for(std::vector<int>& temp0: temp) {
            for(int i = 0; i <= temp0.size(); i++) {
                std::vector<int> t(temp0.begin(), temp0.begin()+i);
                t.push_back(front);
                t.insert(t.end(), temp0.begin()+i, temp0.end());
                //std::vector<std::vector<int>> ans1 = permutations(t);
                ans.push_back(t);
            }
        }
        return ans;
    }
    void nextPermutation1(vector<int>& nums) {
        //vector<int> nums1;
        std::vector<std::vector<int>> perm = permutations(nums);
        for(int i = 0; i < perm.size(); i++) {
            if(nums==perm[i] and i < perm.size()-1) nums=perm[i+1];
        }
        nums=perm[0];
    }
};

/*
123
132
213
231
312
321
*/