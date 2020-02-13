/*
 *  Problem: https://www.geeksforgeeks.org/longest-even-length-substring-sum-first-second-half/
 *  Longest Even Length Substring such that Sum of First and Second Half is same
 *  Given a string ‘str’ of digits, find the length of the longest substring of ‘str’, 
 *  such that the length of the substring is 2k digits and sum of left k digits is equal to the sum of right k digits.
 *  Input: str = "123123"
 *  Output: 6
 *  The complete string is of even length and sum of first and second half digits is same
 *  Compile: gcc -o longestEvenSubstr longestEvenSubstr.c -g -Wall -fsanitize=address && ./longestEvenSubstr   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return((a > b) ? a : b);
}

int find1(char str[], int left, int right) {
    //printf("  %d %d\n", left, right);
    int ret = 0;
    if(((right - left + 1) % 2) == 0) {
        int sl = 0;
        int sr = 0;
        for(int i = left, j = right; i < left + (right - left + 1)/2; i++, j--) {
            int cl = str[i] - '0';
            int cr = str[j] - '0';
            sl += cl;
            sr += cr;
            //printf("%d %d %d %d %d\n", i, c1, j, c2, '0');
            //exit(0);
        }
        if(sl == sr) {
            ret = right - left + 1;
        }
        else {
            ret = max(find1(str, left+1, right), find1(str, left, right-1));
        }
    }
    else if(left < right) {
            ret = max(find1(str, left+1, right), find1(str, left, right-1));
    }
    
    return(ret);
}

int find(char str[]) {
    //int longest = 0;
    int len = strlen(str);
    printf("%s %d\n", str, len);
    
    //for(int i = 0; i < len; i++) {
        int l = find1(str, 0, len-1);
        //printf("%d %d\n", l);
        //exit(0);
    //}
    
    
    return(l);
}

int main(int argc, char** argv){
    char str[] = "1532023";
    int w = find(str);
    printf("%d\n", w);
    return(0);
}
