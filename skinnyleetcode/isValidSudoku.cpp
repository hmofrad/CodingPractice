/*
 * https://leetcode.com/problems/valid-sudoku/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int nrows = board.size();
        int ncols = nrows ? board[0].size() : 0;
        
        std::vector<std::unordered_set<char>> rows(nrows);
        std::vector<std::unordered_set<char>> cols(ncols);
        for(int i = 0; i < nrows; i+=3) {
            for(int j = 0; j < ncols; j+=3) {
                std::unordered_set<char> box;
                for(int k = i; k < i+3; k++) {
                    for(int l = j; l < j+3; l++) {
                        char c = board[k][l];
                        if(c != '.' and c != ',') {
                            if((rows[k].insert(c).second == false) or
                               (cols[l].insert(c).second == false) or
                               (box.insert(c).second == false)) { return false; }
                        }
                    }
                }
            }
        }
        return true;
    }
};