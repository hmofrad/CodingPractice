/*
 *	https://leetcode.com/problems/different-ways-to-add-parentheses/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        std::vector<int> ans;
        int len = input.length();
        for(int i = 0; i < len; i++) {
            char c = input[i];
            if(c=='-' or c=='*' or c=='+') {
                std::string p1_s = input.substr(0, i);
                std::string p2_s = input.substr(i+1);
                std::vector<int> p1_n = diffWaysToCompute(p1_s);
                std::vector<int> p2_n = diffWaysToCompute(p2_s);
                
                for(int& n1: p1_n) {
                    for(int& n2: p2_n) {
                        int v = 0;
                        switch(c) {
                            case '+': v= n1+n2; break;
                            case '-': v= n1-n2; break;
                            case '*': v= n1*n2; break;
                        }
                        ans.push_back(v);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(input));
        return ans;
    }
};