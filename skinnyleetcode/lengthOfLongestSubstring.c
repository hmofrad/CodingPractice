/*
 *  Problem: lengthOfLongestSubstring (https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)
 *  Compile: gcc -o lengthOfLongestSubstring lengthOfLongestSubstring.c -g -Wall -Werror 
 *  Run ./lengthOfLongestSubstring
 *  (c) Mohammad H-Mofrad, 2017
 *  (e) mohammad.hmofrad@pitt.edu
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
 int lengthOfLongestSubstring(char *str) {
     
    char *str_index = str;
    int length = 0;
    int str_length = 0;
    while(*str_index) {
        str_length++;
        str_index++;
    }

    int i = 0;
    int j = 0;
    int l = 0;
    char b = 1;

    for(l = str_length; l > 0; l--) {
        str_index = str;
        length = str_length;
        while(*str_index && length >= l) {
            b = 1;
            length--;
            for(i = 0; i < l; i++) {
                for(j = i + 1; j < l; j++){
                    if(*(str_index + i) == *(str_index + j)) {
                        b = 0;
                        break;
                    }
                }
                if(!b)
                    break;
            }
            
            if(!b) {
                str_index++;    
            }
            else {
                b = -1;
                break;
            }
        }
        if(b == -1)
            break;
    }  
     return(l);
 }
 
 int main(int argc, char *argv[]) {
    char *str1 = "abcabcbb";
    (void) str1;
    char *str2 = "bbbbb";
    (void) str2;
    char *str3 = "pwwkew";
    printf("%s (%d)\n", str1, lengthOfLongestSubstring(str1)); 
    printf("%s (%d)\n", str2, lengthOfLongestSubstring(str2)); 
    printf("%s (%d)\n", str3, lengthOfLongestSubstring(str3)); 
    return(0);
 }