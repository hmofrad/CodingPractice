/*
 * https://leetcode.com/problems/reverse-words-in-a-string/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    string reverseWords(string s) {
        std::stack<std::string> stack;
        int len = s.length();
        int j = -1;
        for(int i = 0; i < len; i++) {
            if(s[i] != ' ' and j == -1) { j=i; }
            else if(s[i]==' ' and j != -1) {
                std::string temp = s.substr(j, i-j);
                stack.push(temp);
                j=-1;
            }
        }
        
        if(j!=-1) {
            std::string temp = s.substr(j);
            stack.push(temp);
        }
        
        std::string t;
        while(not stack.empty()) {
            t += stack.top() + ' '; stack.pop();
        }
        
        if(not t.empty()) t.pop_back(); 
        return t;
    }
    
    std::string extract_from_back(std::string s, int& i) {
        if(s.empty() or i==0) return std::string();
        int len = s.length();
        while(i>=0 and s[i]==' ') i--;
        int j = i;
        while(i>=0 and s[i]!=' ') i--;
        std::string t = s.substr(i+1, j-i);
        return t;
    }
    
    
    string reverseWords2(string s) {
        if(s.empty()) return s;
        if(s.size()==1) {
            if(s.front()==' ') return std::string();
            else return s;
        }
        std::string t;
        int i = s.length()-1;
        while(i>0) {
            std::string temp = extract_from_back(s, i);
            if (not temp.empty()) { t += temp + ' ';}
        }
        if(not t.empty()) t.pop_back();
        return t;
    }    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    
    string reverseWords1(string s) {
     std::string ret;
    int i = 0;
    char ss = s[i];
    while(ss == ' ') {
        i++;
        ss = s[i];
    }
    for(; i < s.size(); i++) {
        ss = s[i];
        
        if((ss == ' ')) {
            while((i + 1) < s.size()) {
                if(s[i+1] == ' ') {
                    i++;
                }
                else {
                    //i++;
                    break;
                }
            }
            ss = s[i];
        }
        
        //if(ss != ' ') {
            ret += ss;
      //      printf("%c", ss);
        //}
    }
    //printf("\n");
    if(ret[ret.size() - 1] == ' ')
        ret.pop_back();
    std::string ret1;
    i = 0;
    int j = ret.size()-1;
    //for(int i = ret.size() - 1; i > 0; i--) {
    while(i < ret.size()) {
        //printf("<");
        std::string t;
        while((j >= 0) and ret[j] != ' '){
            t += ret[j];
            //printf("%c", ret[j]);
            j--;
            i++;
        }
        j--;
        i++;
        for(int k = 0; k < t.size()/2; k++)
            std::swap(t[k], t[t.size() - k - 1]);
        //printf("> %s\n", t.c_str());
        ret1 += t;
        ret1 += ' ';
    }
    if(ret1[ret1.size() - 1] == ' ')
        ret1.pop_back();
    
    
    return(ret1);
    }
};