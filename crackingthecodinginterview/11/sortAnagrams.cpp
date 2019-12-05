/*
 *  Cracking the coding interview: Problem 11.2: Sort an array of strings so that all the anagrams are next to each other 
 *  Compile & run: g++ -o sortAnagrams sortAnagrams.cpp -g -Wall && ./sortAnagrams
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

void sort_str(std::string& str) {
    for(uint32_t i = 0; i < str.size(); i++) {
        for(uint32_t j = i+1; j < str.size()-1; j++) {
            if(str[i] > str[j]) {
                std::swap(str[i], str[j]);
            }
        }
    }
}

bool is_anagram(std::string str1, std::string str2) {
    if(str1.size() != str2.size()) return(false);
    
    //sort_str(str1);
    //sort_str(str2);
    //return(strcmp(str1.c_str(), str2.c_str()) == 0);
    
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    return(str1.compare(str2) == 0);
    
}

std::vector<std::string> sort_anagram(std::vector<std::string> anagrams) {
    
    std::vector<std::string> sorted_anagrams;
    
    for(uint32_t i = 0; i < anagrams.size(); i++) {
        for(uint32_t j = i+1; j < anagrams.size(); j++) {
            if(is_anagram(anagrams[i], anagrams[j])) {
                if(i+1 != j) {
                    std::swap(anagrams[i+1], anagrams[j]);
                }
                break;
            }
        }
    }
        
    return(anagrams);
}


int main(int argc, char** argv) {
    std::vector<std::string> str = {"iran", "rain", "listen", "china", "alpha", "rani", "angola", "silent", "analog", "chain", "bbf"};
    
    for(auto& s: str) { printf("%s ", s.c_str());} printf("\n");
    
    std::vector<std::string> str0 = sort_anagram(str);
    
    for(auto& s: str0) {printf("%s ", s.c_str());} printf("\n");
    
    return(0);
}