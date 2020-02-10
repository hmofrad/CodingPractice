/*
 *  Problem: https://www.geeksforgeeks.org/c-program-replace-word-text-another-given-word/
 *  Given three strings ‘str’, ‘oldW’ and ‘newW’. The task is find all occurrences of the word ‘oldW’ and replace then with word ‘newW’. 
 *  Input : str[] = "xxforxx xx for xx", 
 *      oldW[] = "xx", 
 *      newW[] = "geeks"
 *  Output : geeksforgeeks geeks for geeks
 *  Compile: gcc -o replaceSubstring replaceSubstring.c -g -Wall -fsanitize=address && ./replaceSubstring   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* fix(char str[], char oldW[], char newW[]) {
    int str_len = strlen(str);
    int oldW_len = strlen(oldW);
    int newW_len = strlen(newW);

    int i = 0;
    int n = 0;
    while(i < str_len-oldW_len+1) {    
        int k = 0;
        for(int j = 0; j < oldW_len; j++) {
            if(str[i+k] != oldW[j]) {
                break;
            }
            k++;
        }
        if(k == oldW_len) {
            n++;
            i += oldW_len;
        }
        else {
            i++;
        }
    }
    

    int str1_len = str_len + (newW_len - oldW_len) * n;
    char* str1 = (char*) malloc(str1_len+1);
    memset(str1, 0, str1_len+1);
    
    int j = 0;
    i = 0;
    while(i < str_len-oldW_len+1) {    
        int k = 0;
        for(k = 0; k < oldW_len; k++) {
            if(str[i+k] != oldW[k]) {
                break;
            }
        }
        if(k == oldW_len) {
            for(k = 0; k < newW_len; k++) {
                str1[j] = newW[k];
                j++;
            }
            //for(k = 0; k < newW_len - oldW_len; k++) {
              //  str1[j] = str[i-newW_len+k];
                //k++;
                //j++;
            //}
            i += oldW_len;
        }
        else {
            str1[j] = str[i];
            j++;
            i++;
        }
    }
    printf("%s -->  %s\n", str, str1);
    return(str1);
}



int main(int argc, char **argv){
    char str[] = "xxforxx xx for xx";
    char oldW[] = "xx";
    char newW[] = "geek";
    char* str1 = fix(str, oldW, newW);
    printf("%s -->  %s\n", str, str1);
    free(str1);
    return(0);
}
