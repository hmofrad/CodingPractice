/*  
 *  Problem: intToRoman (https://leetcode.com/problems/palindrome-number/description/)
 *  Compile: gcc -o intToRoman intToRoman.c -g -Wall -Werror 
 *  Execute: ./intToRoman
 *  (c) Mohammad HMofrad, 2018
 *  (e) mohammad.hmofrad@pitt.edu
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

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

int ipow(int num, int exp) {
    int i = 0;
    int ret = 1;
    for(i = 0; i < exp; i++) {
        ret *= num;
    }
    return(ret);
}

char roman_numeral(int place) {
    char roman_index;
    switch(place) {
        case 1:
            roman_index = 'I';
            break;
        case 5:
            roman_index = 'V';
            break;
        case 10:
            roman_index = 'X';
            break;
        case 50:
            roman_index = 'L';
            break;
        case 100:
            roman_index = 'C';
            break;
        case 500:
            roman_index = 'D';
            break;
        case 1000:
            roman_index = 'M';
            break;
        default:
            printf("Invalid place=%d", place);
            break;
    }
    return(roman_index);
}
 
char *intToRoman(int num) {
    char *roman_num = malloc(sizeof(char) * MAX_LENGTH);
    int i = 0;
    memset(roman_num, '\0', sizeof(char) * MAX_LENGTH);
    char *roman_index = roman_num;
    char *temp_index = NULL;
    int n = numDigits(num);    
    int place = ipow(10, n - 1);
    int num1 = 0;
    int num2 = 0;
    
    while(num) {
        num1 = num / place;
        num = num - (num1 * place);
        printf("%d %d\n", num1, place);
        
        // 1, 2, 3, 6, 7, and 8
        if((num1 <= 3) || (num1>= 6) && (num1 <= 8)) {
            if(num1 > 5) {
                roman_num[i] = roman_numeral(5 * place);
                i++;
                num1 = num1 % 5;
            }
            while(num1) {
                roman_num[i] = roman_numeral(place);
                i++;
                num1--;
            }
        // 4, and 9    
        } else if(((((num1 * place) + place) - place) == 4 * place) || ((((num1 * place) + place) - place) == 9 * place)) { 
            roman_num[i] = roman_numeral(place);
            i++;
            roman_num[i] = roman_numeral((num1 * place) + place);
            i++;
        // 5, and 10
        } else {
            roman_num[i] = roman_numeral(num1 * place);
            i++;
        }
        
        place = place / 10;
    }
    return(roman_num);
}
 
int main(int argc, char *argv[]) {
    int num = 60;
    printf("Number:%d\n", num);
    char *roman = intToRoman(num);
    printf("Roamn numeral: %s\n", roman);
     
    return(0);
 }