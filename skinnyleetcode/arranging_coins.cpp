/*
 *  Problem: https://leetcode.com/problems/arranging-coins/
 *  Compile: g++ -o arranging_coins arranging_coins.cpp -std=c++11 -g -Wall -fsanitize=address && ./arranging_coins
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

int arranging_coins_1(int m) {
    int i = 0;
    int j = 1;
    while(true) {
        m -= j;
        j++;
        if(m>=0)
            i++;
        else
            break;
    }
    return(i);
}

int arranging_coins(int m) {
    int i = 0;
    int j = 1;
    while(j < m) {
        j += (j+1);
        i++;
    }
    return(i);
}

int arranging_coins_2(int n) {
    int i = 0;
    while(n > 0) {
        i++;
        n -= i;
    }
    
    return((n == 0) ? i : --i);
}


int main(int argc, char **argv){
    int m = 5;
    int n = arranging_coins_2(m);
    printf("N=%d\n", n);
    return(0);
}






