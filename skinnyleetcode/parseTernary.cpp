/*
 *	https://leetcode.com/problems/ternary-expression-parser/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    string parseTernary(string expression) {
        std::string ans;
        if(expression.empty()) return ans;
        
        std::stack<char> stack;
        int len = expression.length();
        
        for(int i = len-1; i >= 0; i--) {
            char c = expression[i];
            if(not stack.empty() and stack.top()=='?') {
                stack.pop(); // ?
                char first = stack.top(); stack.pop();
                stack.pop(); // :
                char second = stack.top(); stack.pop();
                
                if(c=='T') stack.push(first);
                else stack.push(second);
                
            }
            else { stack.push(c); }
        }
        ans = stack.top();
        return ans;
    }
};