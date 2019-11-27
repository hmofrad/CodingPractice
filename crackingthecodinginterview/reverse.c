/*
Cracking the coding interview: Problem 1.2
Compile and run:  gcc -o reverse reverse.c && ./reverse
(c) Mohammad Hasanzadeh mofrad, 2019
(e) m.hasanzadeh.mofrad@gmail.com
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverse(char* str) {
    char* c = str;
    int n = 0;
    while(*c) {
        c++;
        n++;
    }
    
    int i = 0;
    for(i = 0; i < n/2; i++) {
        char t = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = t;
    }
}    

int main(int argc, char* argv[]) {
    char str[] = "Hello, Worldc!";
    printf("1. %s\n", str);
    reverse(str);
    printf("2. %s\n", str);
    return(0);
}