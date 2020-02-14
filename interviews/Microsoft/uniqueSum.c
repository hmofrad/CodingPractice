/*
 *  Problem: https://www.geeksforgeeks.org/print-uncommon-elements-two-sorted-arrays/
 *  Print uncommon elements from two sorted arrays. Given two sorted arrays of distinct elements, 
 *  Compile: gcc -o uniqueSum uniqueSum.c -g -Wall -fsanitize=address && ./uniqueSum   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

int uniqueSum(int arr1[], int m, int arr2[], int n) {
    int sum = 0;
    int i1 = 0;
    int i2 = 0;
    while((i1 < m) && (i2 < n)) {
        //printf("sum=%d arr1=%d arr2=%d\n", sum, arr1[i1], arr2[i2]);
        if(arr1[i1] < arr2[i2]) {
            sum += arr1[i1];
            i1++;
        }
        else if(arr1[i1] >= arr2[i2]) {
            sum += arr2[i2];
            i1++;
            i2++;
        }
    }
    
    
    if((i1 == m) && (i2 == n)) {
        return(sum);
    }

    if(i1 < m) {
        while(i1 < m) {
            sum += arr1[i1];
            i1++;
        }
    }
    else {
        while(i2 < n) {
            sum += arr2[i2];
            i2++;
        }
    }
    
    
    return(sum);
}

int main(int argc, char** argv){
    int arr1[] = {10, 20, 30};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {20, 25, 30, 40, 50};
    int n = sizeof(arr2)/sizeof(arr2[0]);
    int Usum = uniqueSum(arr1, m, arr2, n);
    printf("sum=%d\n", Usum);
    return(0);
}
