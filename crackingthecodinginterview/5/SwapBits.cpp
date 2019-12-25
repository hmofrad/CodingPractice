/*
 *  Cracking the coding interview: Problem 5.5: How many bit flips you need to convertt integer A to B
 *  Compile & run: g++ -o SwapBits SwapBits.cpp -g -Wall -std=c++11 -fsanitize=address && ./SwapBits
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>

int swapBits(int A, int B) {
    int C = A ^ B;
    int n = 0;
    while(C) {
        C &= (C-1);
        n++;
    }
    return(n);
}

int main(int argc, char** argv) {
    int A = 127;
    int B = 0;
    int n = swapBits(A, B);
    printf("%d, %d --> %d\n", A, B, n);
    return(0);
}