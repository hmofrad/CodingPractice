/*  
 *  Problem: romanToInt (https://leetcode.com/problems/roman-to-integer/description/)
 *  Compile: gcc -o romanToInt romanToInt.c -g -Wall -Werror 
 *  Execute: ./romanToInt
 *  (c) Mohammad HMofrad, 2018
 *  (e) mohammad.hmofrad@pitt.edu
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number(char roman_numeral) {
    int number = 0; 
    switch(roman_numeral) {
        case 'I':
            number = 1;
            break;
        case 'V':
            number = 5;
            break;
        case 'X':
            number = 10;
            break;
        case 'L':
            number = 50;
            break;
        case 'C':
            number = 100;
            break;
        case 'D':
            number = 500;
            break;
        case 'M':
            number = 1000;
            break;
        default:
            printf("Invalid roman numeral %c\n", roman_numeral);
    }
    return(number);
}
 
 int romanToInt(char* s) {
    int l = strlen(s);
    char *i = s;
    int j = l;
    int place = 1;
    int num = 0;
    int num1 = 0;
    int num2 = 0;
    while(*i) {
        num1 = number(*i);
        num2 = 0;
        num += num1; 
        if(j > 1) {
            num2 = number(*(i+1));
            if(num2 > num1) {
                num += num2;
                num -= 2 * num1;
                i++;
                j--;
            }
        }
        
        while(*i == *(i+1)){
           num +=num1; 
           i++; 
           j--;
        }
        i++;
        j--;
    }
    return(num);
}
 
int main(int argc, char *argv[]) {
    
    char *roman_numeral = "MCMXCVI";    
    int num = romanToInt(roman_numeral);
    printf("%s=%d\n", roman_numeral, num);
    return(0);
}
