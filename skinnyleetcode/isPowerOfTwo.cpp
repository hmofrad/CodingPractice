    /*
 *  Problem: https://leetcode.com/problems/power-of-two/
 *  Compile & execute: g++ -o isPowerOfTwo isPowerOfTwo.cpp -std=c++11 -fsanitize=address && ./isPowerOfTwo
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
#include <queue>
#include <cmath>

/*
bool isPowerOfTwo(int n) {
    bool ret =  false;
    double nn = n;
    if(n == 1) return(true);
    if(fmod(nn, 2)) return(false);
    while(nn > 1) {
        nn /= 2;
    }
    return((nn == 1) == true);
}
*/

bool isPowerOfTwo(int n) {
    return((n <= 0) ? false : !(n & (n-1)));
}



int main(int argc, char **argv) {
    //int n = 9;
    //printf("isPowerOfTwo(%d) = %d\n", n, isPowerOfTwo(n));
    for(int n = 0; n < 15; n++) {
        printf("isPowerOfTwo(%d) = %d\n", n, isPowerOfTwo(n));
    }
    return(0);
}






