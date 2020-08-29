/*
 * https://leetcode.com/problems/basic-calculator-ii/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        std::stack<int> stack;
        int d = 0;
        char op = '+';
        for(int i = 0; i < len; i++) {           
            char c = s[i];
            if((c>='0' and c<='9')) {
                d = d*10 + (c-'0');
            }
            

            if(c == '+' or c == '-' or c == '*' or c == '/' or i==len-1) {
                if(op=='+') { stack.push(d); }
                else if(op=='-') { stack.push(-d); }
                else if(op=='*') {
                    int v = stack.top();
                    stack.pop();
                    stack.push(v*d);
                }
                else if(op=='/') {
                    int v = stack.top();
                    stack.pop();
                    stack.push(v/d);
                }
                op=c;
                d=0;
            }
        }
        int ans = 0;
        while(not stack.empty()) { ans += stack.top(); stack.pop(); }
        return ans;
    }
};