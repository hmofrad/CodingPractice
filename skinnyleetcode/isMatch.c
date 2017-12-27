/*  Incompelete because it was hard :-s
 *  Problem: isMatch (https://leetcode.com/problems/palindrome-number/description/)
 *  Compile: gcc -o isMatch isMatch.c -g -Wall -Werror 
 *  Execute: ./isMatch
 *  (c) Mohammad HMofrad, 2017
 *  (e) mohammad.hmofrad@pitt.edu
 */
 
typedef int bool ;
#define true 1
#define false 0
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
//bool dot() {
//    
//}    
 
bool isMatch(char* s, char* p) {
    //char *i = s;
    //char *j = p;
    /*
    while(*i) {
        printf("%c ", *i);
        i++;
    }
    printf("\n");
    
    while(*j) {
        printf("%c ", *j);
        j++;
    }
    printf("\n");
    */
    //i = s;
    //j = p;
    /*
    while(true) {
        printf("%c %c\n", *i, *j);

        if(*j == '.') {
            printf("dot(%c)\n", *j);
            
        } else if(*j == '*') {
            printf("star(%c)\n", *j);
        } else {
            
        }
        
        if(*i) {
            i++;
        }
        if(*j) {
            j++;
        }
        
        if(!*i && !*j) {
            break;
        }

    }
    */
    
    size_t sl = strlen(s);
    size_t pl = strlen(p);
    char *si = s;
    char *pi = p;
    bool ret = true;
    //for(p_iter = 0; p_iter < p_len; p_iter++) {
    while(*pi) {
        //printf("%c\n", *pi);
        if(*pi == '.') {
            printf("dot(%c, %c)\n", *pi, *si);
            if(!*si) {
                ret = false;
                break;
            }
            pi++;
            si++;
        } else if(*pi == '*') {
            printf("star(%c, %c)\n", *pi, *si);
            pi++;
            si++;
            
        } else {
            printf("else(%c, %c)\n", *pi, *si);
            if((*pi != *si) || !*si) {
                ret = false;
                break;
            }
            pi++;
            si++;
        }
        

    }
    
    return(ret);
}
 
int main(int argc, char *argv[]) {
    char *s = "aab";
    char *p = "c*a*b";
    bool r = isMatch(s, p);
    printf("isMatch=%d\n", r);
    return(0);
}







