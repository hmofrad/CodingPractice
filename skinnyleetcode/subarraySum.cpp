/*
 * https://leetcode.com/problems/subarray-sum-equals-k/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int count = 0;
        int size = nums.size();
        int sum = 0;
        std::unordered_map<int, int> map;
        map[0]=1;
        for(int i = 0; i < size; i++) {
            sum +=nums[i];
            int d = sum-k;
            count += map[d];
            map[sum]++;
        }
        return count;
    }
    int subarraySum3(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int count = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            int sum = 0;
            for(int j = i; j < size; j++) {
                sum += nums[j];
                if(sum==k) {count++;}
            }
        }
        return count;
    }
    
    int subarraySum2(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int count = 0;
        int size = nums.size();
        std::vector<int> sums(size+1);
        for(int i = 1; i <= size; i++) { sums[i]=sums[i-1]+nums[i-1]; }
        
        for(int i = 0; i < size; i++) {
            for(int j = i+1; j <= size; j++) {
                if(sums[j]-sums[i]==k) count++;
            }
        }
        
        return count;
    }
    
    int subarraySum1(vector<int>& nums, int k) {
        int count = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            for(int j = i+1; j <= size; j++) {
                int sum = 0;
                for(int k = i; k < j; k++) { sum += nums[k]; }
                if(sum==k) { count++; }
            }
        }
        return count;
    }
 
    int backtrack(std::vector<int>& nums, int k, int index, bool picked, int sum) {
        if(picked and sum == k) {return 1;}
        int size = nums.size();
        if(index==size){return 0;}
        int count = 0;
        if(picked==false) {
            count = backtrack(nums, k, index+1, true, sum+nums[index]) +
                    backtrack(nums, k, index+1, false, sum);            
        }
        else {
            count = backtrack(nums, k, index+1, true, sum+nums[index]);
        }
        return count;
    }
    
    
    int subarraySum0(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        return backtrack(nums, k, 0, false, 0);
    }
};