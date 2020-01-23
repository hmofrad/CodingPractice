/*
 *  Problem: https://leetcode.com/problems/number-of-segments-in-a-string/
 *  Compile: g++ -o countSegments countSegments.cpp -std=c++11 -g -Wall -fsanitize=address && ./countSegments
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

int countSegments(std::string s) {
    int n = 0;
    if(s.empty()) {
        return(0);
    }
    
    char prev = *s.begin();
    bool charExist = (s.front() != ' ') ? true : false;
    
    for(auto it=s.begin()+1; it != s.end(); it++) {
        auto c = *it;
        if((prev != ' ') and (c == ' ')) {
            n++;
        }
        prev = c;
        if(!charExist and (prev != ' ')) {
            charExist = true;
        }
    }
    bool endingSpace = (s.back() == ' ') ? true : false;
    if(charExist and !endingSpace) {
        n++;
    }
    return(n);    
}

int main(int argc, char **argv){
    std::string s = "  A,   BBBB ";
    int numSegs = countSegments(s);
    printf("%s: NumSegs=%d\n", s.c_str(), numSegs);
    return(0);
}






