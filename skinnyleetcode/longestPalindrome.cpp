/*
 *  Problem: https://leetcode.com/problems/longest-palindrome/
 *  Compile: g++ -o longestPalindrome longestPalindrome.cpp -std=c++11  -g -Wall -fsanitize=address && ./longestPalindrome
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

int longestPalindrome(std::string s) {
    std::vector<int> alphas(26*2);
    for(auto c: s) {
        //printf("%c %d %d %d\n", c, c, c-'a', c-'A'+('z'-'a'+1));
        if((c >= 'a') and (c <= 'z')) {
            alphas[c-'a']++;
        }
        else if((c >= 'A') and (c <= 'Z')) 
            alphas[c-'A'+('z'-'a'+1)]++;
    }
    
    for(auto a: alphas) {
        printf("%d ", a);
    }
    printf("\n");
    
    int n = 0;
    
    
    for(auto a: alphas) {
        if(((a % 2) == 0) or (((a % 2) != 0) and (n%2) == 0)) {
            n+=a;
        }
        else {
            n += (a - (a%2));
        }
    }
    
    
    
    return(n);
}

int main(int argc, char **argv){
    std::string s = "AabcccAccdd"; // AdcccccdA
    int n = longestPalindrome(s);
    printf("%s %d\n", s.c_str(), n);
    return(0);
}






