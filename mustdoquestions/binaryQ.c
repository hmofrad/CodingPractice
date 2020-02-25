/*
 *  Problem: Binary
 *  Compile: gcc -o binaryQ binaryQ.c -g -Wall -fsanitize=address && ./binaryQ   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM_BITS 32

char get_bit(int n, int i) {
    int mask = 1 << i;
    return((mask & n) != 0);
}

void set_bit(int* n, int i) {
    int mask = 1 << i;
    *n |= mask;
}



void print_bits(int n) {
    for(int i = 0; i < MAX_NUM_BITS; i++) {
        printf("%d", get_bit(n, i));
    }
    printf("\n");
}

int count_bits(int n) {
    int i = 0;
    while(n) {
        n &= (n-1);
        i++;
    }
    return(i);
}




int main(int argc, char** argv){
    int n = 1029;
    print_bits(n);  
    print_bits(-n-1);  
    
    int c = count_bits(n);
    printf("%d\n", c);
    
    //set_bit(&n, 3);
    //print_bits(n);      
    return(0);
}
