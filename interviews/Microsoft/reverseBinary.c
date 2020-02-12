/*
 *  Problem: Reverse a binary 
 * 01010101 --> 1010101
 *  Compile: gcc -o reverseBinary reverseBinary.c -g -Wall -fsanitize=address && ./reverseBinary   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

unsigned int get_bit(unsigned int n, int b) {
    unsigned int mask = 1L << b;
    return((n & mask) != 0);
}

void set_bit(unsigned int* n, int b) {
    unsigned int mask = 1L << b;
    *n |= mask;
}

void clear_bit(unsigned int* n, int b) {
    unsigned int mask = 1L << b;
    *n &= ~mask;
}

unsigned int reverse(unsigned int n) {
    for(int i = 0; i < 32; i++) {
        //unsigned int mask = 1L << i;
        //unsigned int bit = ((n & mask) != 0);
        printf("%d", get_bit(n, i));
        
    }
    printf("\n");
    
    int m = 0;
    for(int i = 0; i < 16; i++) {
        unsigned int bit_l = get_bit(n, i);
        unsigned int bit_r = get_bit(n, 31-i);
        if(bit_r) {
            set_bit(&n, i);
            clear_bit(&n, 31-i);
        }
        if(bit_l) {
            set_bit(&n, 31-i);
            clear_bit(&n, i);
        }
    }
    printf("\n");
    
    for(int i = 0; i < 32; i++) {
        unsigned int mask = 1L << i;
        unsigned int bit = ((n & mask) != 0);
        printf("%d", bit);
        
    }
    printf("\n");
    
    
    return(n);
}

int main(int argc, char** argv){
    unsigned int n = 10l;
    unsigned int m = reverse(n);
    printf("%d --> %d\n", n, m);
    return(0);
}
