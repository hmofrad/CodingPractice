/*
 *  Cracking the coding interview: Problem 17.11: Implement Rand 7 from Rand 5
 *  Compile & run: g++ -o rand7fromRand5 rand7fromRand5.cpp -g -Wall -std=c++11 -fsanitize=address && ./rand7fromRand5
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

/* 
 * rand_gen[min max): generate a random number between 
 * min inclusive and max (exclusive)
 */
int rand_gen(int min, int max) {
    return((rand() % (max - min)) + min);
}

int rand5() {
    srand(time(NULL));
    int min = 0;
    int max = 5;
    return(rand_gen(min, max));
}

int rand7_1(){
    int max5 = 5;
    int max7 = 7;
    double scale = (double) max7/max5;
    return(rand5() * scale);
}

int rand7_2(){
    return((rand5() + rand5()) % 7);
}

int rand7_3(){
    while(true) {
        int num = 5 * rand5() + rand5();
        if(num < 21) {
            return(num % 7);
        }
    }
}

int main(int argc, char** argv) {
    //srand(time(NULL));
    //int min = 0;
    //int max = 5;
    //printf("rand_gen(%d, %d)=%d\n", min, max, rand_gen(min, max));
    printf("%d\n", rand7_1());
    printf("%d\n", rand7_2());
    printf("%d\n", rand7_3());
    return(0);
}