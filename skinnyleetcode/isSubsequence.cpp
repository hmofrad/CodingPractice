/*
 *  Problem: https://leetcode.com/problems/ransom-note/
 *  Compile: g++ -o isSubsequence isSubsequence.cpp -std=c++11  -g -Wall -fsanitize=address && ./isSubsequence
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

bool isSubsequence(std::string s, std::string t) {
    
    uint32_t i = 0;
    uint32_t j = 0;
    while(i < s.size() and j < t.size()) {
        if(s[i] == t[j]) {
            i++;
            //j++;
            //continue
        }
        //else {
            j++;
        //}
    }
    return(i == s.size());
}


int main(int argc, char **argv){
    std::string s = "abc";
    std::string t = "ahbgdc";

    printf("%s %s\n", s.c_str(), t.c_str());
    bool is = isSubsequence(s, t);
    printf(" Is is ==> %d\n", is);
    return(0);
}






