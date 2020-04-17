/*
 *  https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    void reverse1(std::string& s, int start, int end) {
        //printf("", start, end,start-end)/2);
        for(int i = 0; i <= (end-start)/2; i++) {
           // printf("%d %d %d\n", i, start+i, end-i);
            std::swap(s[start+i], s[end-i]);
        }
    }
    
    string reverseParentheses(string s) {
        int len = s.length();
        int start = 0;
        int end = len-1;
        std::vector<int> stack;
        for(int i = 0; i < len; i++) {
            if(s[i] == '(') stack.push_back(i+1);
            else if(s[i]==')') {
                int start = stack.back();
                stack.pop_back();
                int end = i-1;
                reverse1(s, start, end);
                //std::reverse(s.begin()+start, s.begin()+end+1);
               // printf("%d, [%d %d] [%c %c] %s\n", i, start, end, s[start], s[end], s.c_str());
            }
        }
                
        std::string t;
        for(char c: s) {
            if(c != '(' and c != ')') t.push_back(c);
        }
        return t;
    }
    
    string reverseParentheses1(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start < end) {
            if(s[start] == '(') { 
                while(s[end] != ')') end--;
                start++;
                end--;
                reverse1(s, start, end);
            }
            else start++;
        }
        
        std::string t;
        for(char c: s) {
            if(c != '(' and c != ')') t.push_back(c);
        }
        return t;
    }
};
