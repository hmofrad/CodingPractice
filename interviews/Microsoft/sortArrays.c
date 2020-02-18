/*
 *  Problem: https://www.geeksforgeeks.org/sort-array-according-order-defined-another-array/
 *  Sort an array according to the order defined by another array
 *  Compile: gcc -o sortArrays sortArrays.c -g -Wall -fsanitize=address && ./sortArrays   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

void print(int arr[], int m) {
    for(int i = 0; i < m; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
int move(int arr1[], int m, int arr2[], int n) {
    int j = 0;
    int k = 0;
    for(int i = 0; i < m; i++) {
        if(arr1[i]
    }
}
*/

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sort1(int arr[], int m) {
    for(int i = 0; i < m-1; i++) {
        for(int j = i+1; j < m; j++) {
            if(arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void sort(int arr1[], int m, int arr2[], int n) {
    print(arr1, m);
    print(arr2, n);
    
    int k = 0;
    int i = 0;
    while((i < m) && (k < n)) {
        int ii = i;
        //char c = 0;
    //for(int i = 0; i < m; i++) {
        //if(k < n) {
            //int b = i;
            for(int j = i; j < m; j++) {
                if(arr1[j] == arr2[k]) {
                    swap(&arr1[i], &arr1[j]);
                    i++;
                    //c = 1;
                }
                //if(i >= m) break;
            }
            k++;
        //}
        if(i == ii) i++; 
    }
    
    printf("%d %d\n", i, k);
    sort1(arr1+i, m-i);
    
    
    
    print(arr1, m);
}

int main(int argc, char** argv){
    int arr1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {2, 1, 8, 3};
    int n = sizeof(arr2)/sizeof(arr2[0]);
    sort(arr1, m, arr2, n);
    return(0);
}
