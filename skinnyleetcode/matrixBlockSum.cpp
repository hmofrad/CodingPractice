/*
 *  https://leetcode.com/problems/matrix-block-sum/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = (m) ? mat[0].size() : 0;
        //printf("%d %d\n", m, n);
        vector<vector<int>> grid(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = i - K; k <= i + K; k++) {
                    //if (k < 0 and k >= m) break;
                    for(int l = j - K; l <= j + K; l++) {
                       // printf("%d %d %d %d\n", i, j, k, l);
                        if (k >= 0 and k < m and l >= 0 and l < n) 
                        //if (l < 0 and l > n) break;
                            grid[i][j] += mat[k][l];
                    }
                }
            }
        }
        
        return(grid);
    }
};
