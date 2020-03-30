/*
 *  https://leetcode.com/problems/candy-crush/submissions/
 *  g++ -o numUniqueEmails numUniqueEmails.cpp && ./numUniqueEmails
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int nrows;
    int ncols;
    
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        nrows = board.size();
        ncols = board[0].size();
        bool todo = false;
        
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j+2 < ncols; j++) {
                int v = abs(board[i][j]);
                if(v and v == abs(board[i][j+1]) and v == abs(board[i][j+2])) {
                    board[i][j] =  -v;
                    board[i][j+1] = -v;
                    board[i][j+2] = -v;
                    todo = true;
                }   
            }
        }
        
        for(int i = 0; i+2 < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                int v = abs(board[i][j]);
                if(v and v == abs(board[i+1][j]) and v == abs(board[i+2][j])) {
                    board[i][j] = -v;
                    board[i+1][j] = -v;
                    board[i+2][j]= -v;
                    todo = true;
                }   
            }
        }
        
        for(int j = 0; j < ncols; j++) {
            int write = nrows-1;
            for(int i = nrows-1; i >= 0; i--) {
                if(board[i][j] > 0) {
                    board[write][j] = board[i][j];
                    write--;
                }
           }
            while(write >= 0) {board[write][j] = 0; write--;}
        }
        return todo ? candyCrush(board) : board;
    }
};