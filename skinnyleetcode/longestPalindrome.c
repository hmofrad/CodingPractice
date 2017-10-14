/*
 *  Problem: longestPalindrome (https://leetcode.com/problems/longest-palindromic-substring/description/)
 *  Compile: gcc -o longestPalindrome longestPalindrome.c -g -Wall -Werror 
 *  Execute: ./longestPalindrome
 *  (c) Mohammad HMofrad, 2017
 *  (e) mohammad.hmofrad@pitt.edu
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH (1000)


int isPalindrome(char *s, int length) {
    //int length = strlen(s);
    char *left = s;
    char *right = s + length - 1;
    printf("%s %d\n", s, length);
    //printf("%p %p %c %c %d %d\n", left, right, *left, *right, left < right, *left != *right);
    char returned_value = 0;
    while(left < right)
    {
        if(*left != *right)
        {
            returned_value = 1;
            break;
        }
        left++;
        right--;
    }
    return(returned_value);
}

char * longestPalindrome(char *s) {
    int length = strlen(s);
    char *returned_value = NULL;
    
    char *left = s;
    char *right = s + length - 1;
    char *removed_left_l;
    char *removed_left_r;
    int left_length;
    
    char *removed_right_l;
    char *removed_right_r;
    int right_length;

    while (left < right){

        removed_left_l = left + 1;
        removed_left_r = right;
        left_length = length - 1;
        
        removed_right_l = left;
        removed_right_r = right - 1;
        right_length = length - 1;

        if(!isPalindrome(left, length))
        {
            returned_value = malloc(sizeof(char) * (length + 1));
            memset(returned_value, 0, sizeof(char) * (right_length + 1));
            memcpy(returned_value, left, length);
            return(returned_value);    
        }
        
        while(removed_left_l < removed_left_r)
        {
            //printf("%p %d\n", removed_left_l, isPalindrome(removed_left_l, left_length));
            if(!isPalindrome(removed_left_l, left_length))
            {
                returned_value = malloc(sizeof(char) * (left_length + 1));
                memset(returned_value, 0, sizeof(char) * (right_length + 1));
                memcpy(returned_value, removed_left_l, left_length);   
                return(returned_value);
            }
            removed_left_l++;
            left_length--;
        }
        left = left++;
        length--;
        
        while(removed_right_l < removed_right_r)
        {
            //printf("--%p %d\n", removed_right_l, isPalindrome(removed_right_l, right_length));
            if(!isPalindrome(removed_right_l, right_length))
            {
                returned_value = malloc(sizeof(char) * (right_length + 1));
                memset(returned_value, 0, sizeof(char) * (right_length + 1));
                memcpy(returned_value, removed_right_l, right_length);
                return(returned_value);
            }
            removed_right_r--;
            right_length--;
        }
        right = right--;
        length--;
    }
    return(returned_value);
}


int main(int argc, char *argv[]) {
    char *s="cbbd";
    int l = strlen(s);
    printf("%s\n", s);
    char *r = longestPalindrome(s);
    printf("^^%s^^^\n", r);
    return(0);
}
 
 