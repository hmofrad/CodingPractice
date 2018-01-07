/*  
 *  Problem: longestCommonPrefix (https://leetcode.com/problems/longest-common-prefix/description/)
 *  Compile: gcc -o longestCommonPrefix longestCommonPrefix.c -g -Wall -Werror 
 *  Execute: ./longestCommonPrefix
 *  (c) Mohammad HMofrad, 2018
 *  (e) mohammad.hmofrad@pitt.edu
 */

 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    
    
    if(!strsSize)
        return("");
    int i = 0;
    int j = 0;
    int k[strsSize];
    memset(k, 0, sizeof(k));
    
    int minLength = strlen(strs[0]);
    int length = 0;
    for(j = 1; j < strsSize; j++) {
        length = strlen(strs[j]);
        if(minLength > length) {
            minLength = length;
        }
    }
    if(!minLength)
        return("");        
    
    
    char *longestPrefix = malloc(sizeof(char) * minLength);
    memset(longestPrefix, 0, sizeof(char) * minLength);
    char tempCharacter = 0;
    int tempIndex = 0;
    char flag = 0;
    for(i = 0; i < minLength; i++) {
        tempCharacter = strs[0][i];
        //printf("%c\n", tempCharacter);
        for(j = 1; j < strsSize; j++) {
            if(tempCharacter != strs[j][i]) {
                flag = 1;
                break;
            }
            //printf("%s %c\n", strs[j],strs[j][i]);    
        }
        if(!flag) {
            longestPrefix[tempIndex] = tempCharacter;
            tempIndex++;
        } else {
            break;
        }
        //printf("\n");
        //tempCharachter = strs[i];
        //if(tempCharachter != strs
        //j = 
        //printf("%s %d %d\n", strs[i], k[i], strlen(strs[i]));
    }
    
    printf(">>>%s %zu\n", longestPrefix, minLength);
    
    return(longestPrefix);
}

int main(int argc, char *argv[]) {
    //char *strs[] = {"onee", "one", "oneee", ""};
    char *strs[] = {"a", "ac"};
    int strsSize = sizeof(strs)/sizeof(strs[0]);
    //printf("%s %s %s %s %d\n", strs[0], strs[1], strs[2], strs[3], strsSize);
    //printf("%s\n", strs[0]);
    
    char *longestPrefix = longestCommonPrefix(strs, strsSize);
    printf("%s %d\n", longestPrefix, strlen(longestPrefix));
    return(0);
}

