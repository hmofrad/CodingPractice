/*
 *  https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        std::vector<std::pair<char, int>> stack;
        int len = s.length();
        for(int i = 0; i < len; i++) {
            if(s[i] == '(') stack.push_back({s[i],i});
            else if(s[i] == ')') {
                if(stack.empty()) stack.push_back({s[i],i});
                else if(stack.back().first == ')') stack.push_back({s[i],i});
                else stack.pop_back();
            } 
           // printf("%d %c %d\n", i, s[i], stack.size());
        }
        
        
        std::vector<bool> bitmap(len);
        for(auto s: stack) {
          //  printf("%c %d\n", s.first, s.second);
            bitmap[s.second] = true;
        }
        
        std::string ans;
        for(int i = 0; i < len; i++) {
            if(not bitmap[i]) ans.push_back(s[i]);
        }
        return ans;
        
    }
    string minRemoveToMakeValid1(string s) {
        std::vector<std::pair<char, int>> stack;
        int len = s.length();
        for(int i = 0; i < len; i++) {
           // printf("%c %d\n", s[i], stack.size());
            if(s[i] == ')') {
                while(not stack.empty() and stack.back().first != '(' and stack.back().first != ')') stack.pop_back();
                if(not stack.empty() and stack.back().first == '(') stack.pop_back();
                else stack.push_back({s[i],i});
            }
            else {
                stack.push_back({s[i], i});
            }
        }
        
       // for(auto s: stack) {
         //   printf("<%c %d>\n", s.first, s.second);
        //}
        
        
        std::vector<bool> bitmap(len);
        for(auto s: stack) {
            if(s.first == '(' or s.first == ')') bitmap[s.second] = true;
        }
        
        std::string ans;
        for(int i = 0; i < len; i++) {
            if(not bitmap[i]) ans.push_back(s[i]);
        }
        
        return ans;
    }
};