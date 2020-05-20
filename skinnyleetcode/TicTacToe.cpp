/*
 *	https://leetcode.com/problems/design-tic-tac-toe/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class TicTacToe {
public:
    std::vector<int> rows;
    std::vector<int> cols;
    int diagonals;
    int antidiagonals;
    int n;
    TicTacToe(int n_) {
        n = n_;
        rows.resize(n);
        cols.resize(n);
        diagonals = 0;
        antidiagonals = 0;
    }

    int move(int row, int col, int player) {
        int add = (player == 1) ? +1 : -1;
        rows[row] += add;
        cols[col] += add;
        diagonals += (row==col) ? add : 0;
        antidiagonals += (row+col == n-1) ? add : 0;
        return abs(rows[row]) == n or  abs(cols[col]) == n or  abs(diagonals) == n or  abs(antidiagonals) == n ? player : 0;
    }
};



class TicTacToe1 {
public:
    /** Initialize your data structure here. */
    int n = 0;
    std::vector<std::vector<int>> board;
    TicTacToe1(int n_) {
        n = n_;
        board.resize(n);
        for(std::vector<int>& row: board) row.resize(n);
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col]=player;
        return check();
    }
    int check() {
        for(int i = 0; i < n; i++) {
            int won = board[i][0];
            for(int j = 1; j < n; j++) {
                if(board[i][j]==0 or board[i][j]!=board[i][j-1]) {won = 0; break;}
            }
            if(won) return won;
        }
        
        for(int j = 0; j < n; j++) {
            int won = board[0][j];
            for(int i = 1; i < n; i++) {
                if(board[i][j]==0 or board[i][j]!=board[i-1][j]) {won = 0; break;}
            }
            if(won) return won;
        }
        
        {
            int won = board[0][0];
            for(int i = 1; i < n; i++) {
                if(board[i][i]==0 or board[i][i]!=board[i-1][i-1]) {won = 0; break;}
                
            }
            if(won) return won;
        }
        
        {
            int won = board[0][n-1];
            for(int j = n-2; j >= 0; j--) {
                if(board[n-1-j][j]==0 or board[n-1-j][j]!=board[n-1-j-1][j+1]) {won = 0; break;}
                
            }
            if(won) return won;
        }
        return 0;
        
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */