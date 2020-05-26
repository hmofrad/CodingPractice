/*
 *	https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::string check(std::vector<int>& rows, std::vector<int>& cols, std::vector<int>& diags, std::vector<int>& adiags, int row, int col) {
        std::string res = "Pending";
        if(rows[row]==3) res = "A";
        else if(rows[row]==-3) res = "B";
        else if(cols[col]==3) res = "A";
        else if(cols[col]==-3) res = "B";
        else if(diags[0]+diags[1]+diags[2] == 3) res = "A";
        else if(diags[0]+diags[1]+diags[2] == -3) res = "B";
        else if(adiags[0]+adiags[1]+adiags[2] == 3) res = "A";
        else if(adiags[0]+adiags[1]+adiags[2] == -3) res = "B";
        else res = "Pending";
        return res;
    }
    string tictactoe(vector<vector<int>>& moves) {
        //moves={{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
        std::string res="Draw";
        std::vector<int> rows(3);
        std::vector<int> cols(3);
        std::vector<int> diags(3);
        std::vector<int> adiags(3);
        int size = moves.size();
        for(int i = 0; i < size; i++) {
            int row = moves[i][0];
            int col = moves[i][1];
            rows[row] += i%2 ? -1 : +1;
            cols[col] += i%2 ? -1 : +1;
            diags[col] = (row==col) ? i%2 ? -1 : +1 : diags[col];
            adiags[col] = (row+col==2) ? i%2 ? -1 : +1 : adiags[col];
            res = check(rows, cols, diags, adiags, row, col);
            //printf("%s\n", res.c_str());
            //printf("%d %d %d %d %d\n", row, col, diags[0], diags[1], diags[2]);
            //printf("%d %d %d %d %d\n", row, col, adiags[0], adiags[1], adiags[2]);
        }
        return size==9 and res=="Pending" ? "Draw" : res;
    }
};