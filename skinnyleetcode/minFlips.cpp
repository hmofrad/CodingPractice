/*
 *  https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int getBit(int n, int i) {
        int mask = 1 << i;
        int bit = n & mask;
        return(bit != 0);
    }
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for(int i = 0; i < 32; i++) {
            int a1 = getBit(a, i);
            int b1 = getBit(b, i);
            int c1 = getBit(c, i);
            
            if((a1 | b1) != c1) {
                if(a1 & b1) flips +=2;
                else flips++;
            }
        }
        return flips;
    }
};