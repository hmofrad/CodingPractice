/*
 *  Problem: https://leetcode.com/problems/hamming-distance/
 *  Compile: g++ -o hammingDistance hammingDistance.cpp -std=c++11 -g -Wall -fsanitize=address && ./hammingDistance
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

int get_bit(int x, int i) {
    int mask = 1 << i;
    return((x & mask) != 0);
}

int hammingDistance(int x, int y) {
    int d = 0;
    for(int i = 0; i < 31; i++) {
        if(get_bit(x, i) ^ get_bit(y, i)) {
            d++;
        }
    }
    return(d);    
}

int main(int argc, char **argv){
    int x = 1;
    int y = 4;
    int d = hammingDistance(x, y);
    printf("D(%d, %d) = %d\n", x, y, d);
    return(0);
}