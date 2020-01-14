/*
 *  Cracking the coding interview: Problem 18.7: Find the longest word made of other words
 *  Compile & run: g++ -o  largestCombinedWord largestCombinedWord.cpp -g -Wall -std=c++11 -fsanitize=address  && ./largestCombinedWord
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<std::string>& strs) {
    for(auto s: strs) {
        printf("%s ", s.c_str());
    }
    printf("\n");
}

bool isSubStr(std::string str1, std::string str2) {
    bool isit = false;
    for(uint32_t i = 0; i < str1.size(); i++) {
        if(str1[i] == str2[0]) {
            uint32_t j = i;
            bool matched = true;
            for(uint32_t k = 0; k < str2.size(); k++) {
                if(str1[j] != str2[k]) {
                    matched = false;
                    break;
                }
                j++;
            }
            if(matched) {
                isit = true;
                break;
            }
        }                    
    }
    return(isit);
}
/*
std::string concat(std::vector<std::string>& strs) {
    
    
}
*/

std::string longest(std::vector<std::string>& strs) {
    std::string str;
    
    print(strs);

    
    for(uint32_t i = 0; i < strs.size()-1; i++) {
        for(uint32_t j = i; j < strs.size(); j++) {
            if(strs[i].size() < strs[j].size()) {
                std::swap(strs[i], strs[j]);
            }
        }
    }
    
    print(strs);
    
    
    for(uint32_t i = 0; i < strs.size()-1; i++) {
        std::string str1 = strs[i];
        std::vector<std::string> subs;
        for(uint32_t j = i+1; j < strs.size(); j++) {   
            bool issub = false;
            std::string str2 = strs[j];
            if(str1.size() > str2.size()) {
                issub = isSubStr(str1, str2);
            }
            else {
                issub = isSubStr(str2, str1);
            }
            
            if(issub) {
                if(str1.size() > str2.size()) {
                    subs.push_back(str2);
                }
                else {
                    subs.push_back(str1);
                }
            }
            //printf("%s %s: %d\n", str1.c_str(), str2.c_str(), issub);
        }
        
        for(auto s: subs) {
            printf("%s ", s.c_str());
        }
        printf("\n");
        
    }
    
    
    
    return(str);
}

int main(int argc, char** argv) {
    std::vector<std::string> strs = {"cat", "banana", "dog", "nana", "walk", "walker", "dogwalker"};
    std::string str = longest(strs);
    
    printf("STR=%s\n", str.c_str());
    
    //printf("Is=%d\n", isSubStr("ana", "bananana"));
    
    return(0);
}