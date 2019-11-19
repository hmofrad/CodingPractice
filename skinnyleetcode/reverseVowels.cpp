    /*
 *  Problem: https://leetcode.com/problems/reverse-vowels-of-a-string/
 *  Compile: g++ -o reverseVowels reverseVowels.cpp -std=c++11 && ./reverseVowels #-fsanitize=address 
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <string.h>
#include <unordered_set>
#include <stack>
#include <numeric>
#include <map>
#include <cmath>
#include <unordered_map>
/*
std::string reverseVowels(std::string s) {
    if(not s.size()) return(s);
    
    for(int i = 0; i < s.size()-1; i++) {
        if(((s[i] >= 65 and s[i] <= 90) or (s[i] >= 97 and s[i] <= 122)) and 
           ((s[i] == 'a' ) or (s[i] == 'e' ) or (s[i] == 'i' ) or (s[i] == 'o' ) or (s[i] == 'u' ) or
             (s[i] == 'A' ) or (s[i] == 'E' ) or (s[i] == 'I' ) or (s[i] == 'O' ) or (s[i] == 'U' ))) {
            int i1 = i;
            int i2 = 0;
            bool tf = false;
            for(int j = i+1; j < s.size(); j++) {
                if(((s[j] >= 65 and s[j] <= 90) or (s[j] >= 97 and s[j] <= 122)) and 
                ((s[j] == 'a' ) or (s[j] == 'e' ) or (s[j] == 'i' ) or (s[j] == 'o' ) or (s[j] == 'u' ) or
                 (s[j] == 'A' ) or (s[j] == 'E' ) or (s[j] == 'I' ) or (s[j] == 'O' ) or (s[j] == 'U' ))) {
                    i2 = j;
                    tf = true;
                    break;
                }
            }
            if(tf) {
                std::swap(s[i1], s[i2]);
            }
            else {
                break;
            }
        }
    }
    return s;
}
*/
std::string reverseVowels(std::string s) {
    if(not s.size()) return(s);
    
    int i = 0;
    int j = s.size()-1;
    while(i < j) {
        while((i < j) and not((s[i] == 'a' ) or (s[i] == 'e' ) or (s[i] == 'i' ) or (s[i] == 'o' ) or (s[i] == 'u' ) or
             (s[i] == 'A' ) or (s[i] == 'E' ) or (s[i] == 'I' ) or (s[i] == 'O' ) or (s[i] == 'U' ))) {
            i++;
        }
        while((j > i) and not((s[j] == 'a' ) or (s[j] == 'e' ) or (s[j] == 'i' ) or (s[j] == 'o' ) or (s[j] == 'u' ) or
            (s[j] == 'A' ) or (s[j] == 'E' ) or (s[j] == 'I' ) or (s[j] == 'O' ) or (s[j] == 'U' ))) {
            j--;
        }
        
        if(i < j){
            std::swap(s[i], s[j]);
        }
        i++;
        j--;
    }
    return(s);
}


int main(int argc, char **argv){
    std::string s = ".";
    printf("%s\n", s.c_str());
    s=reverseVowels(s);
    printf("%s\n", s.c_str());
    return(0);
}






