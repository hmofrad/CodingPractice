/*  Incomplete, be back later
 *  Problem: intToRoman (https://leetcode.com/problems/palindrome-number/description/)
 *  Compile: gcc -o intToRoman intToRoman.c -g -Wall -Werror 
 *  Execute: ./intToRoman
 *  (c) Mohammad HMofrad, 2018
 *  (e) mohammad.hmofrad@pitt.edu
 */
 
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10 // strlen('MMMCMXCIX\0') = 10 + 

/*
enum roman {
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000    
};    
*/

int numDigits(int num) {
    int m = 10;
    int r = 0;
    int d = 0;
    while(num) {
        r = num % m;
        num = num / m;
        d++;
    }
    return(d);
}

int pow(int num, int exp) {
    int i = 0;
    int ret = 1;
    for(i = 0; i < exp; i++) {
        ret *= num;
    }
    return(ret);
}

char *roman_numeral(int num, int place) {
    int number = num;
    int multiplier = place;
    char *roman_numeral = malloc(sizeof(char) * MAX_LENGTH);
    memset(roman_numeral, '\0', sizeof(char) * MAX_LENGTH);
    while(num <= 3) {
        switch(place) {
            case 1:
                *roman_numeral = 'I';
                break;
            case 5:
                *roman_numeral = 'V';
                break;
            case 10:
                *roman_numeral = 'X';
                break;
            case 50:
                *roman_numeral = 'L';
                break;
            case 100:
                *roman_numeral = 'C';
                break;
            case 500:
                *roman_numeral = 'D';
                break;
            case 1000:
                *roman_numeral = 'M';
                break;
            default:
                printf("Invalid number=%d", number);
                break;
        }
        num--;
    }
    return(roman_numeral);
}
 
char *intToRoman(int num) {
    int n = numDigits(num);
    //printf("%d\n", n);
    
    //char *roman = malloc(sizeof(char) * n);
    
    
    //for(i = 0; i < 3; i++) {
    
    //while(num) {
        
    //}
    
    int m = pow(10, n - 1);
    //printf("%d %d \n", m, num/m);
    int num1 = 0;
    while(num) {
        num1 = num / m;
        printf("%d %d %s\n", num1, m, roman_numeral(num1, m));
        
        
        
        
        num = num - (num1 * m);
        m = m / 10;
        
        //break;
        
    }
    

    /*
    int r = 0;
    int m = 10;
    int c = 1;
    int i = 0;
    while(num) {
        r = num % m;
        printf("%d %d %d\n", num, r, c);
        num = num / m;
        c = c * 10;
        
        //num = num - r;
        //m = m * 10;
    }
    */
    
    //int m = 10;
    
    //printf("%d %d %d %d\n", num, num / m, (num / m) * m, num - ((num / m) * m) );
    //int r = num - ((num / m) * m);
    //num = ((num / m) * m);
    //num = num - r;
    //printf("%d %d\n", num, r);
    //m = m * 10;
    //printf("%d %d %d %d %d\n", num, num / m, (num / m) * m, num - ((num / m) * m), (num - ((num / m) * m))/(m/10));
    //r = (num - ((num / m) * m))/(m/10);
    //num = num - r;
    
    //printf("%d %d %d %d\n", num, num / m, (num / m) * m, num - ((num / m) * m) );
    //int new_num = ((num / m) * m);
    //int r = num - ((num / m) * m);
    
    //printf("%d %d %d %d\n", num, new_num, );
    //printf("%d %d %d\n", num, num / 10, num / 100);
    //enum roman r = C;
    //printf("%d\n", r);
    exit(0);
     
    char *ret = malloc(sizeof(char) * 3);
    ret[0] = 'I';
    ret[1] = 'I';
    ret[2] = '\0';
    return(ret);
}
 
int main(int argc, char *argv[]) {
    int num = 123;
    char *roman = intToRoman(num);
    printf("%s\n", roman);
     
    return(0);
 }