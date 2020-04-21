/*
 *  https://leetcode.com/problems/validate-stack-sequences/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> stack;
        int m = pushed.size();
        int j = 0;
        for(int v: pushed) {
            stack.push(v);
            while(not stack.empty() and j < m and stack.top() == popped[j]) {stack.pop(); j++;}
        }
        return j == m;
    }
    bool validateStackSequences1(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> stack;
        int i = 0;
        int pu_len = pushed.size();
        int j = 0;
        int po_len = popped.size();
        while(i < pu_len and j < po_len) {
            if(stack.empty() and i < pu_len) stack.push(pushed[i++]);
            while(not stack.empty() and j < po_len and popped[j] != stack.top() and i < pu_len) stack.push(pushed[i++]);
            while(not stack.empty() and j < po_len and popped[j] == stack.top()) {stack.pop(); j++;}
        }
        
        return i == pu_len and j == po_len;
    }
};