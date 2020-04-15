/*
 *  https://leetcode.com/problems/generate-parentheses/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
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
    
    vector<string> generateParenthesis(int n) {
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