/*
0000 0
0001 1
0010 2
0011 3
0100 4
0101 5 
0110 6
0111 7 
1000 8
1001 9
1010 A
1011 B 
1100 C
1101 D
1110 E
1111 F
*/
/*
 *  URL: https://leetcode.com/problems/reverse-bits/
 *  Compile & Execute: g++ -o reverseBits reverseBits.cpp -std=c++11 && ./reverseBits
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>


class Solution {
public:
    static uint32_t reverseBits(uint32_t n) {
        //char nBytes = sizeof(n);
        //char nBits = 8 * sizeof(n);
        uint32_t mask = 1;
        //uint32_t mask1 = 4294967295;
        
        printf("%08x %08x\n", n, mask);
        //printf("%08x %08x\n", n, k << 1);
        //printf("%08x %08x\n", n, k << 31);
        //printf("%08x %08x\n", n, k << 2);
        //printf("%08x %08x\n", n, k >> 2);
        //int l = 32/2;
        uint32_t r = 0;
        for(int i = 0; i < 16; i++) {
            uint32_t j = 1 << i;
            uint32_t k = 1 << (32 - i - 1);
            uint32_t l = n & j;
            uint32_t m = n & k;
            //uint32_t o = l & m;
            printf("%d: %08x %08x : %08x %08x\n", i, j, l, k, m);
            if(l and m) {
                r = r | j;
                r = r | k;
                printf("set both\n");
            }
            else if(l) {
                r = r | k;
                printf("set right\n");
            }
            else if(m) {
                r = r | j;
                printf("set left\n");
            }
            printf("%08x\n", r);
        }
        
        
        return(r);
    }
};

int main(int argc, char **argv) {
    uint32_t m = 4294967293;
    uint32_t n = Solution::reverseBits(m);
    printf("\n%lu\n", n);
    return(0);
}    

