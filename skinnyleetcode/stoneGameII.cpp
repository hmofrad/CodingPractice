/*
 *  https://leetcode.com/problems/stone-game-ii/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
int stoneGameII(vector<int>& piles) {
    int size = piles.size();
    if(size == 1) return piles[0];

    std::vector<int> prefixSum(size+1, 0);
    prefixSum[0] = piles[0];
    for(int i=1; i<size; i++) {
        prefixSum[i] = prefixSum[i-1]+piles[i];
    }
    std::vector<std::vector<int>> dp(size, std::vector<int>(size));
    
    for(int i=size-1; i>=0; i--) {
        for(int j=0; j<size; j++) {
            if(i+(2*j)>=size) {dp[i][j]=prefixSum[size-1]-prefixSum[i]+piles[i];}
        
            for(int k=1; (k<=min(2*j,size-1)) and (i + k < size); k++) {
                //if(i + k >= size) break;

                //printf("%d %d %d %d %d\n", i, j, k, size,k+i<size);
                dp[i][j]=max(dp[i][j], prefixSum[size-1]-dp[i+k][max(k,j)]-prefixSum[i]+piles[i]);
            }
        }
    }
    return dp[0][1];
}
    
    
    
    int play(std::vector<int>& piles, int M, int turn, int score_A, int score_L) {
        printf("sz=%d, M=%d turn=%d A=%d L=%d\n", piles.size(), M, turn, score_A, score_L);
        int size = piles.size();
        if(piles.empty()) return (turn%2) ? score_A : score_L;
        
        std::vector<int> scores_A;
        std::vector<int> scores_B;
        for(int i = 1; i <= min(2*M, size-1); i++) {
            //printf("I: %d\n", i);
            std::vector<int> piles1 = piles;
            if(turn%2 == 0) {
                printf("A: %d %d\n", piles1.size(), i);
                score_A += std::accumulate(piles1.begin(), piles1.begin()+i, 0);
                piles1.erase(piles1.begin(), piles1.begin()+i);
                int score = play(piles1, i, turn+1, score_A, score_L);
                printf("A: %d %d>>\n", score, i);
                scores_A.push_back(score);
            }
            else {
                printf("L: %d %d\n", piles1.size(), i);
                score_L += std::accumulate(piles1.begin(), piles1.begin()+i, 0);
                piles1.erase(piles1.begin(), piles1.begin()+i);
                int score = play(piles1, i, turn+1, score_A, score_L);
                printf("L: %d %d>> \n", score, i);
                scores_B.push_back(score);
            }
        }
        
        return *std::min_element(scores_A.begin(), scores_A.end());
        
    }
    int stoneGameII1(vector<int>& piles) {
        return(play(piles, 1, 0, 0, 0));
    }
};