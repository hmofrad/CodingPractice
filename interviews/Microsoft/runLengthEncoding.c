/*
 *  Problem: https://www.geeksforgeeks.org/run-length-encoding/
 *  Given an input string, write a function that returns the Run Length Encoded string for the input string.
 *  For example, if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6”.
 *  write a program to find the least common ancestor.
 *  Compile: gcc -o runLengthEncoding runLengthEncoding.c -g -Wall -fsanitize=address && ./runLengthEncoding    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* encode(char* str) {
    int sz = sizeof(char) * strlen(str) * 2;
    char* cipher = malloc(sz);
    memset(cipher, '\0', sz);
    
    char* c = str;
    char* p = NULL;
    int i = 0;
    int j = 0;
    int k = 0;
    while(*c) {
        printf("%c\n", *c);
        if((p && *p != *c) || ((k+1) == strlen(str))) {
            if((k+1) == strlen(str)) {
                cipher[j] = *p;
                cipher[j+1] = '0'+i+1;
                cipher[j+2] = '\0';
                printf("[%c %d]\n", *p, i+1);                
            }
            else {
                cipher[j] = *p;
                cipher[j+1] = '0'+i;
                j += 2;
                printf("[%c %d]\n", *p, i);
                i = 0;
                p = c;
            }
        }
        else {
           p = c; 
        }
        
        c++;
        i++;
        k++;
    }
    printf("\n");
    printf("[%c %d]\n", *p, i);
    //cipher[j] = *p;
    //cipher[j+1] = '0'+i;
    //cipher[j+2] = '\0';
    
    
    return(cipher);
}

int main(int argc, char **argv){
    char* str = "wwwwaaadexxxxxx";
    char* cipher = encode(str);
    printf("%s\n", cipher);
    free(cipher);
    return(0);
}
