/*
 *  Problem: https://www.geeksforgeeks.org/print-last-10-lines-of-a-given-file/
 *  Program to print last 10 lines
 *  Compile: gcc -o printN printN.c -g -Wall -fsanitize=address && ./printN
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
void printN(char* str, int n, char delim) {
    if(n == 0) return;

    int count = 0;
    char* c = str;
    while(*c) {
        if(*c == delim) {
            count++;
        }
        c++;
    }

    int t = (count > n) ? (count - n) : 0;

    c = str;
    while(t) {
        if(*c == delim) t--;
        c++;
    } 
printf("<<<\n");    
    
    while(*c) {
        //printf("%c\n", *c);
        if(*c == delim) {
            printf("%c", *c);
        }
        else {
            printf("%c", *c);
        }
        c++;
    }
printf(">>>\n");        

}
*/
void printN(char* str, int n, char delim) {
    if(n == 0) return;

    int count = 0;
    char* c = str;
    while(*c) {
        if(*c == delim) {
            count++;
        }
        c++;
    }

    int t = (n > count) ? 0 : n+1;
    c = (t == 0) ? str : c;
    
    printf("<%d %d %c>", t, count, *c);
    int sz = strlen(str);
    int s = 0;
    while(t && (s < sz)) {
        if(*c == delim) {
            t--;
        }
        c--;
        s++;
    } 
    printf("%s\n", c);    
}


int main(int argc, char **argv){
    char *str1 = "str-1\nstr0\nstr1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7\n";
    //char* str1 = "str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7\nstr8\nstr9"
    //             "\nstr10\nstr11\nstr12\nstr13\nstr14\nstr15\nstr16\nstr17"
    //             "\nstr18\nstr19\nstr20\nstr21\nstr22\nstr23\nstr24\nstr25"; 
    int n = 9;
    char delim = '\n';
    printN(str1, n, delim);
    
    //void printN(str2);
    return(0);
}
