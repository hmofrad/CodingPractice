/*
 * https://leetcode.com/problems/decode-string/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::string dfs(std::string s, int& j) {
        //printf("%d\n",j);
        int k = 0;
        int len = s.length();
        std::string t;
        int i = j;
        if(j<len and s[j]>='0' and s[j]<='9') {
            while(j<=len and s[j]>='0' and s[j]<='9') j++;
            k = stoi(s.substr(i, j-i));
        }
        //printf("k=%d\n",k);
        if(s[j]=='[') {
            j++;
            std::string t0 =  dfs(s, j);
            printf("t0=%s\n",t0.c_str());
            for(int l = 0; l < k; l++) {
                t += t0;
            }
        }
        if(s[j]==']') {
            j++;
            t+=dfs(s, j);
        }
        //printf("j=%d\n", j);
        if(j<=len and s[j]>='a' and s[j]<='z') {
            while(j<=len and s[j]>='a' and s[j]<='z') j++;
            t += s.substr(i, j-i);
        }
        
        printf("t=%s %d\n",t.c_str(), k);
        return t;
    }
    
    std::string dfs1(std::string s, int& j) {
        int k = 0;
        std::string t;
        int len = s.length();
        while(j<len) {
            char c = s[j];
            if(c=='[') {
                std:string t0 = dfs1(s, ++j);
                while(k){t+=t0;k--;}
            }
            else if (c>='0' and c<='9') {
                k=k*10+(c-'0');
            }
            else if(c==']') {
                return t;
            }
            else {
                t.push_back(c);
            } 
            j++;
        }
        return t;
    }
    
    string decodeString1(string s) {
        
        std::stack<int> counts;
        std::stack<std::string> strs;
        std::string t;
        //int i = 0;
        int k = 0;
        int len = s.size();
        for(char c: s) {
            //printf("", c, counts.size(), strs.size());
            if(c>='0' and c<='9') {
                k=(k*10)+c-'0';
            }
            else if(c=='[') {
                //printf(">%d [%s]\n", k, t.c_str());
                counts.push(k); k=0;
                strs.push(t); t.clear();
            }
            else if(c==']') {
                k = counts.top(); counts.pop();
                std::string t0 = strs.top(); strs.pop();
                //printf("%d [%s]\n", k, t0.c_str());
                while(k){t0.append(t);k--;}
                t=t0;
            }
            else {
                t.push_back(c);
            }
        }
        
        
        return t;
    }
    
    
    string decodeString(string s) {
        //int j = 0;
        //return dfs(s, j);
        return decodeString1(s);
    }
};