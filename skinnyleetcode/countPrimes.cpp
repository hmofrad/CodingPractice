/*
 *  Problem: course-schedule
 *  Compile: g++ -o countPrimes countPrimes.cpp -std=c++14 && ./countPrimes
 *  Execute: ./countPrimes
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
#include <queue>
#include <numeric>
#include <unordered_set>

bool isPrime(int n) {
    bool prime = true;
    for(int i = 2; i <=n/2; i++) {
        if((n % i) == 0) {
            prime = false;
            break;
        }
    }
    return(prime);
}


int countPrimes(int n) {
    int count = 0;
    int k = 1;
    for(int i = 2; i < n; i++) {
        
        //if(isPrime) count++;
        
        count += isPrime(i);
        //for(int j = 2; j < n; j++) {
        //printf("%d %d\n", i, count);
        //if((n % i) != 0)
          //  count++;
        
        //if(isPrime(i)) count++;
    }
    //printf("  %d\n", count);
    return(count);
}

int main(int argc, char** argv) {
    int n = 10;
    printf("countPrimes(%d)=%d\n", n, countPrimes(n));
    return(0);
}