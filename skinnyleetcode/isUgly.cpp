    /*
 *  Problem: https://leetcode.com/problems/ugly-number/
 *  Compile: g++ -o isUgly isUgly.cpp -std=c++11 && ./isUgly
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

bool isUgly(int num) {
    bool ugly = false;
    if(num < 1) return(ugly);
    
    while(not(num % 2)) {
        num /= 2;
        printf("2 ");
    }
    
    while(not(num % 3)) {
        num /= 3;
        printf("3 ");
    }
    while(not(num % 5)) {
        num /= 5;
        printf("5 ");
    }

    printf("%d\n", num);
    if(num == 1) ugly = true;
    return(ugly);
}

int main(int argc, char **argv){
    int num = 1;
    
    printf("isUgly(%d) = %d\n", num, isUgly(num));
    
    return(0);
}






