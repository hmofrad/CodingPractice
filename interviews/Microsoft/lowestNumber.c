/*
 *  Problem: https://www.geeksforgeeks.org/build-lowest-number-by-removing-n-digits-from-a-given-number/
 *  Build Lowest Number by Removing n digits from a given number
 *  Input: str = "4325043", n = 3
 *  Output: "2043"
 *  Input: str = "765028321", n = 5
 *  Output: "0221"
 *  Input: str = "121198", n = 2
 *  Output: "1118" 
 *  Compile: gcc -o lowestNumber lowestNumber.c -g -Wall -fsanitize=address && ./lowestNumber   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void remove1(char str[], int m, int left, int right, char str1[], int idx) {
    int len = right - left + 1;
    printf("m=%d l=%d r=%d idx=%d len=%d\n", m, left, right, idx, len);
    
    
    if(m <= 0) {
        for(int i = left; i <= right; i++) {
            str1[idx] = str[i];
            idx++;
        }
        return;
    }
    
    if(len <= m) return;
    
    int minIdx = left;
    for(int i = left+1; i <= left+m; i++) {
        if(str[i] < str[minIdx]) {
            minIdx = i;
        }
    }
    str1[idx] = str[minIdx];
    printf("minidx=%d str[minidx]=%c len=%d m-minidx=%d nextleft=%d str=%s\n", minIdx, str[minIdx], len, m - minIdx, minIdx+1, str1);
    
    remove1(str, m - minIdx+left, minIdx+1, right, str1, idx+1);
}

int main(int argc, char** argv){
    char str[] = "765028321";
    int len = strlen(str);
    char str1[len+1];
    memset(str1, '\0', (sizeof(char) * (len+1)));
    
    
    int m = 5;
    remove1(str, m, 0, len-1, str1, 0);

        printf("%s,%d --> %s\n", str, m, str1);

    
    return(0);
}
