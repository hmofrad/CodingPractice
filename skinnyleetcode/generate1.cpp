/*
 *	https://leetcode.com/problems/pascals-triangle/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //numRows=3;
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++) {
            int ncols = i+1;
            std::vector<int> col(ncols, 1);
            //printf("%d %d\n",i, ncols);
            for(int j = 1; j < ncols-1; j++) {
                //printf("%d[%d %d] %d %d %d\n", j, i-1, j-1, ans[i-1][j-1], ans[i-1][j], -col[j]);
                col[j] = ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(col);
        }
        return ans;
    }
};