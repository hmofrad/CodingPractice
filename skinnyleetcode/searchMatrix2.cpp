/*
 * https://leetcode.com/problems/search-a-2d-matrix-ii/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nrows = matrix.size();
        int ncols = nrows ? matrix[0].size() : 0;
        
        int row = nrows-1;
        int col = 0;
        while(row >= 0 and col < ncols) {
            if(matrix[row][col]>target) row--;
            else if(matrix[row][col]<target) col++;
            else return true;
        }
        return false;
    }
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int nrows = matrix.size();
        int ncols = nrows ? matrix[0].size() : 0;
        int left = 0;
        int right= ncols - 1;
        int down = 0;
        int up = nrows - 1;
        
        while(left<=right and down<=up) {
            
            int l = left;
            int r = right;
            int d = down;
            int u = up;
            int row = down + (up-down)/2;
            int col = left + (right-left)/2;
            printf("target=%d: [%d %d] [%d %d] [%d %d] : %d\n", target, left, right, down, up, row, col, matrix[row][col]);
            if(matrix[row][col]==target) { return true; }
            else if(matrix[row][col]>target) {
                if(left!=right) right = col-1;
                if(matrix[row][left] > matrix[row][col]) up=row-1;
                else up=row;
            }
            else {
                if(left!=right)left = col+1;
                if(matrix[row][right] < matrix[row][col]) down=row+1;
                else up=row;
                
            }
            
            if(left == l and right == r and d == down and u == up) { break; }
        }
        
        return false;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    bool searchMatrix0(vector<vector<int>>& matrix, int target) {
    bool found = false;
    
    int m = matrix.size();
    int n = 0;
    if(m) {
        n = matrix[0].size();
    }

    int low = 0;
    int high = 0;
    int mid = 0;
    for(int i = 0; i < m; i++) {
        auto& vector = matrix[i];
        /*
        if(std::find(vector.begin(), vector.end(), target) != vector.end()) {
            found = true;
            break;
        }
        */
        
        low = 0;
        high = n - 1;//vector.size() - 1;
        while(low <= high) {
            //mid = low + (high - low) / 2;
            mid = (low + high) / 2;
            if(vector[mid] == target) {
                found = true;
                break;
            }
            else if(vector[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        if(found) {
            break;
        }  
        
    }
    return(found);    
    }
};