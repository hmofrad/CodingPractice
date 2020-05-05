/*
 *	https://leetcode.com/problems/reformat-the-string/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 #include <stdlib.h>

class Solution {
public:
    void copy(std::string& t, std::unordered_map<char,int>& first, std::unordered_map<char,int>& second) {
        int i=0;
        for(auto f: first) {
            //printf("%d %c\n",i, f.first);
            for(int j=0; j < f.second; j++) {t[i]=f.first; i+=2;}
        }
        i=1;
        for(auto s: second) {
            for(int j=0; j < s.second; j++) {t[i]=s.first; i+=2;}
        }
    }
string reformat(string s) {
        std::unordered_map<char,int> letters;
        int nletters = 0;
        std::unordered_map<char,int> digits;
        int ndigits = 0;
        for(char c: s) {
            if(c>='a' and c<='z') {letters[c]++; nletters++;}
            else {digits[c]++; ndigits++;}
        }
        int diff = nletters>ndigits ? nletters-ndigits : ndigits-nletters;
        if(diff > 1) return std::string();
        //printf("%d %d %d %d\n", diff, letters.size(), digits.size(), s.length()/2);
        
        int len = s.length();
        std::string t(len, '\0');
        if((nletters==len/2 and ndigits==len/2) or (nletters>len/2)) {
            copy(t, letters, digits);
        }
        else {
            copy(t, digits, letters);
        }
        
        return t;
    }
};