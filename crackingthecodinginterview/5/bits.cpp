/*
 * Cracking the coding interview: Bit manipulation (indexing start at zero and is inclusive)
 * Compile and run: g++ -o bits bits.cpp && ./bits
 * (c) Mohammad Hasanzadeh Mofrad, 2019
 * (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdio.h>
#include <stdlib.h>

int get_bit(int num, int n) {
    int mask = 1 << n;
    int r = ((num & mask) != 0) ? 1 : 0;
    return(r);
}

int set_bit(int num, int n) {
    int mask = 1 << n;
    int r = (num | mask);
    return(r);
}

int clear_bit(int num, int n) {
    int mask = ~(1 << n);
    int r = (num & mask);
    return(r);
}

int toggle_bit(int num, int n) {
    int mask = 1 << n;
    int r = (num ^ mask);
    return(r);
}


void print_bits(int num) {
    printf("Decimal:     %d\n", num);
    printf("Hexadecimal: 0x%04x\n", num);
    printf("Binary:      "); 
    for(int i = 31; i >= 0; i--) {
        printf("%d", get_bit(num, i));
    }
    printf("\n\n");
}


int clear_bits_msb_to_i(int num, int n) {
    int mask = (1 << n) - 1;
    int r = (num & mask);
    return(r);
}

int clear_bits_i_to_lsb(int num, int n) {
    int mask = ((~1 + 1) << n); 
    int r = (num & mask);
    return(r);
}


int main(int argc, char** argv) {
    int num = 234532;
    print_bits(num);
    num = clear_bits_i_to_lsb(num, 15);
    print_bits(num);
    
    
    return(0);
}
