/*
 * https://leetcode.com/problems/word-search/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool dfs1(vector<vector<char>>& board, string word, int index, int row, int col) {
        //printf("%d %d %d\n", row, col, index);
        if(index==word.size()) {return true;}
        int nrows = board.size();
        int ncols = nrows ? board[0].size() : 0;
        if(row<0 or row>=nrows or col<0 or col>=ncols or board[row][col]!=word[index]) return false;
        bool ret = false;
        board[row][col]='#';
        
        std::vector<int> r = {1,-1,0,0};
        std::vector<int> c = {0,0,1,-1};
        
        for(int i = 0; i < 4; i++) {
            ret = dfs1(board, word, index+1, row+r[i], col+c[i]);
            if(ret) break;
        }
        board[row][col]=word[index];
        return ret;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int index, int row, int col, std::set<std::pair<int, int>> visited) {
        if(index==word.size()) {return true;}
        //printf("%d %d %d %d\n", row, col, index, visited.size());
        if(index==word.size()) {return true;}
        int nrows = board.size();
        int ncols = nrows ? board[0].size() : 0;
        if(row<0 or row>=nrows or col<0 or col>=ncols or board[row][col]!=word[index] or visited.count({row, col})) return false;
         
        visited.insert({row, col});
        
        
        return (dfs(board, word, index+1, row+1, col, visited) |
        dfs(board, word, index+1, row-1, col, visited) |
        dfs(board, word, index+1, row, col+1, visited) |
        dfs(board, word, index+1, row, col-1, visited));
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        //board={{"A","B","C","E"},{"S","F","E","S"},{"A","D","E","E"}};
       // word="ABCESEEEFS";
        int nrows = board.size();
        int ncols = nrows ? board[0].size() : 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(board[i][j] == word.front()) {
                    //std::set<std::pair<int, int>> visited;
                    //if(dfs(board, word, 0, i, j, visited)) return true;
                    if(dfs1(board, word, 0, i, j)) return true;
                }
            }
        }
       return false;
    }
};