/*
 * https://leetcode.com/problems/spiral-matrix/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:

    void print(vector<vector<int>>& matrix) {
        for(auto row: matrix) {
            for(auto co: row) {
                printf("%d ", co);
            }
            printf("\n");
        }
        printf("\n");
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int nrows = matrix.size();
        int ncols = nrows ? matrix[0].size() : 0;
        if(nrows == 0 or ncols == 0) { return std::vector<int>(); }
        vector<int> ans;
        int s = nrows * ncols;
        int k = 0;
        int l = 0;
        int m = (nrows+1)/2;
        //print(matrix);
        do {
            for(int j = l; j < ncols-l; j++) { ans.push_back(matrix[l][j]); }
            k += ncols-2*l;
            if(k==s) {break;}
            
            for(int i = l+1; i < nrows-l; i++) { ans.push_back(matrix[i][ncols-1-l]);}
            k += nrows-1-2*l;
            if(k==s) {break;}

            for(int j = ncols-2-l; j >= l; j--) { ans.push_back(matrix[nrows-1-l][j]); }
            k += ncols-1-2*l;
            if(k==s) {break;}
            
            for(int i = nrows-2-l; i >= l+1; i--) { ans.push_back(matrix[i][l]); }
            k += nrows-2-2*l;
            if(k==s) {break;}
            l++;
        } while(k<s);
        
        return ans;
    }
    
    
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