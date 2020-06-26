/*
 * https://leetcode.com/problems/spiral-matrix/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        int size = m*n;
        std::vector<int> vec(size); int idx = 0;
        int left = 0, right = n-1;
        int up = 0, down = m-1;
        int row = 0, col = 0;
        while(true) {
            for(int j = left; j <= right; j++) vec[idx++]=matrix[up][j];
            if(idx==size) break;
            
            for(int i = up+1; i <= down; i++) vec[idx++]=matrix[i][right];
            if(idx==size) break;

            for(int j = right-1; j >= left; j--) vec[idx++]=matrix[down][j];
            if(idx==size) break;

            for(int i = down-1; i >= up+1; i--) {vec[idx++]=matrix[i][left];}
            if(idx==size) break;

            left++;
            right--;
            up++;
            down--;
        }
        return vec;
    }
};