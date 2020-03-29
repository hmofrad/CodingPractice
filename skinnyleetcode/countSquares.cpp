/*
 *  https://leetcode.com/problems/count-square-submatrices-with-all-ones/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    int countSquares1(vector<vector<int>> matrix, int r) {
        int m = matrix.size();
        int n = (m) ? matrix[0].size() : 0;
        int count = 0;
        int c1 = r * r;
        for(int i = 0; i <= m-r; i++) {
            for(int j = 0; j <= n-r; j++) {
                //printf("i=%d j=%d\n", i, j);
                int c = 0;
                for(int k = i; k < i+r; k++) {
                    for(int l = j; l < j+r; l++) {
                        //printf("k=%d l=%d\n", k,l);
                        //if(k>m and l>n) break;
                          //  break;
                        //}
                        //else {
                            if(matrix[k][l])
                                c++;
                            else 
                                break;
                        //}
                    }
                }
                
                if(c == c1) {
                    //printf("i=%d j=%d c=%d\n", i, j, c);
                    count++;
                }
            }
        }
        return(count);
    }
    int countSquares0(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = (m) ? matrix[0].size() : 0;
        int r = (m > n) ? n : m;
        int c = 0;
        //printf("%d\n", r);
        for(int i = 1; i <= r; i++) {
            c += countSquares1(matrix, i);
        }
        return(c);
    }
    
    
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = (m) ? matrix[0].size() : 0;
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            if(matrix[i][0]) dp[i][0] = 1;
        }
        
        for(int j = 0; j < n; j++) {
            if(matrix[0][j]) dp[0][j] = 1;
        }
        
        /*
[i-1, j-1] [i-1, j]
[i,   j-1] [i  , j] [i, j+1]
           [i+1, j]
        */
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j]) {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                }
            }
        }
        
        int sum = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                sum += dp[i][j];
            }
        }
        
        return(sum);
    }
    
    
};