/*
 *  Problem: https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/
 *  Median in a stream of integers (running integers)
 *  Compile: gcc -o findMedian findMedian.c -g -Wall -fsanitize=address && ./findMedian   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};



void median(int arr[], int m) {
    int arr1[m];
    memset(arr1, 0, sizeof(arr1));

    arr1[0] = arr[0];
    int mid = arr[0];
    int n = 1;
    for(int i = 1; i < m; i++) {
        int j = 0;
        for(j = 0; j < n; j++) {
            if(arr1[j] > arr[i]) {
                for(int k = n-1; k >= j; k--) {
                    arr1[k+1] = arr1[k];
                }
                arr1[j] = arr[i];
                break;
            }
        }
        
        if(j == n) {
            arr1[j] = arr[i];
        }
        n++;
        
        if((n % 2) == 1) {
            mid = (arr[n/2] + arr[(n/2)-1])/2;
        }
        else {
            mid = arr[n/2];
        }
        printf("arr[%d]=%d Median=%d %d\n", i, arr[i], mid, n);
    }
    
    for(int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
}

int main(int argc, char** argv){
    int arr[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4}; 
    int m = sizeof(arr)/sizeof(arr[0]);
    median(arr, m);
    
    return(0);
}
