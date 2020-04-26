/*
 *  https://leetcode.com/problems/minesweeper/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 class Solution {
public:
    void reveal(vector<vector<char>>& board, int row, int col, int nrows, int ncols) {
        
        if(not onboard(board, row, col, nrows, ncols)) return;
        
        if(board[row][col] == 'E') {
            int count = 0;
            std::vector<std::vector<int>> directions = {{-1,-1},{-1,0},{-1,+1},{0,-1},{0,+1},{+1,-1},{+1,0},{+1,+1}};
            
            for(std::vector<int> direction: directions) {
                int r = row+direction[0];
                int c = col+direction[1];
                if(onboard(board, r, c, nrows, ncols) and board[r][c]=='M') count++;
            }
            //printf("%d %d | %d %d\n", row, col, nrows, ncols);
            if(count>0) board[row][col]='0'+count;
            else {
                board[row][col]='B';
                for(std::vector<int> direction: directions) {
                    int r = row+direction[0];
                    int c = col+direction[1];
                    reveal(board, r, c, nrows, ncols);
                }
            }
        }
    }
    
    bool onboard(vector<vector<char>>& board, int row, int col, int nrows, int ncols) {
        return row >= 0 and row < nrows and col >= 0 and col < ncols;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0];
        int col = click[1];
        
        if(board[row][col] == 'M') {board[row][col] = 'X'; return board;}
        
        int nrows = board.size();
        int ncols = nrows ? board[0].size() : 0;
        reveal(board, row, col, nrows, ncols);
        
        return board;
    }
};