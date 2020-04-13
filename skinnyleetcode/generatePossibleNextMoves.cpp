/*
 *  https://leetcode.com/problems/flip-game/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        std::vector<std::string> moves;
        int length = s.length();
        int i = 0;
        while(i <= length-2) {
            if(s[i] == '+' and s[i+1] == '+') {
                std::string first = s.substr(0,i); 
                std::string second = s.substr(i+2,length-i-2);
                std::string minus = "--";
                moves.push_back(first+minus+second);
            }
            i++;
        }
        return moves;
    }
};