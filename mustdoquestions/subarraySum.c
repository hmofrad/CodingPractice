/*
 *  Problem: https://www.geeksforgeeks.org/find-subarray-with-given-sum/
 *  Find subarray with given sum
 *  Compile: gcc -o subarraySum subarraySum.c -g -Wall -fsanitize=address && ./subarraySum   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

char comp(int a, int b) {
    return(a == b);
}

int sum1(int arr[], int m, int sum) {
    int found = 0;
    for(int i = 0; i < m/2; i++) {
        int s = 0;
        for(int j = i; j <= m-1-i; j++) {
            s += arr[j];
        }
        printf("%d %d\n", i, s);
        if((s == sum) || ((s-arr[i]) == sum) || ((s-arr[m-1-i]) == sum)) {found = 1; break;}
    }
    return(found);
}

int sum2(int arr[], int m, int sum) {
    int found = 0;
    int curr_sum = arr[0];
    int j = 0;
    for(int i = 1; i < m; i++) {
        //printf("1.%d %d %d\n", i, arr[i], curr_sum);
        if(curr_sum < sum) {
            curr_sum += arr[i];
        }
        
        while(curr_sum > sum) {
            curr_sum -= arr[j]; 
            j++;
        } 
        if(curr_sum == sum) {
            found = 1; break;
        }
        //printf("2.%d %d\n", i, curr_sum);
    }
    return(found);
}


int main(int argc, char** argv){
    int arr[] = {1, 4, 20, 3, 10, 5};
    int m = sizeof(arr)/sizeof(arr[0]);
    int sum = 33;
    int f = sum2(arr, m, sum);
    printf("found=%d\n", f);
    return(0);
}
