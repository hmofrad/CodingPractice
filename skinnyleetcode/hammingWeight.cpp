/*
 *  Problem: hammingWeight
 *  Compile: g++ -o hammingWeight hammingWeight.cpp -std=c++11 && ./hammingWeight
 *  Execute: ./hammingWeight
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <string.h>



int hammingWeight(uint32_t n) {
    int count = 0;
    int len = 8 * sizeof(uint32_t);
    /*
    for(int i = 0; i < len; i++) {
        uint32_t mask = 1 << i;
        if(mask & n)
            count++;        
    }
    */
    int i1 = 0;
    uint32_t mask1 = 0;
    int i2 = len - 1;
    uint32_t mask2 = 0;
    //uint32_t mask = 0;
    while(i1 < i2) {
    
    mask1 = 1 << i1;
    mask2 = 1 << i2;
    //mask = mask1 or mask2;
    i1++;
    i2--;
    //printf("%d %d %d %d\n", mask1, mask2, i1, i2);
     //mask1 = 1 << i;
        if((mask1 & n) and (mask2 & n))
            count+=2;        
        else if((mask1 & n) or (mask2 & n))
            count++;   
    }
    
    return(count);
}

int main(int argc, char** argv) {
    uint32_t n = 2324343;
    printf("hammingWeight(%d)=%d\n", n, hammingWeight(n));
    return(0);
}