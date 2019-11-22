/*
 *  Problem: https://leetcode.com/problems/valid-perfect-square/
 *  Compile: g++ -o isPerfectSquare isPerfectSquare.cpp -std=c++11 && ./isPerfectSquare #-fsanitize=address 
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

bool isPerfectSquare(int num) {
    /*
    unsigned int i=1;
    do {
        ;
    } while(i++ < num/i);
    i--;
    return i*i==num;  
    */
    unsigned int i=1;
    while(i <= num/i) i++;
    i--;
    return i*i==num;  
    
    
}

int main(int argc, char **argv){
    int num = 16;
    bool isit = isPerfectSquare(num);
    printf("isPerfectSquare(%d) ? %d\n", num, isit);
    
    return(0);
}






