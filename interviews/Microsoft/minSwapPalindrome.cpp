/*
 *  Problem: https://leetcode.com/discuss/interview-question/351783/
 *  Given a string, what is the minimum number of adjacent swaps required to convert a string into a palindrome. If not possible, return -1.
 *  Example 1: Input: "mamad"  Output: 3 
 *  Example 2: Input: "asflkj" Output: -1
 *  Example 3: Input: "aabb"   Output: 2
 *  Example 4: Input: "ntiin"  Output: 1 Explanation: swap 't' with 'i' => "nitin" 
 *  Compile: g++ -o minSwapPalindrome minSwapPalindrome.cpp -std=c++11 -g -Wall -fsanitize=address && ./minSwapPalindrome
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(std::string s) {
    bool palindrome = true;
    for(uint32_t i = 0; i < s.size()/2; i++) {
        if(s[i] != s[(s.size()-1)-i]) {
            palindrome = false;
        }
    }
    return(palindrome);
}

int minSwaps(std::string s) {
    int numMinSwaps = 0;
    printf("%s ? %d\n", s.c_str(), isPalindrome(s));
    
    //bool canBePalindrome = false;
    
    std::vector<int> alphas(26);
    for(auto c: s) {
        alphas[c-'a']++;
    }
    
    int countOnes = 0;
    for(auto a: alphas) {
        if(a == 1) {
            countOnes++;
        }
    }
    if(countOnes > 1) {
        numMinSwaps = -1;
    }
    else {
        //isPalindrome(s)
        printf("%s\n", s.c_str());
        
        //if(not(isPalindrome(s))) {
            for(uint32_t i = 0; i < s.size()/2; i++) {
                
                uint32_t j = (s.size()-1)-i;
                
                printf("s=%s i=%d j=%d  s[i]=%c s[j]=%c\n", s.c_str(), i, j, s[i], s[j]);
                if(alphas[s[i]-'a'] == 1) {
                    uint32_t k = i;
                    while(k != s.size()/2) {
                        std::swap(s[k], s[k+1]);
                        k++;
                        numMinSwaps++;
                    }
                }
                else {
                    uint32_t k = i+1;
                    while(s[i] != s[k]) {
                        k++;
                    }
                    while(s[i] != s[j]) {
                        std::swap(s[k], s[k+1]);
                        k++;
                        numMinSwaps++;
                    }
                }
            }
        //}
        
        
    }
    printf("%s ? %d\n", s.c_str(), isPalindrome(s));
    
    return(numMinSwaps);
}


int main(int argc, char **argv){
    //std::string s = "mdmaa";
    //std::string s = "asflkj";
    //std::string s = "aabb";
    std::string s = "ntiin";
    int min = minSwaps(s);
    printf("Min swaps=%d\n", min);
    
    return(0);
}
