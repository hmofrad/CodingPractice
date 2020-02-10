/*
 *  Problem: geeksforgeeks.org/find-the-element-that-appears-once/
 *  Given an array where every element occurs three times, except one element which occurs only once. 
 *  Find the element that occurs once. Expected time complexity is O(n) and O(1) extra space.
 *  Compile: gcc -o findElement findElement.c -g -Wall -fsanitize=address && ./findElement    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3}
Output: 2
*/

int find(int arr[], int n) {
    
    
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int max = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    
    int arr1[max+1];
    memset(arr1, 0, sizeof(arr1));
    
    for(int i = 0; i < n; i++) {
        arr1[arr[i]]++;
    }
    
    for(int i = 0; i < max; i++) {
        if(arr1[i] == 1) {
            return(i);
        }
    }
    
    return(-1);
}

int find1(int arr[], int n) {
    int ones = 0;
    int twos = 0;
    int not_three = 0;
    int x = 0;
    
    for(int i = 0; i < n; i++) {
        x = arr[i];
        twos |= (ones & x);
        ones ^= x;
        not_three = ~(ones & twos);
        ones &= not_three;
        twos &= not_three;
    }
    
    return(ones);
}


int main(int argc, char **argv){
    int arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num = find(arr, n);
    printf("? %d\n", num);
    num = find1(arr, n);
    printf("? %d\n", num);
    return(0);
}
