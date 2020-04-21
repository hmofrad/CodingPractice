/*
 *  https://leetcode.com/problems/complement-of-base-10-integer/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int get_bit(int num, int i) {
        int mask = 1 << i;
        int bit = num & mask;
        return bit != 0;
    }
    int bitwiseComplement(int N) {
        
        for(int i = 31; i >= 0; i--) {
            if(get_bit(N, i)) {
                int M = 0;
                for(int j = i; j >= 0; j--) {
                    if(not get_bit(N, j)) M+=pow(2,j);
                }
                return M;
            }
        }
        return 1;
    }
};