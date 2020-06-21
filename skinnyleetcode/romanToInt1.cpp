/*
 * https://leetcode.com/explore/interview/card/microsoft/48/others/198/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> map = {{'I',1},
                                            {'V',5},
                                            {'X',10},
                                            {'L',50},
                                            {'C',100},
                                            {'D',500},
                                            {'M',1000}};
        int j = 0;
        int len = s.length();
        int val = 0;
        while(j<len) {
            if((s[j]=='I' and j+1<len and (s[j+1]=='V' or s[j+1]=='X')) or 
               (s[j]=='X' and j+1<len and (s[j+1]=='L' or s[j+1]=='C')) or
               (s[j]=='C' and j+1<len and (s[j+1]=='D' or s[j+1]=='M'))) {
                val += map[s[j+1]] - map[s[j]];
                j+=2;
            }
            else {val += map[s[j++]];}
        }
        return val;
    }
    
    
    
    
    int romanToInt2(string s) {
       int value = 0;
        std::unordered_map<char, int> romans({{'I', 1}, {'V', 5}, {'X',10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});
        
        int len = s.length();
        int i = 0;
        int currentvalue = 0;
        while(i < len) {
            int currentvalue = romans[s[i]];
            int nextvalue = i+1<len ? romans[s[i+1]] : 0;
            if(currentvalue<nextvalue) {value +=nextvalue-currentvalue; i+=2;}
            else {value+=currentvalue; i++;}
        }
        
        return value;
    }
    int romanToInt1(string s) {
        int value = 0;
        std::unordered_map<char, int> romans({{'I', 1}, {'V', 5}, {'X',10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});
        
        int len = s.length();
        int i = 0;
        while(i < len) {
        //for(int i = 0; i < len; i++) {
            int v = 0;
            if((i+1 <len) and ((s[i]=='I' and (s[i+1]=='V' or s[i+1]=='X')) or (s[i]=='X' and (s[i+1]=='L' or s[i+1]=='C')) or (s[i]=='C' and (s[i+1]=='D' or s[i+1]=='M')))) {
                v = romans[s[i+1]]-romans[s[i]];
                i+=2;
            }
            else {
                int t = romans[s[i]];
                v += t;
                while(i+1 <len and s[i]==s[i+1]) {v+=t; i++;}
                i++;
            }
            value +=v;
        }
        
        
        return value;
    }
};