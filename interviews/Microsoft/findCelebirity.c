/*
 *  Problem: https://www.geeksforgeeks.org/the-celebrity-problem/
 *  The Celebrity Problem: In a party of N people, only one person is known to everyone. Such a person may be present in the party, 
 *  if yes, (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B? “. 
 *  Find the stranger (celebrity) in minimum number of questions.
 *  Compile: gcc -o findCelebirity findCelebirity.c -g -Wall -fsanitize=address && ./findCelebirity    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int HaveAcquaintance(int A, int B) {
    return((A != 2) && (B == 2));
}


int find(int n) {
    int celebrity = -1;
    
    int mat[n][n];
    memset(mat, 0, sizeof(mat));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {  
            mat[i][j] = HaveAcquaintance(i, j);
        }
    }
    
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {    
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    
    for(int j = 0; j < n; j++) { 
        int deg = 0;
        for(int i = 0; i < n; i++) {
            deg += mat[i][j];
        }
        if(deg == (n-1)) {
            celebrity = j;
            break;
        }
    }
    
    return(celebrity);
}


int main(int argc, char **argv){
    int n = 4;
    int celebrity = find(n);
    printf("celebrity=%d\n", celebrity);
    return(0);
}
