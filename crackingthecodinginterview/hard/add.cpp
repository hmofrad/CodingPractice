/*
 *  Cracking the coding interview: Problem 18.1: add without adding
 *  Compile & run: g++ -o add add.cpp -g -Wall -std=c++11 -fsanitize=address  && ./add
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int add(int a, int b) {
    printf("a=%d b=%d\n", a, b);
    if(b == 0) {
        return(a);
    }
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return(add(sum, carry));
}

int main(int argc, char** argv) {
    int a = 759;
    int b = 674;
    int c0 = a + b;
    int c1 = add(a, b);
    printf("%d == %d\n", c0, c1);
    return(0);
}