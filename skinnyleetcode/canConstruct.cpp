/*
 *  Problem: https://leetcode.com/problems/ransom-note/
 *  Compile: g++ -o canConstruct canConstruct.cpp -std=c++11  -g -Wall -fsanitize=address && ./canConstruct
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

bool canConstruct(std::string ransomNote, std::string magazine) {
    if((ransomNote.size() and magazine.size() == 0) or
       (magazine.size() < ransomNote.size())) {
           return(false);
    }
    
    std::sort(ransomNote.begin(), ransomNote.end());
    std::sort(magazine.begin(), magazine.end());
    printf("%s %s %lu\n", ransomNote.c_str(), magazine.c_str(), magazine.size());
    uint32_t i = 0;
    uint32_t j = 0;
    
    while(i < ransomNote.size() and j < magazine.size()) {
        if(ransomNote[i] == magazine[j]) {
            i++;
            j++;
            
        }
        else {
            j++;
        }
    }
    printf("%d %d\n", i, j);
    /*
    for(uint32_t i = 0; i < ransomNote.size(); i++) {
        printf("1. %d %d\n", i, j);
        while((ransomNote[i] > magazine[j]) and (j < magazine.size())) j++;
        printf("2. %d %d\n", i, j);
        if(ransomNote[i] != magazine[j]) {
            printf("Exiting: %d %d\n", i, j);
            return(false);
        }
        else 
            j++;
    }
    */
    return((i==ransomNote.size()));    
}

int main(int argc, char **argv){
    std::string ransomNote = "a"; //"bbgl";
    std::string magazine = "b"; //"efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj";
    printf("%s %s\n", ransomNote.c_str(), magazine.c_str());
    bool can = canConstruct(ransomNote, magazine);
    printf(" Can ==> %d\n", can);
    return(0);
}






