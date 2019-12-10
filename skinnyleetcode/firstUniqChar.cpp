/*
 *  Problem: https://leetcode.com/problems/first-unique-character-in-a-string/
 *  Compile: g++ -o firstUniqChar firstUniqChar.cpp -std=c++11  -g -Wall -fsanitize=address && ./firstUniqChar
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>   

int firstUniqChar(std::string s) {
    std::vector<int> alpha(27);
    for(auto c: s) {
        alpha[c-'a']++;
    }
    
    //for(auto a: alpha) {
    //    printf("%d ", a);
    //}
    //printf("\n");
    
    
    for(uint32_t i = 0; i < s.size(); i++) {
        auto c = s[i];
        if(alpha[c-'a'] == 1)
            return(i);
    }
    
    return(-1);    
}

int main(int argc, char **argv){
    
    std::string s = "loveleetcodevdtc";
    int u = firstUniqChar(s);
    printf("%s: %d\n", s.c_str(), u);
    return(0);
}






