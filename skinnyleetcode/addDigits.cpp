    /*
 *  Problem: https://leetcode.com/problems/add-digits/
 *  Compile: g++ -o addDigits addDigits.cpp -std=c++11 && ./addDigits
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

int addDigits(int num) {
    int ret = 0;
    while(true) {
        do{
            ret += num%10;
            num = num/10;
        } while(num);
        if(ret < 10) {
            break;
        }
        else {
            num = ret;
            ret = 0;
        }
    }
    return(ret);    
}

int main(int argc, char **argv){
    int num = 38;
    printf("addDigits(%d)=%d\n", num, addDigits(num));
    return(0);
}






