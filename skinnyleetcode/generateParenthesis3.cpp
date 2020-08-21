/*
 * https://leetcode.com/problems/generate-parentheses/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    void backtrack(int n, int m, int open, int close, std::string temp, std::vector<std::string>& ans) {
        if(temp.length() == m) { ans.push_back(temp); return;}
        if(open<n) {
            backtrack(n, m, open+1, close, temp + '(', ans);
        }
        if(close<open) {
            backtrack(n, m, open, close+1, temp + ')', ans);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> ans;
        backtrack(n, 2*n, 0, 0, std::string(), ans);
        return ans;
    }
};


class Solution33 {
public:
    vector<string> combinations(int n) {
        std::vector<std::string> ans;
        if(n==0) {ans.push_back(""); return ans;}
        
        std::vector<std::string> temp0 = combinations(n-1);
        for(std::string& t0: temp0) {
            for(int i = 0; i < t0.size(); i++) {
                if(t0[i]=='(') {
                    std::string t=t0.substr(0, i+1);
                    t += "()";
                    t += t0.substr(i+1);
                    ans.push_back(t);                    
                }
            }
            ans.push_back("()"+ t0);
        }
        return ans;
    }
    
    
    vector<string> backtrack(int n, int m, int open, int close, std::string temp) {
        std::vector<std::string> ans;    
        if(temp.size() == m) { ans.push_back(temp); return ans; }
        
        std::vector<std::string> temp0;
        if(open<n) temp0 = backtrack(n, m, open+1, close, temp+"(");
        std::vector<std::string> temp1;
        if(close<open) temp1 = backtrack(n, m, open, close+1, temp+")");
        ans.insert(ans.begin(), temp0.begin(), temp0.end());
        ans.insert(ans.end(), temp1.begin(), temp1.end());
        return ans;
    }
    
    vector<string> generateParenthesis(int n) {
        //return combinations(n);
        return backtrack(n, 2*n, 0, 0, std::string());
    }
    
    
    
    bool isbalanced1(std::string s) {
        int len = s.size();
        int balanced = 0;
        for(int i = 0; i < len; i++) {
            char c = s[i];
            if(c=='(') balanced++;
            if(c==')') balanced--;
            if(balanced<0) break;
        }
        
        return balanced >= 0;
    }
    
    bool isbalanced(std::string s) {
        int len = s.size();
        int balanced = 0;
        for(int i = 0; i < len; i++) {
            char c = s[i];
            if(c=='(') balanced++;
            if(c==')') balanced--;
            if(balanced<0) break;
        }
        
        return balanced == 0;
    }
    
    void generateParenthesis2(std::vector<std::string>& perms, std::string temp, int open, int close, int max) {
        
        if((temp.size() == 2*max) and isbalanced(temp) and (std::find(perms.begin(), perms.end(), temp) == perms.end())) perms.push_back(temp);
        
        if(open < max) generateParenthesis2(perms, temp+'(', open+1, close, max);
        if(close < max) generateParenthesis2(perms, temp+')', open, close+1, max);

    }
    
    
    int length;
    std::vector<std::string> generateParenthesis1(std::string pairs) {
        
        if(pairs.empty()) {std::vector<std::string> s(1); return s;}
        
        std::vector<std::string> perms;
        
        char c = pairs[0];
        
        pairs.erase(pairs.begin());
        std::vector<std::string> perms1 = generateParenthesis1(pairs);
        //printf(">> %c %s %d\n", c, pairs.c_str(), perms1.size());
        for(std::string p: perms1) {
            int size = p.length();
            for(int i = 0; i <= size; i++) {
                std::string first = p.substr(0, i);
                std::string last = p.substr(i,size-i);
                std::string temp = first + c + last;
                if((temp.length() < length) or ((temp.length() == length) and isbalanced(temp) and std::find(perms.begin(), perms.end(), temp) == perms.end())) {
                    perms.push_back(temp);
                }
            }
        }
        return perms;
    }
    
    vector<string> generateParenthesis1(int n) {
        /*
        length = 2*n;
        std::string pairs(length, '\0');
        for(int i = 0; i < length; i+=2) {pairs[i] = '('; pairs[i+1] = ')';}
        std::vector<std::string> perms = generateParenthesis1(pairs, length);
        */
        
        std::vector<std::string> perms;
        generateParenthesis2(perms, "", 0, 0, n);
        return perms;
    }
};