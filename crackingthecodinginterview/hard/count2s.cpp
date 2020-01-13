/*
 *  Cracking the coding interview: Problem 18.4: Count the number of 2s
 *  Compile & run: g++ -o  count2s count2s.cpp -g -Wall -std=c++11 -fsanitize=address  && ./count2s
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>


int numberOf2s(int n) {
    int count = 0;
    while(n > 0) {
        if((n%10) == 2) {
            count++;
        }
        n/=10;
    }
    return(count);
}


int count(int n) {
    int c = 0;
    
    for(int i = 0; i <= n; i++) {
        c += numberOf2s(i);
    }
    return(c);
}

int count1(int n) {
    int c = 0;
    
    for(int i = 0; i <= n; i++) {
        int d = i;
        int r = 0;
        do{
            r = d%10;
            d /=10;
            if(d == 2) c++;
            if(r == 2) c++;
        }while(d>2);
    }
    return(c);
}


int main(int argc, char** argv) {
    int n = 25;
    int c = count(n);
    printf("Count = %d\n", c);    
    return(0);
}