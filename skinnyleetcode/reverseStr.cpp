/*
 * https://leetcode.com/problems/reverse-string-ii/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    void reverse(std::string& s, int i, int j) {
        while(i<j) { std::swap(s[i++],s[j--]); }
        //int m  = s.length()-1;
        //for(int k = i; k <= min(m,i+((j-i)/2)); k++) { 
            //printf("%d %d\n", k, j+i-k);
          //  std::swap(s[k], s[j+i-k]); 
        //}
    }
    string reverseStr(string s, int k) {
        //s="abcdefg";
        //k=3;
        if(s.size()<2) return s;
        int l = s.length();
        //s="a";
        for(int i = 0; i < s.length(); i+=2*k) { 
            //printf("%d %d %s\n", i, i+k-1, s.c_str());
            reverse(s,i, min(i+k-1, l-1)); 
        }
        return s;
    }
};