/*
 *  Cracking the coding interview: Problem 17.4: Maximum of two numbers
 *  Compile & run: g++ -o max max.cpp -g -Wall -std=c++11 -fsanitize=address && ./max
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int flip(int bit){
    return(1^bit);
}

int sign(int n) {
    return(flip((n >> 31) & 0x1));
}

int getMax(int a, int b) {
    int k = sign(a - b);
    int q = flip(k);
    return(a*k + b*q);
}

/*
int get_bit(int num, int i) {
    int mask = 1 << i;
    return((num & mask) != 0);
}

int max(int num1, int num2) {
    for(int i = 31; i >= 0; i--) {
        int b1 = get_bit(num1, i);
        int b2 = get_bit(num2, i);
        printf("i=%d b1=%d b2=%d\n", i, b1, b2);
    }
    return(0);
}
*/

int main(int argc, char** argv) {
    int num1 = 23045;
    int num2 = 456722;
    int maximum = getMax(num1, num2);
    printf("max(%d, %d) = %d\n", num1, num2, maximum);
    return(0);
}