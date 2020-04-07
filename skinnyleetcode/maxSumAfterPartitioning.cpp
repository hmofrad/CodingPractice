/*
 *  https://leetcode.com/problems/partition-array-for-maximum-sum/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int m = A.size();
        std::vector<int> dp(m+1);
        
        for(int i = 0; i < m; i++) {
            //printf("%d: ", i);
            int r = 0;
            int s = 0;
            for(int k = 1; k <= K and i-k+1 >= 0; k++) {
                s = max(s, A[i-k+1]);
                r = max(r, dp[i-k+1] + k*s);
               // printf("[%d %d %d]", k, s, r);
            }  
            dp[i+1] = r;
            //printf(" %d\n", dp[i+1]);
        }    
        
        //for(auto d: dp) printf("%d ", d);
    
        return dp.back();
    }
    
    
    int maxSumAfterPartitioning1(vector<int>& A, int K, int i = 0, int j = 0) {
        int m = A.size();
        if(i >= m or i-j < 0) return 0;
        
        int n = (m-i > 3) ? 3 : m-i;
        //printf("%d\n", n);
        std::vector<int> current_gains(n);
        for(int k = 0; k < n; k++){
            current_gains[k] = A[i-j] * (k+1);
           // printf("C=%d %d\n",k, current_gains[k]);
        }        

        int current_gain = *std::max_element(current_gains.begin(), current_gains.end());
        int current_index = std::min_element(current_gains.begin(), current_gains.end()) - current_gains.begin();
        
        //printf("<< %d %d %d %d\n", i, i+current_index, m, current_gains.size());
        int current_next_gain = maxSumAfterPartitioning1(A, K, i+n, 0);
        int this_gain = current_gain + current_next_gain;
        //exit;
        int next_gain = max(maxSumAfterPartitioning1(A, K, i+1, 1), maxSumAfterPartitioning1(A, K, i+1, 0));
        /*
        std::vector<int> next_gains(n);
        for(int k = 0; k < n; k++){
            next_gains[k] = maxSumAfterPartitioning(A, K, i+k, k+1);
           // printf("N=%d %d\n",k, next_gains[k]);
        }
        

        int next_gain = *std::max_element(next_gains.begin(), next_gains.end());
        int next_index = std::min_element(next_gains.begin(), next_gains.end()) - next_gains.begin();
        */
        printf(">> %d %d %d\n", i, current_gain, next_gain);
        //exit;
        return((this_gain > next_gain) ? this_gain : next_gain);
    }
};