/*
 *  Problem: myAtoi (https://leetcode.com/problems/string-to-integer-atoi/description/)
 *  Compile: gcc -o myAtoi myAtoi.c -g -Wall -Werror 
 *  Execute: ./myAtoi
 *  (c) Mohammad HMofrad, 2017
 *  (e) mohammad.hmofrad@pitt.edu
 */
 
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 
 int myAtoi(char *str) {
    char *i = str;
    int r = 0;
    int m = 1;
    int s = 1;
    int e = 0;
    while(*i) {
        if((*i >= 48) && (*i <= 57)) {
            r = (m * r) + (*i % 48);
            m = 10;
        } else if(!e && (*i == 43)) { 
            s = 1;
            e = 1;
        } else if(!e &&(*i == 45)) {
            s = -1;
            e = 1;
        } else if(!r && (*i == 32)) { 
            ;
        } else {
            printf("%c %d\n", *i, *i);
            r = 0;
            break;
        }
        i++;
    }
    r = s * r;
    return(r);
 }
 
 int main(int argc, char *argv[]) {
    char *str = "-0012a42";
    //char *str = "alizandvakil";
    int r = myAtoi(str);
    printf("%d %d\n", r, atoi("  -0012a42"));
    return(0);
 }