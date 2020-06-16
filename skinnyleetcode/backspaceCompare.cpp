/*
 * https://leetcode.com/problems/backspace-string-compare/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::string backspacing1(std::string S) {
        std::string s;
        for(char c: S) {
            if(c!='#') s.push_back(c);
            else if(not s.empty()) s.pop_back();
        }
        return s;
    }
    
    std::string backspacing(std::string S) {
        std::string s;
        int b=0;
        for(int i = S.length()-1; i >= 0; i--) {
            if(S[i]!='#') {s.push_back(S[i]); b = 0;}
            else {
                b++;
                while(i>0 and S[i-1]!='#' and b) {i--; b--;}
            }
        }
        std::reverse(s.begin(), s.end());
        return s;
    }
    bool backspaceCompare(string S, string T) {
        //S="ab##";
        //T="c#d#";
        //return backspacing(S) == backspacing(T);
        return backspacing1(S) == backspacing1(T);
    }
};