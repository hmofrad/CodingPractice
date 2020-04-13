/*
 *  https://leetcode.com/problems/binary-gap/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int getBit(int N, int i) {
        int mask = 1 << i;
        int bit = N & mask;
        return bit != 0;
    }
    int binaryGap(int N) {
        int d = 0;
        int j = -1;
        int len = 31;
        for(int i = 31; i >= 0; i--) {
            int b = getBit(N, i);
            if(b) {
                j = (j==-1) ? i : j;
                d = max(d, j-i);
               // printf("%d %d %d\n", i, j, d);
                j=i;
            }
        }
        return d;
    }
};