/*
 *	https://leetcode.com/problems/perform-string-shifts/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::string myshift(std::string& s, int n) {
        //printf("%s %d\n", s.c_str(), n);
        int len = s.length();
        if(n<0) {
            while(n) {
                char c = s[0];
                for(int i = 1; i < len; i++) s[i-1]=s[i];
                s[len-1]=c;
                n++;
            }
        }
        else if(n>0) {
            while(n) {
                char c = s[len-1];
                for(int i = len-2; i >= 0; i--) s[i+1]=s[i];
                s[0]=c;
                n--;
            }
        }
        return s;
    }
    string stringShift(string s, vector<vector<int>>& shift) {
        if(s.length()<2) return s;
        
        //s="wpdhhcj";
        //shift={{0,7},{1,7},{1,0},{1,3},{0,3},{0,6},{1,2}};
        //"hcjwpdh"
        
        int nshifts=0;
        for(std::vector<int> sh: shift) {
            int direction = sh[0];
            int amount = sh[1];
            nshifts += direction ? amount : -amount;
        }
        int len = s.length();
        nshifts %= len;
        return myshift(s, nshifts);
    }
};