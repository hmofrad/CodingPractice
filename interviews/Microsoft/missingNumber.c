/*
 *  Problem: https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/
 *  Find the smallest positive number missing from an unsorted array
 *  Compile: gcc -o missingNumber missingNumber.c -g -Wall -fsanitize=address && ./missingNumber   
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

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int abs(int a) {
    return((a >= 0) ? a : -a); 
}

int segregate(int arr[], int m) {
    int j = 0;
    for(int i = 0; i < m; i++) {
        if(arr[i] < 0) {
            swap(&arr[i], &arr[j]);
            printf("arr[%d]=%d, arr[%d]=%d\n", i, arr[i], j, arr[j]);
            j++;
        }
    }
    return(j);
}

int find(int arr[], int m) {
    print(arr, m);
    for(int i = 0; i < m-1; i++) {
        for(int j = i+1; j < m; j++) {
            if(arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
    print(arr, m);
    int missing = 0;
    int prev = arr[0];
    for(int i = 1; i < m; i++) {
        int curr = arr[i];
        if((prev > 0) && (curr > 0)) {
            int diff = curr - prev;
            if(diff > 1) {
                missing = prev+1;
                break;
            }
        }
        prev = curr;
    }
    
    
    return(missing);
}

int find1(int arr[], int m) {
    print(arr,m);
    
    for (int i = 0; i < m; i++) { 
        int index = abs(arr[i]) - 1;
        if (index < m && arr[index] > 0) 
            arr[index] = -arr[index]; 
    } 
    
    for (int i = 0; i < m; i++) 
        if (arr[i] > 0) 
            return i + 1; 
        
    return m + 1;
}

int main(int argc, char** argv){
    //int arr[] = {20, 30, -7, 60, 80, 10, -10, 15};
    int arr[] = {2, 3, -7, 6, 8, 1, -10, 15};
    int m = sizeof(arr)/sizeof(arr[0]);
    
    //int missing = find(arr, m);
    //printf("? %d\n", missing);
    
    print(arr, m);
    int shift = segregate(arr, m);
    print(arr, m);
    
    int missing = find1(arr+shift, m-shift);
    printf("? %d\n", missing);
    print(arr, m);
    return(0);
}
