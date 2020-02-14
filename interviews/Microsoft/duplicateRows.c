/*
 *  Problem: https://www.geeksforgeeks.org/find-duplicate-rows-binary-matrix/
 *  Find duplicate rows in a binary matrix
 *  Compile: gcc -o duplicateRows duplicateRows.c -g -Wall -fsanitize=address && ./duplicateRows   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

void printDuplicates(int mat[][7], int m, int n) {
    for(int i = 0; i < m-1; i++) {
        for(int j = i+1; j < m; j++) {
            char yes = 1;
            for(int k = 0; k < n; k++) {
                if(mat[i][k] != mat[j][k]) {
                    yes = 0;
                }
            }
            if(yes) printf("%d == %d\n", i, j);
        }
    }
}


int main(int argc, char** argv){
    int m = 6;
    int n = 7;
    int mat[6][7] = {{1, 1, 0, 1, 0, 1, 0},
                     {0, 0, 1, 0, 0, 1, 0},
                     {1, 0, 1, 1, 0, 0, 0},
                     {1, 1, 0, 1, 0, 1, 0},
                     {0, 0, 1, 0, 0, 1, 0},
                     {0, 0, 1, 0, 0, 1, 0}};
    
    int c = sizeof(mat[0])/sizeof(mat[0][0]) ;
    int r = sizeof(mat)/sizeof(mat[0]);
    printf("row=%d col=%d\n", r, c);
    
    
    
    
    printDuplicates(mat, r, c);    
    
    return(0);
}
