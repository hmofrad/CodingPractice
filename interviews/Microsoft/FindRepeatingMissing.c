/*
 *  Problem: https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/
 *  Detect and Remove Loop in a Linked List
 *  Compile: gcc -o FindRepeatingMissing FindRepeatingMissing.c -g -Wall -fsanitize=address && ./FindRepeatingMissing    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void find(int arr[], int n) {
    int repeated = 0;
    int missing = 0;
    int s = 0;
    for(int i = 0; i < n; i++) {
        s += arr[i];
    }
    
    for(int i = 0; i < n; i++) {
        //printf("%d\n", i);
        int t = (arr[i] < 0) ? -arr[i] : arr[i];
        //printf("%d %d %d\n", i, arr[i], t);
        if(arr[t-1] > 0) {
            arr[t-1] = -arr[t-1];
            //int t = -arr[i];
            //arr[i] = arr[arr[i]-1];
            //arr[arr[i]-1] = t;
        }
        else {
            repeated = t;
            //if(arr[-arr[i]-1]
            printf("%d %d %d\n", i, arr[i], t);
        }
    }
    
    int su = (n * (n+1))/2;
    missing = su - (s-repeated);
    
    printf("repeated = %d missing = %d\n", repeated, missing);
}

int main(int argc, char **argv){
    int arr[] = {4, 3, 6, 2, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    find(arr, n);
    
    return(0);
}
