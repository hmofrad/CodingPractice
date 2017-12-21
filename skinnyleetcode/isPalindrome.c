/*
 *  Problem: isPalindrome (https://leetcode.com/problems/palindrome-number/description/)
 *  Compile: gcc -o isPalindrome isPalindrome.c -g -Wall -Werror 
 *  Execute: ./isPalindrome
 *  (c) Mohammad HMofrad, 2017
 *  (e) mohammad.hmofrad@pitt.edu
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

int countDigits(int x) {
    int m = 10;
    int r = 0;
    do {
        x = x/m;
        r++;
    } while(x);
    return(r);
}    
 
bool isPalindrome(int x) {
    int numDigits = countDigits(x);
    if(x < 0) {
        return(false);
    }
    
    int mLeft = 10;
    int left = 1;
    int leftValue = 0;
    int leftOldValue = 0;
    
    int mright = 1;
    int i = 0;
    for(i = 0; i < numDigits - 1; i++) {
        mright *= 10;
    }
    int right = countDigits(x);
    int rightValue = numDigits;
    int rightOldValue = 0;    
    
    while(left < right) {
        rightValue = x - ((x/mLeft) * mLeft);
        rightOldValue = (rightValue - rightOldValue)/(mLeft/10);
        mLeft = mLeft * 10;
        printf("%d %d\n", right, rightOldValue);
        leftValue = x/mright;
        leftOldValue = leftValue - leftOldValue;
        if(rightOldValue != leftOldValue) {
            return(false); // not a palindrome
        }
        printf("%d %d\n", left, leftOldValue);
        leftOldValue = leftValue * 10;
        mright = mright/10;
        
        left++;
        right--;
    }
    return(true);
}

int main(int argc, char *atgv[]) {
    //int x = 2343432;
    int x = 11;
    printf("x=%d\n",  x);
    printf("%d\n",  isPalindrome(x));
    return(0);
}