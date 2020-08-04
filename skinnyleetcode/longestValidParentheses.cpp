/*
 * https://leetcode.com/problems/longest-valid-parentheses/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int max_len = 0;
        std::stack<int> stack;
        stack.push(-1);
        for(int i = 0; i < len; i++) {
            if(s[i]=='(') { stack.push(i); }
            else {
                stack.pop();
                if(stack.empty()) { stack.push(i); }
                else { max_len = max(max_len, i-stack.top()); }
            }
        }
        return max_len;
    }
};