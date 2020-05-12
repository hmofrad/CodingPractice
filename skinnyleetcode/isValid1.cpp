/*
 *	https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool check1(std::string S, int start, int end) {
        bool ret = false;
        //std::string right;
        int j = start;
        for(int i = start; i <= end-2; i++) {
            std::string t = S.substr(j, 3);
            if(t=="abc") {
                
                //std::string left = S.substr(start, j-start+1);
                //std::string right = S.substr(j+3, end-j+1);
                bool ret = check1(S, start, j) and check1(S, j+3, end);
                break;
            }
            else j++;
        }
        return ret;
    }
    bool check(std::string S) {
        if(S.empty()) return true;
        //printf("s=%s\n",  S.c_str());
        //bool ret = false;
        //std::string right;
        int len = S.length();
        //int j = 2;
        for(int i = 0; i < len-2; i++) {
            
            std::string t = S.substr(i, 3);
            //printf("%d %s\n", i, t.c_str());
            if(t=="abc") {
                std::string T = S.substr(0, i);
                T += S.substr(i+3, len-i-3);
                return check(T);
                //ret = check(T);
                //printf("<%s %d>\n", T.c_str(), ret);
                //std::string left = S.substr(start, j-start+1);
                //std::string right = S.substr(j+3, end-j+1);
                //bool ret = check(S, start, j) and check(S, j+3, end);
                //break;
            }
           // else j++;
        }
        return false;
    }
    bool isValid1(string S) {
        return check(S);
    }
    bool isValid(string S) {
        std::vector<char> stack;
        for(char c: S) {
            stack.push_back(c);
            if(stack.back() == 'c') {
                int n = stack.size();
                if(n>=3 and stack[n-2]=='b' and stack[n-3]=='a') {stack.pop_back(); stack.pop_back(); stack.pop_back();}
            }
        }
        return stack.empty();
    }
};