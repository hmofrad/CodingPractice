/*
 *  https://leetcode.com/problems/stone-game/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    bool stoneGame(vector<int>& piles, int i = 0, int j = -1, int si = 0, int sj = 0) {
        int m = piles.size();
        j = (j==-1) ? m-1 : j;
        if(i<j){
            i=i+1;
            j=j-1;
            if(piles[i] > piles[j]) {
                return(piles, i, j, si+piles[i], sj+piles[j]);
            }
            else 
                return(piles, i, j, si+piles[j], sj+piles[i]);
            }
        return(si > sj);
    }
    
    bool stoneGame1(vector<int>& piles) {
        int m = piles.size();    
        std::vector<std::vector<int>> dp(m+2, std::vector<int> (m+2));
        for(int i = 1; i <= m; i++) {
            for(int j = 0; j + i <= m; j++) {
                int k = j+i-1;
                int parity = (k+j+m)%2;
                if(parity == 1) {
                    dp[j+1][k+1] = max(piles[j] + dp[j+2][k+1], piles[k]+dp[j+1][k]);
                }
                else {
                    dp[j+1][k+1] = max(-piles[j] + dp[j+2][k+1], piles[k]+dp[j+1][k]);
                }
            }
        }
        return dp[1][m] > 0;
    }
};