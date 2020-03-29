/*
 *  https://leetcode.com/problems/battleships-in-a-board/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = (m) ? board[0].size() : 0;
        int c = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'X') {
                    if(i and board[i-1][j] == 'X') continue;
                    if(j and board[i][j-1] == 'X') continue;
                    c++;
                }
            }
        }
        return(c);
    }
};