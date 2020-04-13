/*
 *  https://leetcode.com/problems/minimum-falling-path-sum/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    void dfs(vector<vector<int>>& A, int row, int col, int last, int sum) {
        int nrows = A.size();
        int ncols = A.size();
        if(row == nrows) {if(sum < minSum) minSum = sum; return;}
        
        for(int j = 0; j < ncols; j++) {
            if(A[row][j] != last) {
                last = A[row][j];
                //sum += last;
                dfs(A, row+1, 0, last, sum+last);
            }
        }
    }
    int minSum = INT_MAX;
    int minFallingPathSum1(vector<vector<int>>& A) {
        int nrows = A.size();
        int ncols = A.size();
       // int minSum = INT_MAX;
        for(int j = 0; j < ncols; j++) {
            dfs(A, 1, 0, A[0][j], A[0][j]);
            //minSum = min(minSum, dfs(A, 1, 0, A[0][j] A[0][j]))
        }
        return(minSum);
    }
    
    
int dfs1(vector<vector<int>>& A, int row, int col, std::vector<std::vector<int>>& cache) {
    int nrows = A.size();
    int ncols = A.size();
    if(row == nrows-1) return A[row][col];
    
    if(cache[row][col] != INT_MAX) return cache[row][col];
    
    
     int sum = A[row][col] + min({dfs1(A, row+1, col, cache), 
                 dfs1(A, row+1, max(0,col-1), cache), 
                 dfs1(A, row+1, min(ncols-1,col+1), cache)}) ;
    cache[row][col]=sum;
    return(sum);
}
    
    
int minFallingPathSum2(vector<vector<int>>& A) {
    int nrows = A.size();
    int ncols = A.size();
    int mySum = INT_MAX;
    
    std::vector<std::vector<int>> cache(nrows, std::vector<int>(ncols, INT_MAX));
    
    for(int j = 0; j < ncols; j++) {
        mySum = min(mySum, dfs1(A, 0, j, cache));
    }
    return(mySum);    

}
int minFallingPathSum(vector<vector<int>>& A) {
    int nrows = A.size();
    int ncols = nrows;
    
    for(int i = nrows-2; i >= 0; i--) {
        for(int j = 0; j < ncols; j++) {
            A[i][j] += min({A[i+1][max(0, j-1)], 
                            A[i+1][j], 
                            A[i+1][min(ncols-1, j+1)]});
        }
    }
    return *min_element(A[0].begin(), A[0].end());
}
    
    
   /* 
int minFallingPathSum(vector<vector<int>>& A) {
        int R = A.size(), C = A[0].size();
        vector<vector<int>> dp(2, vector<int>(C, 0));
        for(int j = 0; j < C; ++j) dp[1][j] = A[R-1][j];
        for(int i = R-2; i >= 0; --i) {
            for(int j = 0; j < C; ++j) {
                dp[0][j] = dp[1][j];
                if(j > 0) dp[0][j] = min(dp[0][j], dp[1][j-1]);
                if(j < C-1) dp[0][j] = min(dp[0][j], dp[1][j+1]);
                dp[0][j] += A[i][j];
            }
            swap(dp[0], dp[1]);
        }
        return *min_element(dp[1].begin(), dp[1].end());
    }    
    */
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};