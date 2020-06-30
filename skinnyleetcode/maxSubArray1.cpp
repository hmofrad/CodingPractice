/*
 * https://leetcode.com/problems/maximum-subarray/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int s = 0;
        int ma = INT_MIN;
        for(int i = 0; i < size; i++) {
            s += nums[i];  
            ma = max(s, ma);
            if(s<0) { s=0; }
        }
        return ma;
    }
    
    int helper1(std::vector<int>& nums, int left, int right, int mid) {
        if(left == right) return nums[left];
        
        int left_sub_sum = INT_MIN;
        int curr_sum = 0;
        
        for(int i = mid; i > left-1; i--) {
            curr_sum += nums[i];
            left_sub_sum = max(left_sub_sum, curr_sum);
        }
        
        int right_sub_sum = INT_MIN;
        curr_sum = 0;
        for(int i = mid+1; i < right+1; i++) {
            curr_sum += nums[i];
            right_sub_sum = max(right_sub_sum, curr_sum);
        }
        return left_sub_sum + right_sub_sum;
    }
    int helper(std::vector<int>& nums, int left, int right) {
        if(left==right) return nums[left];
        
        int mid = left + (right-left)/2;
        
        int left_sum = helper(nums, left, mid);
        int right_sum = helper(nums, mid+1, right);
        int cross_sum = helper1(nums, left, right, mid);
        
        return max({left_sum, right_sum, cross_sum});
    }
    int maxSubArray5(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    int maxSubArray4(vector<int>& nums) {
        int size = nums.size();
        int curr_sum = nums[0];
        int max_sum = nums[0];
        //printf("%d %d\n", curr_sum, max_sum);
        for(int i = 1; i < size; i++) {
            curr_sum = max(nums[i], curr_sum+nums[i]);
            max_sum = max(max_sum, curr_sum);
          //  printf("%d %d %d\n", i, curr_sum, max_sum);
        }
        return max_sum;
    }
    int maxSubArray3(vector<int>& nums) {
        int size = nums.size();
        int max_sum = nums[0];
        for(int i = 1; i < size; i++) {
            if(nums[i-1]>0) nums[i]+=nums[i-1];
            max_sum = max(nums[i], max_sum);
        }
        return max_sum;
    }
    int maxSubArray2(vector<int>& nums) {
        int size = nums.size();
        std::vector<std::vector<int>> dp(size+1, std::vector<int>(size));
        for(int i = 0; i < size; i++) dp[0][i]=nums[i];
        
        for(int i = 1; i <= size; i++) {
            for(int j = 0; j < size; j++) {
                dp[i][j]=max(dp[i-1][j], dp[i-1][j]+nums[j]);
                //if(dp[i][j]+nums[j]>sp[i][j-1])
            }
        }
        int max_sum = INT_MIN;
        for(int i = 0; i < size; i++) max_sum=max(max_sum, dp[size][i]);
        return max_sum;
    }
    int maxSubArray1(vector<int>& nums) {
        if(nums.empty()) return 0;
        int max_sum = INT_MIN;
        //int max_len = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            int s = 0;
            //int l = 0;
            for(int j = i; j < size; j++) {
                s+=nums[j];
                if(s>max_sum){max_sum=s;}
            }
        }
        return max_sum;
    }
    
};