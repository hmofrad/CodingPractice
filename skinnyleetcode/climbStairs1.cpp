/*
 * https://leetcode.com/problems/climbing-stairs/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    int climbStairs(int n) {
        if(n<=1) { return n; }
        std::vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3; i<=n; i++) {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    std::set<std::vector<int>> set;
    void dfs(int n, int k, std::vector<int> temp) {
        if(k==0){ set.insert(temp); return; }
        if(k<0) { return; }
        temp.push_back(1);
        dfs(n, k-1, temp);
        temp.pop_back();
        temp.push_back(2);
        dfs(n,k-2, temp);
    }
    int climbStairs0(int n) {
        if(n==0) return 0;
        dfs(n, n, std::vector<int>());
        return set.size();
    }
};