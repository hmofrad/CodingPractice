/*
 *  Cracking the coding interview: Problem 17.1: Swap to integers
 *  Compile & run: g++ -o swap swap.cpp -g -Wall -std=c++11 -fsanitize=address  && ./swap
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h> 
#include <stdlib.h>
#include <iostream>

void swap(int* a, int* b) {
    *a = *a - *b;
    *b = *b + *a;
    *a = *b - *a;
}

int main(int argc, char** argv) {
    int a = 9;
    int b = 5;
    printf("a=%d b=%d\n", a, b);
    swap(&a, &b);
    printf("a=%d b=%d\n", a, b);
    
    return(0);
}