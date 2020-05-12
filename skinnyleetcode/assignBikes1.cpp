/*
 *	https://leetcode.com/problems/campus-bikes-ii/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int dist(std::vector<int>& a, std::vector<int>& b) {
        return  abs(a[0]-b[0]) + abs(a[1]-b[1]);    
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int nworkers = workers.size();
        int nbikes = bikes.size();
        std::vector<std::vector<int>> dp(nworkers+1, std::vector<int>((1<<nbikes), INT_MAX/2));
        int min_dist = INT_MAX;
        dp[0][0]=0;
        for(int i = 1; i <= nworkers; i++) {
            for(int s = 1; s < (1<<nbikes); s++) {
                for(int j = 0; j < nbikes; j++) {
                    if((s & (1<<j))==0) continue;
                    
                    int prev = s^(1<<j);
                    dp[i][s]=min(dp[i-1][prev]+dist(workers[i-1], bikes[j]), dp[i][s]);
                    if(i==nworkers) min_dist = min(min_dist, dp[i][s]);
                }
            }
        }
        
        return min_dist;
    }
    
    
    int min_dist = INT_MAX;
    void dfs(vector<vector<int>>& workers, vector<vector<int>>& bikes, std::vector<bool> visited, int index, int distance) {
        int nworkers = workers.size();
        if(index == nworkers) {min_dist=min(distance, min_dist); return;}
        if(distance>min_dist) return;
        int nbikes = bikes.size();
        
        for(int i = 0; i < nbikes; i++) {
            if(not visited[i]) {
                visited[i]=true;
                dfs(workers, bikes, visited, index+1, distance+dist(bikes[i], workers[index]));
                visited[i]=false;
            }
        }
    }
    int assignBikes3(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int nworkers = workers.size();
        int nbikes = bikes.size();
        std::vector<bool> visited(nbikes); 
        dfs(workers, bikes, visited, 0, 0);
        return min_dist;
    }
    
    
    int assignBikes2(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int nworkers = workers.size();
        int nbikes = bikes.size();
        std::vector<int> valid(nbikes, true);
        int min_d = 0;
        for(int i = 0; i < nworkers; i++) {
            int d = INT_MAX;
            int k = -1;
            for(int j = 0; j < nbikes; j++) {
                if(valid[j]) { int dt=dist(workers[i], bikes[j]); if(dt<d) {d=dt; k=j;} }
            }
            //printf("%d %d\n", i, k);
            min_d += d;
            valid[k]=false;
        }
        return min_d;
    }
    int assignBikes1(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int nworkers = workers.size();
        int nbikes = bikes.size();
        std::vector<std::vector<int>> dp(nworkers+1, std::vector<int>(nbikes+1));
        int min_dist = 0;
        for(int i = 1; i <= nworkers; i++) {
            printf("i=%d\n", i);
            int d = INT_MAX;
            for(int j = 1; j <= nbikes; j++) {
                printf("j=%d\n", j);
                int dist = abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1]);
                if(dist<=dp[i-1][j-1]) dp[i][j]=dist; 
                else dp[i][j]=min(dp[i-1][j], dp[i][j-1]);   
                d=min(d, dp[i][j]);
            }
             min_dist += d;
        }
        return min_dist;
    }
};