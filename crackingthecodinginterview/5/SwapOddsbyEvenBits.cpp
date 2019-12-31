/*
 *  Cracking the coding interview: Problem 5.6: How many bit flips you need to convertt integer A to B
 *  Compile & run: g++ -o SwapOddsbyEvenBits SwapOddsbyEvenBits.cpp -g -Wall -std=c++11 -fsanitize=address && ./SwapOddsbyEvenBits
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>

int SwapOddsbyEvenBits(int A) {
    return(((A & 0xAAAAAAAA) >> 1) | ((A & 0x55555555) << 1));
}

int main(int argc, char** argv) {
    int A = 5;
    int B = SwapOddsbyEvenBits(A);
    
    printf(" %d --> %d\n", A, B);
    return(0);
}