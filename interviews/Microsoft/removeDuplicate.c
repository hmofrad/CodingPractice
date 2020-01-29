/*
 *  Problem: https://www.geeksforgeeks.org/remove-duplicates-from-a-given-string/
 *  Given a string S, the task is to remove all the duplicates in the given string.
 *  Compile: gcc -o removeDuplicate removeDuplicate.c -g -Wall -fsanitize=address && ./removeDuplicate
 *  
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
char* removeDuplicate(char str[], int n) {
    char* str1 = (char*) malloc(n * sizeof(char));
    memset(str1, 0, (n * sizeof(char)));
    
    int alphas[26];
    memset(alphas, 0, sizeof(alphas));
    
    for(int i = 0; i < n; i++) {
        alphas[str[i]-'a']++;
    }

    char* t = str1;
    int sz = 0;
    for(int i = 0; i < n; i++) {
        if(alphas[str[i]-'a']) {
            printf("%c\n", str[i]);
            *t = str[i];
            t++;
            alphas[str[i]-'a'] = 0;
            sz++;
        }
    }
    sz++;
    
    str1 = (char*) realloc(str1, sz * sizeof(char));
    
    return(str1);
}
*/

char* removeDuplicate(char str[], int n) {
    int index = 0;
    for(int i = 0; i < n; i++) {
        int j = 0;
        for(j = 0; j < i; j++) {
            printf("i=%d j=%d\n", i, j);
            if(str[j] == str[i]) {
                printf("BRK\n");
                break;
            }
        }
        if(j == i) {
            str[index] = str[i];
            index++;
        }
    }
    return(str);
}


int main(int argc, char **argv){
    char s[] = "geeksforgeeks";
    int n = sizeof(s)/sizeof(s[0]);
    printf("s=%s n=%d\n", s, n);
    char* t = removeDuplicate(s, n);
    int m = sizeof(t)/sizeof(t[0]);
    printf("t=%s m=%d\n", t, m);
    return(0);
}
