/*
 *  https://leetcode.com/problems/xor-queries-of-a-subarray/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    std::vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int m = arr.size();
        std::vector<int> dp(m);
        dp[0] = arr[0];
        for(int i = 1; i < m; i++) {
            dp[i] = dp[i-1]^arr[i];
        }
        
        std::vector<int> answers;
        int n = queries.size();
        for(int i = 0; i < n; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            if(l == 0) answers.push_back(dp[r]);
            else answers.push_back(dp[l-1]^dp[r]);
        }
        
        return(answers);
    }

    
    
    
    vector<int> xorQueries2(vector<int>& arr, vector<vector<int>>& queries) {
        int m = arr.size();
        std::vector<std::vector<int>> dp(m);
        
        for(int i = 0; i < m; i++) {
            dp[i].push_back(arr[i]);
            for(int j = i+1; j < m; j++) {
                dp[i].push_back(dp[i].back()^arr[j]) ;
            }
        }
        /*
        for(int i = 0; i < dp.size(); i++) {
            printf("%d:", i);
            for(int j = 0; j < dp[i].size(); j++) {
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
        */
        
        std::vector<int> answers;
        int n = queries.size();
        for(int i = 0; i < n; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            answers.push_back(dp[l][r-l]);
        }
        
        return(answers);
    }
    
    
    
    
    
    
    
    
    
    
    vector<int> xorQueries1(vector<int>& arr, vector<vector<int>>& queries) {
        std::vector<int> answers;
        int m = queries.size();
        for(int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int ans = arr[l];
            for(int j = l+1; j <= r; j++) {
                ans ^= arr[j];
            }
            answers.push_back(ans);
        }
        return(answers);
    }
};