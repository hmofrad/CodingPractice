/*
 *  Problem: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
 *  Largest Sum Contiguous Subarray
 *  Compile: gcc -o largestSum largestSum.c -g -Wall -fsanitize=address && ./largestSum   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int largest_contiguous_sum(int arr[], int m) {
    int sum = INT_MIN;
    for(int i = 0; i < m/2; i++) {
        int s = 0;
        for(int j = i; j <= m-i-1; j++) {    
            s += arr[j];
        }
        s = (s-arr[i] > s) ? s-arr[i] : s;
        s = (s-arr[m-i-1] > s) ? s-arr[m-i-1] : s;
        sum = (s > sum) ? s : sum;
    }
    return(sum);
}

int largest_contiguous_sum1(int arr[], int m) {
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    
    for(int i = 0; i < m; i++) {
        max_ending_here += arr[i];
        
        if(max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
        
        if(max_ending_here < 0) {
            max_ending_here = 0;
        }
        
    }
    return(max_so_far);
}


int main(int argc, char** argv){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int s = largest_contiguous_sum1(arr, m);
    printf("sum=%d\n", s);
    return(0);
}
