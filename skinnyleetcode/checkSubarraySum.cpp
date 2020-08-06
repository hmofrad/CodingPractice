/*
 * https://leetcode.com/problems/continuous-subarray-sum/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        std::unordered_map<int, int> map;
        int size = nums.size();
        map[0]=-1;
        for(int i = 0; i < size; i++) {
            sum += nums[i];
            if(k) { sum = sum%k; }
            if(map.count(sum)==0) { map[sum]=i; }
            else if(i-map[sum]>1) { return true; }
        }
        return false;
    }
    bool checkSubarraySum1(vector<int>& nums, int k) {
        int size = nums.size();
        std::vector<int> sums(size+1);
        for(int i = 0; i < size; i++) { sums[i+1] = sums[i] + nums[i]; }
        for(int i = 0; i < size-1; i++) {
            for(int j = i+1; j < size; j++) {
                if((k and ((sums[j+1]-sums[i])%k)==0) or (k==0 and sums[j+1]-sums[i]==0)) { return true;}
            }
        }
        
        return false;
    }
    bool checkSubarraySum0(vector<int>& nums, int k) {
        int size = nums.size();
        for(int i = 0; i < size-1; i++) {
            int sum = nums[i];
            for(int j = i+1; j < size; j++) {
                sum += nums[j];
                if((k and ((sum%k) == 0)) or (k==0 and sum==0)) { return true; }
            }
        }
        return false;
    }
};