/*
 *  Problem: https://leetcode.com/problems/guess-number-higher-or-lower/
 *  Compile: g++ -o guessNumber guessNumber.cpp -std=c++11  -g -Wall -fsanitize=address && ./guessNumber
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

const int N = 3;

int guess(int num) {
    if(num > N) return(-1);
    else if(num < N) return(+1);
    else return(0);
}

int guess_r(int num, int low, int high) {
    printf("%d\n", num);
    int s = 2;
    if(low == high) {
        
    }
    
    int g = guess(num);
    if(g == 0) {
        return(num);
    }
    else if(g == +1) {
        return(guess_r(num/2, low, high));
    }
    else {
        return(guess_r(num*2, low, high));
    }
}
/*
int guessNumber(int n) {
    int low = 0;
    int high = INT32_MAX;
    int mid = 0;
    
    int g = guess(n);
    if(g == 0) return(n);
    else if(g == -1) {
        low = 0;
        high = n-1;
    }
    else {
        low = n+1;
        high = INT32_MAX;
    }
    mid = (low + high)/2;
    
    while(true) {
        g = guess(mid);
        if(g == 0) {
            return(mid);
        }
        else if(g == -1) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
        mid = (low+high)/2;
    }
    
    return(g);    
}
*/

int guessNumber(int n) {
    uint32_t low = 0;
    uint32_t high = INT32_MAX;
    uint32_t mid = (low+high)/2;
    int g = 0;
    while((g = guess(mid)) != 0) {
        //g = guess(mid);
        //if(!g) return(mid);
        printf("%d %d %d %d\n", low, mid, high, g);
        if(g == -1) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
        mid = (low+high)/2;
    }
    
    return(mid);    
}


int main(int argc, char **argv){
    int num = 10;
    int n = guessNumber(num);
    printf("GUESS %d\n", n);
    return(0);
}






