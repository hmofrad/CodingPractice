/*
 *  https://leetcode.com/problems/minimum-cost-for-tickets/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.back();
        std::vector<int> dp(n+1,0);
        dp[0]=0;
        for(int i = 1,j=0; i <= n; i++) {
            if(i==days[j]) {
                dp[i] = min({dp[i-1]+costs[0], dp[max(i-7, 0)]+costs[1], dp[max(i-30,0)]+costs[2]});
                j++;
            }
            else {
                dp[i]=dp[i-1];
            }
        }
        return dp[n];
    }
    std::vector<int> mem;
     int dfs(vector<int>& days, vector<int>& costs, int day, int cost_index) {
         int last_day = days.back();
         if(day > last_day) return costs[cost_index];
         
         if(mem[day] != -1) return costs[cost_index]+mem[day];
         
         int day_index = lower_bound(days.begin(), days.end(), day)-days.begin();
         int next_day = days[day_index];
         
         int cost = costs[cost_index];
         
         int min_cost = min({dfs(days, costs, next_day+1, 0),
                           dfs(days, costs, next_day+7, 1),
                            dfs(days, costs, next_day+30, 2)});
         cost += min_cost;
         mem[day]=min_cost;
         return cost;
         
     }
    int mincostTickets1(vector<int>& days, vector<int>& costs) {
        int day = days[0];
        int latest_day = days.back()+costs[2];
        mem.resize(latest_day, -1);
        
        return min({dfs(days, costs, day+1, 0),
                    dfs(days, costs, day+7, 1),
                    dfs(days, costs, day+30, 2)});
        
    }
};