/*
 *  Problem: https://leetcode.com/problems/count-numbers-with-unique-digits/
 *  Compile: g++ -o countNumbersWithUniqueDigits countNumbersWithUniqueDigits.cpp -std=c++11 && ./countNumbersWithUniqueDigits #-fsanitize=address 
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

/*
int countNumbersWithUniqueDigits(int n) {
    int num = std::pow(10,n);
    int count =  num;
    std::vector<bool> mask(10);
    for(int i = 0; i <= (num-1); i++) {
        int j = i;
        int r = 0;
        while(j) {
            r = j%10;
            j = j/10;
            if(mask[r]) {
                count--;
                break;
            }
            else {
                mask[r] = 1;
            }
        }
        std::fill(mask.begin(), mask.end(), 0);
    }
    return(count);
}
*/

int countNumbersWithUniqueDigits(int n) {
    int num = std::pow(10,n);
    int count =  num;
    int map = 0;
    int mask = 0;
    //(num-1)
    for(int i = 0; i <= num-1; i++) {
        map = 0;
        int j = i;
        int r = 0;
        while(j) {
            r = j%10;
            j = j/10;
            mask = (1 << r);
            //printf("%d %d %d %d %d %d\n", i, j, r, map, mask, map & mask);
            if(map & mask) {
                count--;
                map = 0;
              //  printf("%d\n", count);
                break;
            }
            else{
                map |= mask;
            }
        }
    }
    return(count);
}

int main(int argc, char **argv){
    
    int input = 3;
    int output = countNumbersWithUniqueDigits(input);
    printf("countNumbersWithUniqueDigits(%d) = %d\n",input, output);
    
    return(0);
}






