/*
 * https://leetcode.com/problems/expressive-words/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::pair<std::string, std::vector<int>> encode(std::string S) {
        std::string T;
        std::vector<int> C;        
        int len = S.length();
        T.push_back(S[0]);
        C.push_back(1);
        int i = 1;
        while(i < len) {
            if(S[i] == T.back()) C.back()++;
            else {T.push_back(S[i]); C.push_back(1);}
            i++;
        }
        return make_pair(T, C);    
    }
    
    bool stretchy(std::string str0, std::string str1) {
        std::vector<int> count0;
        std::vector<int> count1;
        std::tie(str0, count0) = encode(str0);
        std::tie(str1, count1) = encode(str1);
        //printf("%s %d\n", str0.c_str(), count0.size());
        //printf("%s %d\n", str1.c_str(), count1.size());
        if(str0 != str1) return false;
        int len = str0.length();
        for(int i = 0; i < len; i++) {
            int len0 = count0[i];
            int len1 = count1[i];
            if((len0 < 3 and len0 != len1) or (len0>=3 and len0<len1)) return false;
            //if(len0 != len1 and len1>3 )
        }
        return true;
    }
    
    int expressiveWords(string S, vector<string>& words) {
        //S="zzzzzyyyyy";
        //words={"zzyy","zy","zyy"};
        if(S.empty() or words.empty()) return 0;
        int count = 0;
        for(std::string word: words) {
            if(stretchy(S, word)) { count++; }
        }
        return count;
    }
};