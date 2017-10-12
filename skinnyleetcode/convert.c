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
    //P   A   H   N
    //A P L S I I G
    //Y   I   R

    char *returned_value = malloc(sizeof(char) * strlen(s));
    memset(returned_value, 0, sizeof(char) * strlen(s));

    int numColumns = (1 + ((strlen(s) - 1)/(numRows + 1))) + (strlen(s) / (numRows + 1)); // #Zig + #Zag

    char *i = s;
    int j = 0;

    i = s;
    int k = 0;
    int l = 0;

    for(k = 0; k < numRows; k++)
    {
        for(j = 0; j < numColumns; j++)
        {
            if(k%numRows != 1)
            {
                if(j*(numRows+1) < strlen(s))
                {
                    returned_value[l] = *(i + (j*(numRows+1)));
                    l++;
                    //printf("%c  ", *(i + (j*(numRows+1))));
                }
            }
            else
            {
                if(j * 2 < strlen(s))
                {
                    returned_value[l] = *(i + (j * 2));
                    l++;
                    //printf("%c ", *(i + (j * 2)));
                }
            }
        }
        i++;
    } 
    return(returned_value);
}


int main(int argc, char *argv[]) {
    char *s = "PAYPALISHIRING";
    char *r = convert(s, 3);
    printf("%s\n", r);
    free(r);
    return(0);
}

