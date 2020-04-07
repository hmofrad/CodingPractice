/*
 *  https://leetcode.com/problems/number-complement/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int get_bit(int num, int i) {
        int mask = 1 << i;
        int bit = num & mask;
        return(bit != 0);
    }
    
    int toggle_bit(int num, int i) {
        int mask = 1 << i;
        num ^= mask;
        return(num);
    }
    
    int findComplement(int num) {
        int num1 = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = get_bit(num, i);
            if(bit) {
                for(int j  = i; j >= 0; j--) {
                    num = toggle_bit(num, j);
                }
                break;
            }
        }
        printf("\n");
        return(num);
    }
};

// 01001
// 1