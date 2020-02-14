/*
 *  Problem: https://www.geeksforgeeks.org/find-excel-column-name-given-number/
 *  MS Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. 
 *  In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA”.
 *  705 --> AAC
 *  Compile: gcc -o num2column num2column.c -g -Wall -fsanitize=address && ./num2column   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* num2col(int num) {
    char* col = NULL;
    const NUM_ALPHA = 26;
    if(num == 0) {
        return(col);
    }
    
    int i = 0;
    int n = num;
    while(n) {
//        printf("%d %d %d %c\n", num-1, (num-1)/NUM_ALPHA, (num-1)%NUM_ALPHA, ((num-1)%NUM_ALPHA) + 'A');
        
        n /= NUM_ALPHA;
        i++;
    }
    
    col = (char*) malloc(sizeof(char) * (i+1));
    memset(col, 0, sizeof(char) * (i+1));
    
    n = num;
    while(n) {
        col[--i] = ((n-1)%NUM_ALPHA) + 'A';
        n /= NUM_ALPHA;
    }
    
    return(col);
}

int main(int argc, char** argv){
    int num = 70095;
    char* col = num2col(num);
    if(col) printf("%s\n", col);
    if(col) free(col);
    return(0);
}
