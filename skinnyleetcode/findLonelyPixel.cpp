/*
 *  https://leetcode.com/problems/lonely-pixel-i/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool dfs(vector<vector<char>>& picture, int row, int col) {
        int nrows = picture.size();
        int ncols = nrows ? picture[0].size() : 0;
        if(row < 0 or row >= nrows or col < 0 or col >= ncols) return false;
        if(picture[row][col] == 'W') return false;
        bool me = true;
        
        bool others = dfs(picture, row, col-1) or 
                      dfs(picture, row, col+1) or 
                      dfs(picture, row-1, col) or  
                      dfs(picture, row+1, col);
        return me and not others;
    }
    
    int findLonelyPixel1(vector<vector<char>>& picture) {
        int nrows = picture.size();
        int ncols = nrows ? picture[0].size() : 0;
        
        int count = 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(picture[i][j] == 'B')
                    count += dfs(picture, i, j);
            }
        }
            
        return count;
    }
    int findLonelyPixel(vector<vector<char>>& picture) {
        int nrows = picture.size();
        int ncols = nrows ? picture[0].size() : 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                auto& row = picture[i];
                int b_count = std::count(row.begin(), row.end(), 'B');
                if(b_count == 1) {
                    auto it = std::find(row.begin(), row.end(), 'B'); *it='S';
                }
            }
        }
        
        int count = 0;
        for(int j = 0; j < ncols; j++) {
            int s = 0;
            int b = 0;
            for(int i = 0; i < nrows; i++) {
                s += picture[i][j] == 'S' ? 1 : 0;
                b += picture[i][j] == 'B' ? 1 : 0;
            }
            if(b==0 and s==1) count++;
        }
        return count;
            
    }
};