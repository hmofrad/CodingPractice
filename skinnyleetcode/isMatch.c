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
 
bool isMatch(char* s, char* p) {
    
    size_t sl = strlen(s);
    size_t pl = strlen(p);
    char *si = s;
    char *pi = p;
    bool ret = true;
    //for(p_iter = 0; p_iter < p_len; p_iter++) {
    while(*pi) {
        //printf("%c\n", *pi);
        if(*pi == '.') {
            //printf("dot(%c, %c, %d)\n", *pi, *si, ret);
            if(!*si) {
                ret = false;
                break;
            }
            pi++;
            si++;
        } else if(*pi == '*') {
            //printf("star(%c, %c, %d)\n", *pi, *si, ret);
            pi--;
            if(*pi) {
                while(*pi == *si) {
                    si++;
                }
                pi++;
            } else {
                ret = false;
                break;
            }
            pi++;
        } else {
            //printf("else(%c, %c, %d)\n", *pi, *si, ret);
            if((*pi != *si) || !*si) {
                ret = false;
                //break;
            }
            pi++;
            si++;
             //&& !(*(pi+1))
            if((!*pi && *si) || !*pi) {
                ret = false;
                if(*pi == *si) {
                    ret = true;
                }
                break;
            }
            if(*pi && !ret) {
                ret = true;
                si--;
            }
        }
    }
    
    return(ret);
}
 
int main(int argc, char *argv[]) {
    char *s = "aab";
    char *p = "c*a*b";
    printf("%s ? %s\n", s, p);
    bool r = isMatch(s, p);
    printf("isMatch=%d\n", r);
    return(0);
}







