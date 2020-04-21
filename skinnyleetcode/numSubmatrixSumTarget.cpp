/*
 *  https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int nrows = matrix.size();
        int ncols = nrows ? matrix[0].size() : 0;

        std::vector<std::vector<int>> two_d_prefix_sum(nrows+1, std::vector<int>(ncols+1));
        for(int i = 1; i <= nrows; i++) {
            for(int j = 1; j <= ncols; j++) {
                two_d_prefix_sum[i][j] = two_d_prefix_sum[i][j-1]   + 
                                         two_d_prefix_sum[i-1][j]   -
                                         two_d_prefix_sum[i-1][j-1] + 
                                         matrix[i-1][j-1];
            }   
        }
        /*
        for(auto row: two_d_prefix_sum) {
            for(auto col: row) {
                printf("%d ", col);
            }
            printf("\n");
        }
        printf("\n");
        */
        int count = 0;
        int currSum = 0;
        

        for(int i1 = 1; i1 < nrows+1; i1++) {
            for(int i2 = i1; i2 < nrows+1; i2++) {
                std::unordered_map<int, int> sums;
                for(int j = 1; j < ncols+1; j++) {
                    currSum = two_d_prefix_sum[i2][j]-two_d_prefix_sum[i1-1][j];
                    int diff = currSum-target;
                    if(diff == 0) count++;
                    count += sums[diff];
                    sums[currSum]++;
                }
            }
        }
        return count;
    }
};