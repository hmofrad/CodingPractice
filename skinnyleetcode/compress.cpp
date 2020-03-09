/*
 *  Problem: https://leetcode.com/problems/string-compression/
 *  Compile: g++ -o compress compress.cpp -std=c++11 -g -Wall -fsanitize=address && ./compress
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int compress(std::vector<char>& chars) {
    uint32_t i = 0;
    uint32_t j = 1;
    uint32_t k = 0;
    int l = 0;
    while(i < chars.size()) {
        
        if(i+1 < chars.size()) {
            if(chars[i] == chars[i+1]) {
                j++;
            }
            else {
                chars[k] = chars[i];
                k++;
                if(j>1) {
                    int r = j%10;
                    while(j/10) {
                        r =  j%10;
                        chars[k] = '0'+j/10;
                        k++;
                        j = r;
                    }
                    chars[k] = '0'+r;
                    k++;
                }
                j=1;
                l++;
            }
        }
        else {
            printf("%d %d\n", j/10, j%10);
            chars[k] = chars[i];
            k++;
            if(j>1) {
                int r = j%10;
                while(j/10) {
                    r =  j%10;
                    chars[k] = '0'+j/10;
                    k++;
                    j = r;
                }
                chars[k] = '0'+r;
                k++;
            }
            j = 0;
            l++;
        }
        i++;
    }
    
    for(uint32_t m = k; m < chars.size(); m++) {
        chars[m] = '\0';
    }

    return(k);    
}
    
int main(int argc, char **argv){
std::vector<char>  chars ={'a','a','b','b','c','c','c'}//; {'a','b','b','b','b','b','b','b','b','b','b','b'};
;//{'a'};//{'a','a','b','b','c','c','c'};
    int r = compress(chars);
    for(auto c: chars) {printf("%c ", c);} printf("\n");
    printf("R=%d\n", r);
    return(0);
}






