/*
 *  Problem: https://www.geeksforgeeks.org/merge-k-sorted-arrays/
 *  Merge k sorted arrays
 *  Compile: gcc -o mergeKSorted mergeKSorted.c -g -Wall -fsanitize=address && ./mergeKSorted   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int* merge(int mat[3][4], int m, int n) {
    int* arr = malloc(sizeof(int) * m * n);
    int indices[m];
    memset(indices, 0, sizeof(indices));
    int k = 0;
    int i = 0;
    while(i < (m*n)) {
        int min_val = INT_MAX;
        int min_idx = 0;
        for(int j = 0; j < m; j++) {
            if((indices[j] < n) && (mat[j][indices[j]] < min_val)) {
                min_val = mat[j][indices[j]];
                min_idx = j;
            }
        }
        arr[k] = min_val;
        indices[min_idx]++;
        k++;
        i++;
    }
    return(arr);
}

int main(int argc, char** argv){
    int m = 3;
    int n = 4;
    int mat[3][4] = {{1, 3, 5, 7},
                     {2, 4, 6, 8},
                     {0, 9, 10, 11}};
    //int nr = sizeof(mat)/sizeof(mat[0]);
    //int nc = sizeof(mat[0])/sizeof(mat[0][0]);
    int* arr = merge(mat, m, n);
    for(int i = 0; i < m*n; i++) {printf("%d ", arr[i]);} printf("\n");
    free(arr);
    return(0);
}
