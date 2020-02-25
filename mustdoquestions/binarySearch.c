/*
 *  Problem: Binary Search 
 *  Compile: gcc -o binarySearch binarySearch.c -g -Wall -fsanitize=address && ./binarySearch   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

char binarySearch1(int arr[], int left, int right, int x) {
    if(left < right) {
        int mid = left + (right-left)/2;
        if(arr[mid] == x) return(1);
        else if(arr[mid] > x) return(binarySearch1(arr, left, mid-1, x));
        else return(binarySearch1(arr, mid+1, right, x));
    }
    else {
        return(0);
    }
}
    

char binarySearch(int arr[], int m, int x) {
    char ret = 0;
    int left = 0;
    int right = m - 1;
    
    while(left < right) {
        int mid = left + ((right - left)/2);
        printf("%d %d %d %d\n", left, right, mid, x);
        if(arr[mid] == x) {

            ret = 1;
            break;
        }
        else if(arr[mid] > x) {
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }
    return(ret);
}

int main(int argc, char** argv){
    int arr[] = {4, 51, 200, 250, 400, 3001, 23340};
    int m = sizeof(arr)/sizeof(arr[0]);
    //char f = binarySearch(arr, m, 50);
    char f = binarySearch1(arr, 0, m-1, 50);
    printf("%d\n", f);
    
    return(0);
}
