/*
 * https://leetcode.com/problems/split-array-largest-sum/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int size = nums.size();
        long sum = 0;
        long max = INT_MIN;
        for(int i = 0; i < size; i++) {
            sum+=nums[i];
            max = nums[i]>max ? nums[i] : max;
        }
        
        if(m==1) return (int) sum;
        long left = max;
        long right = sum;
        
        while(left<=right) {
            long mid = left + (right-left)/2;
            if(valid(nums, m, mid)) { right = mid-1;}
            else {left = mid+1;}
        }
        return (int) left;
    }
    
    bool valid(std::vector<int>& nums, int m, long target) {
        int count = 1;
        long sum = 0;
        for(int num: nums) {
            sum+=num;
            if(sum>target) {
                sum=num;
                count++;
                if(count>m) return false;
            }
        }
        return true;
    }
    
    
    int ans;
    void dfs1(vector<int>& nums, int m, int n, int index, uint32_t cur_sum, uint32_t max_sum) {
        if(index == nums.size() and n == m) {
            ans = min(ans, (int)max_sum);
            return;
        }
        if(index==nums.size()) return;
        uint32_t new_sum = cur_sum + nums[index];
        if(index) dfs1(nums, m, n, index+1, new_sum, max(new_sum, max_sum));
        
        if(n < m) dfs1(nums, m, n+1, index+1, nums[index], max((uint32_t)nums[index], max_sum));
    }

    int splitArray2(vector<int>& nums, int m) {
       // nums={1,2147483647};
        //m=2;
        ans = INT_MAX;
        dfs1(nums, m, 0, 0, 0, 0);
        return ans;
    }
    
    int dfs(vector<int>& nums, int m, int n, int index, int cur_sum, int max_sum) {
        printf("m=%d n=%d i=%d cs=%d ms=%d\n", m, n, index, cur_sum, max_sum);
        if(nums.size()==index) {
            return m==n ? min(cur_sum, max_sum) : INT_MAX;
        }
        
        int new_sum = cur_sum + nums[index];
        int ret = dfs(nums, m, n, index+1, new_sum, max(new_sum, max_sum));
        if(n<m) ret = min(ret, dfs(nums, m, n+1, index+1, nums[index], max(cur_sum, max_sum)));
        return ret;
    }
    int splitArray1(vector<int>& nums, int m) {
        return dfs(nums, m, 1, 1, nums[0], nums[0]);
    }
};