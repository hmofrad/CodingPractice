/*
 * https://leetcode.com/problems/remove-k-digits/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.empty() or k<0 or k>=num.length()) { return "0"; }
        int len = num.length();
        std::stack<char> stack;
        
        for(char d: num) {
            while(not stack.empty() and k and stack.top()>d) {
                stack.pop();
                k--;
            }
            stack.push(d);
        }
        
        while(not stack.empty() and k) { stack.pop(); k--; }
        
        std::string ans;
        while(not stack.empty()) {
            ans.push_back(stack.top());
            stack.pop();
        }
        while(not ans.empty() and ans.back()=='0') { ans.pop_back(); }
        
        std::reverse(ans.begin(), ans.end());
        return ans.empty() ? "0" : ans;
    }
};
















class Solution0 {
public:
    string removeKdigits(string num, int k) {
            if ((uint32_t) k == num.size()) {
        return("0");
    }        
    
    std::string res;
    for (uint32_t i = 0; i < num.size(); i++) {
        if (((i - k) == res.size()) or (res.empty())) {
            res.push_back(num[i]);
        } 
        else if ((res.back() > num[i]) and ((res.size() + k) > i)) {
            do {
                res.pop_back();
            } while ((res.back() > num[i]) and ((res.size() + k) > i));
            res.push_back(num[i]);
        } 
        else if (res.size() < (num.size() - k)) {
            res.push_back(num[i]);
        }
    }
    //printf("%s\n", res.c_str());
    uint32_t i = 0;
    while((i < res.size()) and (res[i] == '0')) i++; 

    return((i == res.size()) ? "0" : res.substr(i));
    }
};