/*
 *  Cracking the coding interview: Problem 18.8: Given a string s, and an array of smaller strings T, search s for each small string in T 
 *  Compile & run: g++ -o  searchForSuffix searchForSuffix.cpp -g -Wall -std=c++11 -fsanitize=address  && ./searchForSuffix
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string>  genSuffixes(const std::string s) {
    std::vector<std::string> suffixes;
    for(uint32_t i = 0; i < s.size(); i++) {
        suffixes.push_back(s.substr(i, s.size()));
    }
    suffixes.push_back("");
    
    std::vector<std::vector<char>> leaves;
    
    return(suffixes);
}

bool search(std::vector<std::string> prefixes, const std::string t) {
    bool ret = false;
    for(auto p: prefixes) {
        if(p == t) {
            ret = true;
            break;
        }
    }
    return(ret);
}

int main(int argc, char** argv) {
    std::string s = "banana";
    std::vector<std::string> suffixes = genSuffixes(s);
    for(auto s: suffixes) {
        printf("\"%s\"\n", s.c_str());
    }
    
    std::string t = "ana";
    
    bool tf = search(suffixes, t);
    printf("TF=%d\n", tf);
    
    return(0);
}