/*
 *	https://leetcode.com/problems/4-keys-keyboard/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int maxA(int N) {
        std::vector<int> dp(N+1);
        for(int k = 1; k <= N; k++) {
            dp[k]=dp[k-1]+1;
            for(int x = 0; x < k-1; x++) {
                dp[k] = max(dp[k], dp[x]*(k-x-1));
            }
        }
        return dp[N];
    }
};