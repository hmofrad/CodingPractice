/*
 *  https://leetcode.com/problems/license-key-formatting/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int L = S.size();
        std::string T;
        for(int i = L-1; i>= 0; i--) {
            char c = S[i];
            if(c!='-') {
                if(T.length()%(K+1)==K) T.push_back('-');
                if(c>='a' and c<='z') c = c - 'a' + 'A';
                T.push_back(c);
            }
        }
        std::reverse(T.begin(), T.end());
        return T;
    }
    string licenseKeyFormatting1(string S, int K) {
        //S="--a-a-a-a--";
        //K = 2;
        int L = S.size();
        for(char& c: S) { if(c>='a' and c<='z') c = c - 'a' + 'A'; }
        
        //int N = 0;
        //for(char& c: S) {if(c=='-') N++;}
                         
        std::string T;
        int k = 0;
        std::string t;
        for(int i = L-1; i>= 0; i--) {
            char c = S[i];
            if(c != '-') {t.push_back(c); k++;}
            if(k==K) {
                T += t; 
                if(i!=0) T.push_back('-');
                t.clear();
                k=0;
            }
        }
        //printf(">%s\n", t.c_str());
        //if(t.back()=='-') //t.pop_back();
        T += t;
        if(not T.empty() and T.back()=='-') T.pop_back();
        std::reverse(T.begin(), T.end());
        
        return T;
    }
};