/*
 *  https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int size = s1.size();
        if(size == 1) {if(s1[0] == s2[0]) return 0; else return -1;}
        
        int xes1 = 0;
        for(char c: s1) xes1 += c == 'x' ? 1 : 0;
        int xes2 = 0;
        for(char c: s2) xes2 += c == 'x' ? 1 : 0;
        
        if((xes1 + xes2) % 2) return -1;
        
        int dif = 0;
        int xc = 0;
        for(int i = 0; i < size; i++) {
            if(s1[i] != s2[i]) {
                dif++; 
                if(s1[i] == 'x') xc++;
            }
        }
        
        int ans = xc%2 ? (dif/2)+1 : dif/2; // odd #xes or even xes
        return ans;
    }
};
