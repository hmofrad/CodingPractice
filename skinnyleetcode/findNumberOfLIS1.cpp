/*
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        //nums={1,2,3,1,2,3,1,2,3};
        //nums={2,2,2,2,2};
        if(nums.empty()) return 0;
        int size = nums.size();
        std::vector<std::pair<int, int>> dp(size, {1,1});
        int ans = 1;
        for(int i = 1; i < size; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i]>nums[j]) {
                    if(dp[i].first == dp[j].first + 1) { dp[i].second += dp[j].second; }
                    else if(dp[i].first < dp[j].first + 1) { dp[i] = {dp[j].first + 1, dp[j].second}; }
                    ans = max(ans, dp[i].first);
                }
            }
        }
        //printf("%d\n", ans);
        int count = 0;
        for(int i = 0; i < size; i++) {
            if(dp[i].first==ans) count+=dp[i].second;
          //  printf("%d ", dp[i].second);
        }
        //printf("\n");
        return count;
    }
};