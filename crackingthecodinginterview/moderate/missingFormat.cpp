/*
 *  Cracking the coding interview: Problem 17.14: Fix missing format in a string
 *  Compile & run: g++ -o missingFormat missingFormat.cpp -g -Wall -std=c++11 -fsanitize=address  && ./missingFormat
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


std::unordered_map <std::string, bool> buildDictionary(std::string str) {
    std::unordered_map <std::string, bool> dictionary;
    std::string word;
    for(auto c: str) {
        if(c != ' ') {
            word += c;
        }
        else {
            //printf("%s\n", word.c_str());
            if(dictionary.find(word) == dictionary.end()) {
                dictionary[word] = true;
            }
            word.clear();
        }
    }
    if(dictionary.find(word) == dictionary.end()) {
        dictionary[word] = true;
    }
    return(dictionary);
}

std::vector<std::string> parse(std::unordered_map <std::string, bool> dic, std::string str1) {
    std::vector<std::string> tokens;
    //int i = 0;
    //int sz = raw.size();
    //char c;
    
    for(uint32_t i = 1; i < str1.size(); i++) {
        for(uint32_t j = 0; j < str1.size()-i; j++) {
            std::string  word = str1.substr(j, i);
            //printf("%s [%d %d]\n", word.c_str(), j, i);
            if(dic.find(word) != dic.end()) {
                printf(">>>> %s\n", word.c_str());
                if(std::find(tokens.begin(), tokens.end(), word) == tokens.end()) {
                    tokens.push_back(word);
                }
            }
        }
    }
    
    return(tokens);
}

int main(int argc, char** argv) {
    std::string str = "jess just looked like tim her brother";
    std::unordered_map <std::string, bool> dic = buildDictionary(str);
    dic.erase("jess");
    dic.erase("tim");
    
    //for(auto d: dic) {
    //    printf("%s %d\n", d.first.c_str(), d.second);
    //}
    
    std::string str1 = "jessjustlookedliketimherbrother";
    printf("%s\n", str1.c_str());
    std::vector<std::string> tokens = parse(dic, str1);
    for(auto t: tokens) {
        printf("%s ", t.c_str());
    }
    printf("\n");
    
    return(0);
}