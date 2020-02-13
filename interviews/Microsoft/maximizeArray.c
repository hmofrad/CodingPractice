/*
 *  Problem: https://www.geeksforgeeks.org/maximize-elements-using-another-array/
 *  Maximize elements using another array
 *  Input : arr1[] = {2, 4, 3}
 *  arr2[] = {5, 6, 1}
 *  Output : 5 6 4
 *  Compile: gcc -o maximizeArray maximizeArray.c -g -Wall -fsanitize=address && ./maximizeArray   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

void sort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] < arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }            
    }    
}

void print(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* max(int arr1[], int n, int arr2[], int m) {
    int* arr = (int *) malloc(sizeof(int) * n);
    
    sort(arr1, n);
    sort(arr2, m);
    print(arr1, n);
    print(arr2, m);
    
    int i = 0;
    int i1 = 0;
    int i2 = 0;
    while((i1 < n) && (i2 < m) && (i < n)) {
        if(arr1[i1] > arr2[i2]) {
            arr[i] = arr1[i1];
            i1++;
            i++;
        }
        else if(arr1[i1] < arr2[i2]) {
            arr[i] = arr2[i2];
            i2++;
            i++;
        }
        else {
            arr[i] = arr1[i1];
            i1++;
            i++;
            i2++;
        }
    }
    return(arr);
}

int main(int argc, char** argv){
    int arr1[] = {7, 4, 8, 0, 1}; // {2, 4, 3};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {9, 7, 2, 3, 6};//{5, 6, 1};
    int m = sizeof(arr2)/sizeof(arr2[0]);
    int* arr = max(arr1, n, arr2, m);
    print(arr, n);
    free(arr);
    return(0);
}
