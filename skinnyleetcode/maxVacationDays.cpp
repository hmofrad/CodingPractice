/*
 * https://leetcode.com/problems/maximum-vacation-days/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    int dfs(vector<vector<int>>& flights, vector<vector<int>>& days, int city, int week) { 
        int ncities = flights.size();
        int nweeks = days[0].size();
        if(week == nweeks) { return 0; }
        
        int max_vacations = 0;
        for(int i = 0; i < ncities; i++) {
            if(flights[city][i] == 1 or i == city) {
                int vacations = days[i][week] + dfs(flights, days, i, week+1);
                max_vacations = max(max_vacations, vacations);
            }
        }
        return max_vacations;
    }
    
    int dfs(vector<vector<int>>& flights, vector<vector<int>>& days, int city, int week, std::vector<std::vector<int>>& cache) { 
        int ncities = flights.size();
        int nweeks = days[0].size();
        if(week == nweeks) { return 0; }
        
        if(cache[city][week] != -1) { return cache[city][week]; }
        
        int max_vacations = 0;
        for(int i = 0; i < ncities; i++) {
            if(flights[city][i] == 1 or i == city) {
                int vacations = days[i][week] + dfs(flights, days, i, week+1);
                max_vacations = max(max_vacations, vacations);
            }
        }
        cache[city][week] = max_vacations;
        return max_vacations;
    }
    int maxVacationDays0(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int ncities = flights.size();
        int nweeks = days[0].size();
        std::vector<std::vector<int>> cache(ncities, std::vector<int>(nweeks, -1));
        return dfs(flights, days, 0 , 0, cache);
        //return dfs(flights, days, 0 , 0);
    }
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int ncities = flights.size();
        int nweeks = days[0].size();
        std::vector<std::vector<int>> dp(ncities, std::vector<int>(nweeks+1));
        for(int i = nweeks-1; i>= 0; i--) {
            for(int j = 0; j < ncities; j++) {
                int mx = 0;
                for(int k = 0; k < ncities; k++) {
                    if(flights[j][k]==1 or k == j) {
                        mx = max(mx, days[k][i] + dp[k][i+1]);
                    }
                }
                dp[j][i]=mx;
            }
        }
        return dp[0][0];
    }
};
