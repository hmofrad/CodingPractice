/*
 *  Problem: convert
 *  Compile: gcc -o convert convert.c -g -Wall -Werror 
 *  Run ./convert
 *  (c) Mohammad H-Mofrad, 2017
 *  (e) mohammad.hmofrad@pitt.edu
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    char *returned_value = malloc(sizeof(char) * strlen(s));
    memset(returned_value, 0, sizeof(char) * strlen(s));
    
    printf("%s\n", s);
    char *i = s;
    int j = 0;
    
    while(*i)
    {
        if((j%numRows == 0) && (j != 0))
        {
            printf("\n %c \n", *i);    
            j = 0;
            //numColumns++;
        }
        else
        {
            printf("%c ", *i);
            j++;
        }
        i++;
    }
    printf("\n");
    int numColumns = 1 + ((strlen(s) - 1) / (numRows + 1)); // ceiling division
    i = s;
    printf(" %d\n", numColumns);
    int k = 0;
    for(j = 0; j < numColumns; j++)
    {
        printf("%c ", *(i + (j*(numRows+1))));
    }
    printf("\n");
    i++;
    for(j = 0; j < numColumns; j++)
    {
        printf("%c ", *(i + (j*(2))));
    }
    printf("\n");
    i++;
    for(j = 0; j < numColumns; j++)
    {
        printf("%c ", *(i + (j*(numRows+1))));
    }
    printf("\n");
    
    //printf("%c\n", *i);
    //printf("%c\n", *(i+numRows+1));
    //printf("%c\n", *(i + (2*(numRows+1))));
    //printf("%c\n", *(i + (3*(numRows+1))));
    
    
    return(returned_value);
}


int main(int argc, char *argv[]) {
    char *s = "PAYPALISHIRING";
    char *r = convert(s, 3);
    printf("%s\n", r);
    return(0);
}

