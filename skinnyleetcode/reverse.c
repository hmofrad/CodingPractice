/*
 *  Problem: reverse (https://leetcode.com/problems/reverse-integer/description/)
 *  Compile: gcc -o reverse reverse.c -g -Wall -Werror 
 *  Execute: ./reverse
 *  (c) Mohammad HMofrad, 2017
 *  (e) mohammad.hmofrad@pitt.edu
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define BASE (10)

int reverse(int x) {
    int int_range = 2147483647;
    int BASE = 10;
    int reverse = 0;
    int lastDigit = 0;
    int sign = 1;
    if((x > int_range) || (x < -int_range))
        return(0);
    if(x < 0)
    {
        sign = 0;
        x = -x;
    }
    while(x > 0) {
        lastDigit = x % BASE;
        reverse = (reverse * BASE) + lastDigit;
        x = x /BASE;
    }
    if(!sign)
        reverse = -reverse;
    
    return(reverse);
}

int main(int argc, char *argv[]) {
    
    int x = 1534236469;
    printf("Original: %d\n", x);
    int r = reverse(x);
    printf("Reverse : %d\n", r);
    return(0);
}
