/*
 *  Problem: https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
 *  Next Greater Element
 *  Compile: gcc -o nextGreaterElement nextGreaterElement.c -g -Wall -fsanitize=address && ./nextGreaterElement   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* nge(int arr[], int m) {
    int* arr1 = (int*) malloc(sizeof(int) * m);
    memset(arr1, -1, sizeof(int) * m);
    
    for(int i = 0; i < m-1; i++) {
        for(int j = i+1; j < m; j++) {
            if(arr[j] > arr[i]) {
                arr1[i] = arr[j];
                break;
            }
        }
    }
    
    return(arr1);
}

int main(int argc, char** argv){
    int arr[] = {4, 5, 2, 25};
    int m = sizeof(arr)/sizeof(arr[0]);
    int* arr1 = nge(arr, m);
    for(int i = 0; i < m; i++) {printf("%d ", arr1[i]);} printf("\n");
    if(arr1) free(arr1);
    return(0);
}
