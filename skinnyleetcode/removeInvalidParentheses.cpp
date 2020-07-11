/*
 * https://leetcode.com/problems/remove-invalid-parentheses/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    void misplaced(std::string& s, int& left, int& right) {
        std::stack<char> stack;
        for(char c: s) {
            if(c == '(' or c == ')') {
                if(stack.empty()) { stack.push(c); if(c== '(') { left++; } else { right++; } }
                else {
                    if(c== '(') { stack.push(c); left++; }
                    else {
                        if(stack.top() == '(') {
                            stack.pop();
                           left--; 
                        }
                        else { stack.push(c); right++; }
                    }
                }
            }
        }
    }
    
    bool balanced(std::string& s) {
        int balance = 0;
        for(char c: s) {
            if(c=='(') { balance++; }
            else if(c==')') { balance--; }
            if(balance<0) { return false; }
        }
        return true;
    }
    
    void dfs(std::string s, std::vector<std::string>& ans, int i0, int j0, char pl, char pr) {
        int len = s.length();
        for(int i = i0, b = 0; i < len; i++) {
            char c = s[i];
            if(c == pl) { b++; }
            else if(c==pr) { b--; }
            if(b<0) {
                for(int j = j0; j <= i; j++) {
                    if(s[j] == pr and (j == j0 or  s[j-1] != pr)) { dfs(s.substr(0, j) + s.substr(j+1), ans, i, j, pl ,pr); }
                }
                return;
            }
        }
        std::reverse(s.begin(), s.end());
        if(pl=='(') { dfs(s, ans, 0, 0, ')','('); }
        else { ans.push_back(s); }
                                               
    }
    
    vector<string> removeInvalidParentheses(string s) {
        std::vector<std::string> ans;
        dfs(s, ans, 0, 0, '(',')');
        return ans;
    }
};