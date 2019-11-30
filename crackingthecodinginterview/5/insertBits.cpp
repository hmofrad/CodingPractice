/*
 *  Cracking the coding interview: Problem 5.1: Insert M into N s.t. M start at bit i through j
 *  Compile & run: g++ -o insertBits insertBits.cpp -g -Wall && ./insertBits
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int get_bit(unsigned int num, int n) {
    unsigned int mask = 1 << n;
    int bit = ((num & mask) != 0);
    return(bit);
}

void set_bit(unsigned int& num, int n) {
    unsigned int mask = 1 << n;
    num |= mask;
}

void set_bit_v(unsigned int& num, int n, int v) {
    unsigned int mask = v << n;
    num |= mask;
}

void print(unsigned int num) {
    printf("%08d: ", num);
    for(int i = 31; i >= 0; i--) {
        printf("%d", get_bit(num, i));
    }
    printf("\n");
}

void insert(unsigned int& n, unsigned int m, int i, int j) {
    for(int k = i; k <=j; k++) {
        int b = get_bit(m, k-i);
        set_bit_v(n, k, b);
        //printf("%d %d\n", k, b);
        //if(b) set_bit(n, k);
    }
}

int main(int argc, char** argv) {

    unsigned int m = 17;
    unsigned int n = 1024;
    int i = 2;
    int j = 6;
    
    
    print(m);
    print(n);
    insert(n, m, i, j);
    print(n);
}