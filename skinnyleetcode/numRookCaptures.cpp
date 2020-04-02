/*
 *  https://leetcode.com/problems/available-captures-for-rook/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int m = board.size();
        int n = (m) ? board[0].size() : 0;
        
        std::vector<int> rook(2);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'R') {
                    rook = {i, j};
                    break;
                }
            }
        }
        
        //printf("%d %d\n", rook[0], rook[1]);
        int count = 0;
        for(int j = rook[1]+1; j < n; j++) {
            if(board[rook[0]][j] == '.') continue;
            else if(board[rook[0]][j] == 'p') {count++; break;}
            else break;
        }
        
        for(int j = rook[1]-1; j >= 0; j--) {
            if(board[rook[0]][j] == '.') continue;
            else if(board[rook[0]][j] == 'p') {count++; break;}
            else break;
        }
        
        for(int i = rook[0]+1; i < m; i++) {
            if(board[i][rook[1]] == '.') continue;
            else if(board[i][rook[1]] == 'p') {count++; break;}
            else break;
        }
        
        for(int i = rook[0]-1; i >= 0; i--) {
            if(board[i][rook[1]] == '.') continue;
            else if(board[i][rook[1]] == 'p') {count++; break;}
            else break;
        }
        
        
        return(count);
    }
};