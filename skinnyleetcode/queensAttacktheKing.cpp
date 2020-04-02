/*
 *  https://leetcode.com/problems/queens-that-can-attack-the-king/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<vector<int>> grid;
    vector<int> my_king;
    bool attack(int row, int col) {
        if((grid[row][col] == 0) or (grid[row][col] == 2)) return false;
        if(row == my_king[0]) {
            int dc = (my_king[1] > col) ? +1 : -1;
            for(int j = col+dc; j != my_king[1]; j+=dc) {
                if(grid[row][j] == 1) return false;
            }
        }
        else if (col == my_king[1]) {
            int dr = (my_king[0] > row) ? +1 : -1;
            for(int i = row+dr; i != my_king[0]; i+=dr) {
                if(grid[i][col] == 1) return false;
            }
        }
        else if (abs(row - my_king[0]) == abs(col - my_king[1])) {
            int dr = (my_king[0] > row) ? +1 : -1;
            int dc = (my_king[1] > col) ? +1 : -1;
            for(int i = row+dr, j = col+dc; i != my_king[0] and j != my_king[1]; i+=dr, j+=dc) {
                if(grid[i][j] == 1) return false;
            }
        }
        else {
            return false;
        }
        //printf(">>>%d %d\n", row, col);
        return true;
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        /*
        int m = 0;
        int n = 0;
        for(auto queen: queens) {
            m = (queen[0] > m) ? queen[0] : m;
            n = (queen[1] > n) ? queen[1] : n;
        }
        
        m = (m) ? m+1 : m;
        n = (n) ? n+1 : n;
        grid.resize(m);
        for(int i = 0; i < m; i++) {
            grid[i].resize(n);
        }
        */
        
        grid.resize(8);
        for(int i = 0; i < 8; i++) {
            grid[i].resize(8);
        }

        my_king = king;
        grid[my_king[0]][my_king[1]] = 2;
        
        for(auto queen: queens) {
            grid[queen[0]][queen[1]] = 1;
        }
        
        std::vector<std::vector<int>> ret;
        for(auto queen: queens) {
            if(attack(queen[0], queen[1])) {ret.push_back({queen[0], queen[1]});}
           // break;
        }
        
        /*   
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(attack(i, j)) {ret.push_back({i,j});}
            }
        }
        */
        return(ret);
    }
};