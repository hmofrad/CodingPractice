/*
 *	https://leetcode.com/problems/flip-string-to-monotone-increasing/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int f = 0;
        int f1 = 0;
        for(char c: S) {
            if(c=='1') f1++;
            else f++;
            f=min(f1, f);
        }
        return f;
    }
    int minFlipsMonoIncr2(string S) {
        int f0 = 0;
        int f1 = 0;
        for(char c: S) {
            int v = c-'0';
            f0 += v;
            f1 = min(f0, f1+1-v);
        }
        return f1;
    }
    int minFlipsMonoIncr1(string S) {
        int length = S.length();
        int zerosflips = 0;
        int onesflips = 0;
        //for(int i = 0; i < length; i++) {
        //    zerosflips += S[i]=='1' ? 1 : 0;
        //}
        //int zerosflips = 0
        int nzeros = 0;
        for(int i = length-1; i >= 0; i--) {
            if(S[i]=='1') {
                onesflips+=nzeros;
                
                nzeros=0;
                zerosflips++;
                //onesflips = onesflips==0 ? length-i : onesflips;                
            }
            else {
                nzeros++;
                //onesflips += onesflips ? 1 : 0;
            }
        }
        //zerosflips+=nzeros;
        //printf("%d %d\n", zerosflips, onesflips);
        return min(zerosflips, onesflips);
    }
};