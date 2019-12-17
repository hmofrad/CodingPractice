/*
 *  Problem: https://leetcode.com/problems/fizz-buzz/
 *  Compile: g++ -o fizzBuzz fizzBuzz.cpp -std=c++11  -g -Wall -fsanitize=address && ./fizzBuzz
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> str;
    for(int i = 0; i <= n; i++) {
        if(((i%3) == 0) and ((i%5) == 0)) {
            str.push_back("FizzBuzz");
        }
        else if((i%3) == 0) {
            str.push_back("Fizz");
        }
        else if((i%5) == 0) {
            str.push_back("Buzz");
        }
        else {
            str.push_back(std::to_string(i));
        }
    }
    return(str);
}

int main(int argc, char **argv){
    int n = 15;
    std::vector<std::string> str = fizzBuzz(n);
    for(auto s: str) {
        printf("%s\n", s.c_str());
    }
    printf("\n");
    return(0);
}






