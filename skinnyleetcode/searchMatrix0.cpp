/*
 * https://leetcode.com/problems/search-a-2d-matrix/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nrows = matrix.size();
        int ncols = nrows ? matrix[0].size() : 0;
        int left = 0, right = nrows*ncols-1;
        while(left<=right) {
            int index = left + (right-left)/2;
            int element = matrix[index/ncols][index%ncols];
            if(target == element) { return true; }
            else if(target < element) { right = index-1; }
            else { left = index+1; }
        }
        return false;
    }
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        //matrix={{1},{3}}; target=3;
        //matrix={{1,3,5,7},{10,11,16,20},{23,30,34,50}};
        //target=13;
        int nrows = matrix.size();
        int ncols = nrows ? matrix[0].size() : 0;
        
        int left = 0, right = ncols-1;
        int down = 0, up = nrows-1;
        //printf("%d %d\n", nrows, ncols);
        while(left<=right and down<=up) {
            int left0 = left;
            int right0 = right;
            int down0 = down;
            int up0 = up;
            int r = down + (up-down)/2;
            int c = left + (right-left)/2;
            printf("%d: [%d %d] [%d %d] [%d %d]\n", target, left, right, down, up, r, c);
            if(matrix[r][c] == target) { return true;}
            else if(down != up) {
                if(matrix[r][c] < target) { down = r; }
                else { up = r; }
            }
            else {
                if(matrix[r][c] < target) {left = c+1; }
                else { right = c-1; }
            }
            
            if(left == left0 and right == right0 and down == down0 and up == up0) break;
        }
        return false;
    }
};