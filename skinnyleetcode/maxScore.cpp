/*
 *	https://leetcode.com/problems/maximum-score-after-splitting-a-string/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int maxScore(string s) {
        int nzeros = 0;
        int nones = 0;
        int max_score = INT_MIN;
        int len = s.length();
        
        for(char& c: s) nones += c=='1' ? 1 : 0;
        
        for(int i = 0; i < len-1; i++) {
            char c = s[i];
            if(c=='0') nzeros++;
            else nones--;
            max_score = max(max_score, nzeros+nones);
        }
        return max_score;
        
    }
    int maxScore1(string s) {
        if(s.size()<=1) return 0;
        if(s.size()==2) return (s[0]=='0') + (s[1]=='1');
        int len = s.length();
        int nzeros = 0;
        int max_score = INT_MIN;
        for(int i = 0; i < len-1; i++) {
            nzeros += s[i]=='0' ? 1 : 0;
            int nones = 0;
            for(int j=i+1; j < len; j++) { nones += s[j]=='1' ? 1 : 0; }
            max_score = max(max_score, nzeros+nones);
        }
        return max_score; 
    }
};