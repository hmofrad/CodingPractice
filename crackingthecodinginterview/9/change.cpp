/*
 *  Cracking the coding interview: Problem 9.8: Given inifinite number of coins compute ways n can be changed into quarters, dimes, penny, and dimes
 *  Compile & run: g++ -o change change.cpp -g -Wall -std=c++11 -fsanitize=address  && ./change
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
#include <vector>

#define quarter 25
#define dime    10
#define nickle  5
#define penny   1

const std::vector<int> denoms = {25, 10, 5, 1};

int change(int amount, uint32_t index) {
    if(index >= denoms.size() -1) {
        return 1;
    }
    int denomAmount = denoms[index];
    int ways = 0;
    for(int i = 0; i * denomAmount <= amount; i++) {
        int amountRemaining = amount - (i * denomAmount);
        ways += change(amountRemaining, index+1);
    }
    
    return(ways);
}

int main(int argc, char** argv) {
    
    int n = 10;
    int ways = change(n, 0);
    printf("%d\n", ways);
    
    return(0);
}