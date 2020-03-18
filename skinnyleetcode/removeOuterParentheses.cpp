/*
 *  Problem: https://leetcode.com/problems/remove-outermost-parentheses/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    string removeOuterParentheses(string S) {
        std::vector<char> s1;
        std::vector<char> s2;
        std::string out;
        for(int i = 0; i < S.length(); i++) {
            char c = S[i];
            if(c == '(')
                s1.push_back(c);
            else 
               s2.push_back(c);
            if(s1.size() == s2.size())  {
                int i1 = i+1-(s1.size() + s2.size());
                int l1 = i+1-i1;
                //printf("%d %d\n",  i1+1, l1-2) ;
                out += S.substr(i1+1, l1-2);
                s1.clear();
                s2.clear();
            }
        }
        
        return(out);
    }
};