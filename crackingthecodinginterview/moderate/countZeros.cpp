/*
 *  Cracking the coding interview: Problem 17.3: Count the number of trailing zeros in a factorial
 *  Compile & run: g++ -o countZeros countZeros.cpp -g -Wall -std=c++11 -fsanitize=address  && ./countZeros
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h> 
#include <stdlib.h>
#include <iostream>

int factorsOf5(int i) {
    int count = 0;
    while((i%5) == 0) {
        count++;
        i /= 5;
    }
    return(count);
}

int countFactZeros(int num) {
    int count = 0;
    for(int i = 2; i <= num; i++) {
        count += factorsOf5(i);
    }
    return(count);
}

int main(int argc, char** argv) {
    int n = 19;
    
    printf("%d\n", countFactZeros(n));
    
    return(0);
}