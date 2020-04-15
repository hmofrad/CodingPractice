/*
 *  https://leetcode.com/problems/reshape-the-matrix/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int nrows = nums.size();
        int ncols = (nrows) ? nums[0].size() : 0;
        
        if(nrows*ncols != r*c) return nums;
        
        std::vector<std::vector<int>> nums1(r, std::vector<int>(c));
        
        int k = 0;
        int l = 0;
        int m = 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                k = m/c;
                l = m%c;
                nums1[k][l] = nums[i][j];
                m++;
            }
        }
        
        return nums1;
    }
};