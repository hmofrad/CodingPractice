/*  
 *  Problem: letterCombinations (https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)
 *  Compile: gcc -o letterCombinations letterCombinations.c -g -Wall -Werror 
 *  Execute: ./letterCombinations
 *  (c) Mohammad HMofrad, 2018
 *  (e) mohammad.hmofrad@pitt.edu
 */

 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *digitMapper(char digit) {
    int size = 0;
    char *letters = NULL;
    switch (digit) {
        case '0':
            
            // Space
            size = 2;
            letters = malloc(sizeof(char) * size);
            memset(letters, '\0', sizeof(char) * size);
            letters[0] = ' ';
            
            /*
            // Space = '\0'
            size = 1;
            letters = malloc(sizeof(char) * size);
            letters[0] = '\0';
            */
            break;
        case '1':
            // Voicemail
            size = 1;
            letters = malloc(sizeof(char) * size);
            letters[0] = '\0';
            break;    
        case '2':
            size = 4;
            letters = malloc(sizeof(char) * size);
            memset(letters, '\0', sizeof(char) * size);
            strncpy(letters, "abc", sizeof(char) * size - 1);
            break;
        case '3':
            size = 4;
            letters = malloc(sizeof(char) * size);
            memset(letters, '\0', sizeof(char) * size);
            strncpy(letters, "def", sizeof(char) * size - 1);
            break;        
        case '4':
            size = 4;
            letters = malloc(sizeof(char) * size);
            memset(letters, '\0', sizeof(char) * size);
            strncpy(letters, "ghi", size - 1);
            break;        
        case '5':
            size = 4;
            letters = malloc(sizeof(char) * size);
            memset(letters, '\0', sizeof(char) * size);
            strncpy(letters, "jkl", size - 1);
            break;        
        case '6':
            size = 4;
            letters = malloc(sizeof(char) * size);
            memset(letters, '\0', sizeof(char) * size);
            strncpy(letters, "mno", size - 1);
            break;        
        case '7':
            size = 5;
            letters = malloc(sizeof(char) * size);
            memset(letters, '\0', sizeof(char) * size);
            strncpy(letters, "pqrs", size - 1);
            break;        
        case '8':
            size = 4;
            letters = malloc(sizeof(char) * size);
            memset(letters, '\0', sizeof(char) * size);
            strncpy(letters, "tuv", size - 1);
            break;      
        case '9':
            size = 5;
            letters = malloc(sizeof(char) * size);
            memset(letters, '\0', sizeof(char) * size);
            strncpy(letters, "wxyz", size - 1);
            break;      
        default:
            size = 1;
            letters = malloc(sizeof(char) * size);
            letters[0] = '\0';
            printf("Option not found <%c>\n", digit);
            break;      
    }
    return(letters);
}            


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    if(!strlen(digits)){
        returnSize = 0;
        return(NULL);
    }
    int size = 1;
    int s = 0;
    char **letters = malloc(sizeof(char*) * size);
    char *digit = digits;
    char *tempLetters = NULL;
    int totalNumCombinations = 1;
    int totalNumLetters = 0;
   // printf("%zu\n", strlen(digits));
    while(*digit) {
        tempLetters = digitMapper(*digit);
        //printf(">>%s\n", *tempLetters);
        if(*tempLetters) {
            letters[s] = tempLetters;
            totalNumCombinations *= strlen(letters[s]);
            totalNumLetters += strlen(letters[s]);
            s++;
            if(s == size) {
                size *= 2;
                letters = realloc(letters, sizeof(char *) * size);
            }
            
        }
        //tempLetters = digitMapper(*digit);
        //printf("%c: ", *digit);
        while(*tempLetters) {
            //printf("[%c]", *tempLetters);
            tempLetters++;
        }
       // printf("\n");
        *digit++;
        //break;
    }
   // printf("\n");
    
    //int numLetters = s;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int leftNumCombinations = totalNumCombinations;
    int lengthOfCombinations = s;
    
    int lastLeftNumCombinations = 0;
    int times = 1;
    int lettersLength = 0;
    int NextLettersLength = 0;
    //int numLetters = 
   // printf("%d %d\n", totalNumCombinations, s);
    
    char **returnLetters = malloc(sizeof(char*) * totalNumCombinations);
    memset(returnLetters, '\0', sizeof(char*) * totalNumCombinations);
    for(i = 0; i < totalNumCombinations; i++) {
        returnLetters[i] = malloc(sizeof(char) * (lengthOfCombinations + 1));
        memset(returnLetters[i], '\0', sizeof(char) * (lengthOfCombinations + 1));
    }
    /*
    int *lenghtArray = malloc(sizeof(int) * s);
    for(i = 0; i < s; i++) { 
        lenghtArray = strlen(letters[i]);
        printf("%d\n", lenghtArray);
    }
    */
    times = 1;
    k = 0;
    for(i = 0; i < s; i++) { 
        times = 1;
        for(j = i + 1; j < s; j++) { 
            times *= strlen(letters[j]);
        }
      //  printf("%d %d \n", i, times);
        k = 0;
        for(j = 0; j < totalNumCombinations; j++) { 
            if((j > 0) && !(j%times)) {
                k++;
            }
            if(k >= strlen(letters[i])) {
                k = 0;
               // printf(">>>>>>..%d\n", k);
            }
            returnLetters[j][i] = letters[i][k];
            //printf("    %d %d %d %c %c\n", j, times, k, letters[i][k], returnLetters[j][i]);
        }
        //printf("\n");
       // if(i == 1)
        //break;
    }
    
    //for(j = 0; j < totalNumCombinations; j++) { 
    //    printf("%d %s\n", j, returnLetters[j]);
    //}
    
    *returnSize = totalNumCombinations;
    return(returnLetters);
}

int main(int argc, char *argv[]) {    
    //char digits[] = "935";
    char digits[] = "";
    int returnSize = 0;
    printf("INPUT: %s\n", digits);
    char **combinations = letterCombinations(digits, &returnSize);
    printf("Size: %d\n", returnSize);
    int j = 0;
    for(j = 0; j < returnSize; j++) { 
        printf("%d %s\n", j, combinations[j]);
    }
    
    return(0);
}