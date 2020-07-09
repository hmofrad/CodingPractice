/*
 * https://leetcode.com/problems/basic-calculator/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool is_digit(char c) { return c>='0' and c<='9'; }
    
    int calculate(string s) {
        //s="2147483647";
        std::stack<int> stack;
        int sign = 1;
        int ans = 0;
        int len = s.length();
        int i = 0;
        while(i<len) {
            char c = s[i];
            if(is_digit(c)) {
                long sum = s[i]-'0';
                while(i+1<len and is_digit(s[i+1])) {
                    sum = sum*10 + s[i+1]-'0';
                    i++;
                }
                ans += sum * sign;
            }
            else if(c=='+') {
                sign=1;
            }
            else if(c=='-'){
                sign=-1;
            }
            else if(c=='('){
                stack.push(ans); ans=0;
                stack.push(sign); sign=1;
            }
            else if(c==')') {
                ans = ans*stack.top(); stack.pop();
                ans += stack.top(); stack.pop();
            }
            i++;
        }
        return ans;
    }
};
