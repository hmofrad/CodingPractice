/*
 *  Problem: https://leetcode.com/problems/sum-of-two-integers/
 *  Compile: g++ -o getSum getSum.cpp -std=c++11 && ./getSum #-fsanitize=address 
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
#include<bits/stdc++.h> 
int getSum(int a, int b) {
    int c = 0;
    while(b) {
        c = a & b;
        a ^= b;
        b = (uint32_t) c << 1;
        printf("%d %d %d\n", a, b, c);
    }
    return(a);
}

int main(int argc, char **argv){
    int a = 1, b = 2;
    int s = getSum(a, b);
    printf("getSum(%d, %d) = %d\n",a, b, s);
    
    return(0);
}






