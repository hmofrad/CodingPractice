/*
 *  Problem: https://leetcode.com/discuss/interview-question/366869/
 *  Lexicographically smallest string formed by removing at most one character.
 *  Example 1: Input: "abczd" Output: "abcd"
 *  Since you could only remove one char, you should remove the first char you see that is greater than the next from left to right, i.e. peak char. 
    If there is no such string, I think you should just remove the last char, i.e. if the string is sorted ascending.
 *  Compile: g++ -o smallestString smallestString.cpp -std=c++11 -g -Wall -fsanitize=address && ./smallestString    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

std::string smallestSubStr(std::string s) {
    std::string smallest;
    char peak = s[0];
    int index = 0;
    for(uint32_t i = 1; i < s.size(); i++) {
        if(s[i] > peak) {
            peak = s[i];
            index = i;
        }
    }
    printf("%c %d\n", peak, index);
    
    smallest = s.substr(0, index);
    printf("%s\n", smallest.c_str());
    smallest += s.substr(index+1, s.size()-index);
    
    return(smallest);
}

int main(int argc, char **argv){
    std::string s = "abczd";
    //std::string s = "abcdef";
    std::string smallest = smallestSubStr(s);
    printf("Smallest=%s\n", smallest.c_str());
    return(0);
}
