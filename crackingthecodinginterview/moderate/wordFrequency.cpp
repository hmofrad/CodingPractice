/*
 *  Cracking the coding interview: Problem 17.9: Word frequency
 *  Compile & run: g++ -o wordFrequency wordFrequency.cpp -g -Wall -std=c++11 -fsanitize=address && ./wordFrequency
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map <std::string, int> words;


int wordFrequency(std::string word) {
    int freq = 0;
    if(words.find(word) != words.end()) {
        freq = words[word];
    }
    return(freq);
}

void buildDictionary(std::string book) {
    std::string word;
    for(auto c: book) {
        if(c != ' ') {
            word += c;
        }
        else {
            words[word]++;
            word.clear();
        }
    }
    
}

int main(int argc, char** argv) {
    std::string book = "Bad blue fox jumps over my fat fat head";
    buildDictionary(book);
    

    
    int n = wordFrequency("fat");
    printf("%d\n", n);
    
    for(auto w: words) {
        printf("<%s> %d\n", w.first.c_str(), w.second);
    }
    
    return(0);
}