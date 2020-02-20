/*
 *  Problem: https://www.geeksforgeeks.org/reverse-words-in-a-given-string/
 *  Reverse words in a given string
 *  Compile: gcc -o reverseWords reverseWords.c -g -Wall -fsanitize=address && ./reverseWords   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* reverse(char str[]) {
    int len = strlen(str);
    char* str1 = (char*) malloc(sizeof(char)*(len+1));
    //memset(str1, '\0', sizeof(char)*(len+1));
    str1[len] = '\0';
    int len1 = len;
    printf(">>>%ld\n", strlen(str1));
    //int j = 0;
    int k = len;
    int l = 0;
    for(int i = len-1; i >= 0; i--) {
        if((str[i] == ' ') || (i == 0)) {
            int st = i+1;
            if(i == 0) {
                st = i;
            }
            
            for(int j = st; j < k; j++) {
                str1[l] = str[j];
                l++;
                printf("%c", str[j]);
            }
            printf("\n");
            k = i;
            if(str[i] == ' ') {
                str1[l] = ' ';
                l++;
            }
        }
    }
    
    for(int i = 0; i < len1; i++) {
        printf("%c ", str1[i]);
    }
    printf(" > %s\n", str1);
    
    return(str1);
}



void reverse_word(char str[], int start, int end) {
    for(int i = start; i < start+(end - start)/2; i++) {
        char t = str[i];
        str[i] = str[end-1-i+start];
        str[end-1-i+start] = t;
    }
}

char* reverse1(char str[]) {
    int len = strlen(str);
    char* str1 = (char*) malloc(sizeof(char)*(len+1));
    str1[len] = '\0';
    int j = 0;
    for(int i = 0; i < len; i++) {
        if((str[i] == ' ') || ((i+1) == len)) {
            int start = j;
            int end = ((i+1) == len) ? len : i;
            
            reverse_word(str, start, end);
            printf("%d %d %s\n", start, end, str);
            j = i+1;
        }
    }
    
    for(int i = 0; i < len; i++) {
        str1[i] = str[i];
    }
    reverse_word(str1, 0, len);
    
    return(str1);
}


int main(int argc, char** argv){
    char str[] = "i Love Programming very very much";
    char* str1 = reverse1(str);
    printf("[%s]\n[%s]\n", str, str1);
    if(str1) free(str1);
    char str2[] = "asb"; 
    reverse_word(str2, 0, 3);
    printf("%s\n", str2);
    
    return(0);
}
