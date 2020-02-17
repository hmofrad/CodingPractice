/*
 *  Problem: https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/
 *  Search a Word in a 2D Grid of characters
 *  Compile: gcc -o searchWord searchWord.c -g -Wall -fsanitize=address && ./searchWord   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char search2d(char mat[3][13], int m, int n, int i, int j, char* word) {
    char found = 0;
    int l = strlen(word);
    if((j + l) <= n) {
        char found1 = 1;
        for(int k = j; k < j+l; k++) {
            if(mat[i][k] != word[k-j]) {
                found1 = 0;
                break;
            }
        }
        if(found1) found++;
    }
    
    
    if((i + l) <= m) {
        char found1 = 1;
        for(int k = i; k < i+l; k++) {
            if(mat[k][j] != word[k-i]) {
                found1 = 0;
                break;
            }
        }
        if(found1) found++;
    } 
    
    if((i+l) <= m) {
        char found1 = 1;
        int kk = j;
        for(int k = i; k < i+l; k++) {
            if(mat[k][kk] != word[k-i]) {
                found1 = 0;
                break;
            }
            kk++;
        }
        if(found1) found++;
    }
    
    
    return(found);
}

void search(char mat[3][13], int m, int n, char* word) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) { 
            char f;
            if((f = search2d(mat, m, n, i, j, word)) != 0) {
                printf("[%d %d]=%s %d\n", i, j, word, f);
            }
        }
    }
}


int main(int argc, char** argv){
    int m = 3;
    int n = 13;
    char mat[3][13] = {"GEEESFORGEEKS",
                       "GEEKSQUIZGEEK",
                       "IEEQAPRACTICE"};
    
    int c = sizeof(mat[0])/sizeof(mat[0][0]) ;
    int r = sizeof(mat)/sizeof(mat[0]);
    printf("#rows=%d #cols=%d\n", r, c);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
    
    search(mat, m, n, "EEE");
    
    return(0);
}
