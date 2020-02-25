/*
 *  Problem: Frequency sort
 *  Compile: gcc -o frequencySort frequencySort.c -g -Wall -fsanitize=address && ./frequencySort   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_arr(int arr[], int m) {
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

int* unique(int arr[], int m) {
    int* u = (int*) malloc(sizeof(int) * (m+1));
    memset(u, 0, sizeof(int)*(m+1));
    int k = 0;
    for(int i = 0; i < m; i++) {
      //  printf("i=%d arr=%d k=%d\n", i, arr[i], k);
        //char tf = 1;
        int j = 0;
        for(j = 0; j < k; j++) {
            if(arr[i] == u[j]) {
                //tf = 0;
                break;
            }
        }
        if(j == k) {
            u[k] = arr[i];
            k++;
        }
    }
    //printf(".>>%d\n", k);
    u[m] = k;
    return(u);
}

void frequency_sort(int arr[], int m) {
    
    int* u = unique(arr, m);
    int cnt[u[m]];
    memset(cnt, 0, sizeof(cnt));
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < u[m]; j++) {
            if(arr[i] == u[j]) {
                cnt[j]++;
                break;
            }
        }
    }
    
    
    print_arr(u, u[m]);
    print_arr(cnt, u[m]);
    
    for(int i = 0; i < u[m]-1; i++) {
        for(int j = i+1; j < u[m]; j++) {
            if(cnt[j] > cnt[i]) {
                swap(&cnt[i], &cnt[j]);
                swap(&u[i], &u[j]);
            }
        }
    }
    
    
    int k = 0;
    for(int i = 0; i < u[m]; i++) {
        for(int j = 0; j < cnt[i]; j++) {
            arr[k] = u[i];
            k++;
        }
    }
    
    print_arr(u, u[m]);
    print_arr(cnt, u[m]);
    free(u);
    /*
    for(int i = 0; i < m-1; i++) {
        for(int j = i+1; j < m; j++) {    
            if(arr[i] == arr[j]) {
                swap(&arr[i+1], &arr[j]);
                i++;        
            }
        }
    }
    
    int im = 0;
    int fm = 1;
    int k = 0;
    int f = 0;
    int j = 0;
    for(int i = 0; i < m; i++) {
        if((i+1 < m) && (arr[i] == arr[i+1])) {
            f++;
        }
        else {
            if(fm < f) {
                fm = f;
                im = k;
            }
            f = 1;
            k = i+1;
        }
    }
    
    printf("%d %d\n", im, fm);
    */
    
}

int main(int argc, char** argv){
    int arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8};
    int m = sizeof(arr)/sizeof(arr[0]);
    print_arr(arr, m);
    frequency_sort(arr, m);
    print_arr(arr, m);
    
    return(0);
}
