    /*
 *  Problem: https://leetcode.com/problems/bulb-switcher/
 *  Compile: g++ -o bulbSwitch bulbSwitch.cpp -std=c++11 && ./bulbSwitch #-fsanitize=address 
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
#include <unordered_set>
#include <stack>
#include <numeric>
#include <map>
#include <cmath>
#include <unordered_map>

int bulbSwitch(int n) {
    int count = 0;
    unsigned char* bulbs = (unsigned char*) malloc((n + 7)/8);
    memset(bulbs, 0, (n + 7)/8);
    //printf("%d\n", bulbs[0]);
    int m = 0;
    while(m < n) {
      //  printf("m=%d n=%d nr=%d\n", m, n, (n + 7)/8);
        //for(int i = 0 + m; i < n; i+=m+1) {
        for(int i = n - 1 - m; i >= 0; i-=(m+1)) {
            uint32_t byte = i/8;
            uint32_t bit = i%8;
            unsigned char mask = 1 << bit;
            bulbs[byte] ^= mask;
           // printf("i=%d/%d by=%d bi=%d %d\n", i, n - 1 - m, byte, bit, bulbs[0]);
        }    
        m++;   
        //printf("=%d\n", bulbs[0]);
        
    }
    //printf("<%d>\n", bulbs[0]);
    for(int i = n - 1; i >= 0; i--) {
        uint32_t byte = i/8;
        uint32_t bit = i%8;
        unsigned char mask = 1 << bit;
        count += ((bulbs[byte] & mask) != 0);
       // printf("[%d %d] ", i, ((bulbs[byte] & mask) != 0));
    }
    //printf("\n<%d?\n", count);
    free(bulbs);
    return(count);
}

/*
int bulbSwitch(int n) {
    std::vector<bool> bulbs(n, false);
    int m = 0;
    while(m < n) {
        printf("%d\n", m);
        for(int i = 0 + m; i < n; i+=m+1) {
            bulbs[i] = not bulbs[i];
        }    
        m++;   
        for(int i = 0; i < n; i++) {
            printf("%d ", (bulbs[i] == true));
        }   
        printf("\n");
        
    }

    return(std::accumulate(bulbs.begin(), bulbs.end(), 0));
}
*/

int main(int argc, char **argv){
    int n = 4;
    int on = bulbSwitch(n);
    printf("bulbSwitch(%d) = %d\n", n, on);
    return(0);
}






