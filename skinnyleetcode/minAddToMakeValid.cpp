/*
 *  https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int minAddToMakeValid1(string S) {
        std::vector<char> stack;
        int n = 0;
        for(auto c: S) {
            if(stack.empty()) {
                stack.push_back(c);
            }
            else {
                if((stack.back() == ')' and c == ')') or 
                   (stack.back() == '(' and c == '(') or 
                  (stack.back() == ')' and c == '(')) {
                    stack.push_back(c);
                }
                else {
                    stack.pop_back();
                }
            }
        }
        return(stack.size());
    }
    
    int minAddToMakeValid(string S) {
        std::vector<char> stack;
        int n = 0;
        int ans = 0;
        int bal = 0;
        for(auto c: S) {
           // printf("%c %d %d\n", c, ans, bal);
             bal += (c == '(') ? 1 : -1;
            if (bal == -1) {
                ans++;
                bal++;
            }
        }
        return(ans+bal);
    }
    
};