/*
 *  Cracking the coding interview: Problem 9.5: All permutations of a string
 *  Compile & run: g++ -o permutations permutations.cpp -g -Wall -std=c++11 -fsanitize=address  && ./permutations
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>  

std::string insert_char_at(std::string str, int index, char c_char) {
    std::string first = str.substr(0, index);
    std::string second = str.substr(index, str.size()-index);
    //printf("%s %c %s", first.c_str(), c_char, second.c_str());
    return(first + c_char + second);
    //return("");
}

std::vector<std::string> permutations(std::string str) {
        printf("1.%s\n", str.c_str());
    std::vector<std::string> perms;
    //if(str.empty()) {
      //  return perms;
   // }
    
    
    if(str.empty()) {
        perms.push_back("");
        return(perms);
    }    
    
    char first = str[0];
    str.erase(str.begin());
    
    std::vector<std::string> words = permutations(str);
    printf("[%s: ", str.c_str());
    for(auto word: words) {
        printf("(%s) ", word.c_str());
        for(uint32_t i = 0; i <= word.size(); i++) {
            std::string s = insert_char_at(word, i, first);
            printf("%s ", s.c_str());
            perms.push_back(s);
        }
    }
    printf("]\n");
    
    
    
    return(perms);
}

/* 
std::vector<std::string> permutations(std::string str) {
    printf("1.%s\n", str.c_str());
    std::vector<std::string> perms;
    if(str.size() == 0) {
        perms.push_back("");
        return(perms);
    }
    
    printf("2.%s\n", str.c_str());
    char first = str[0];
    str.erase(str.begin());
    //std::vector<char> str1;
    //str1.push_back('a');
    
    std::vector<std::string> words = permutations(str);
    printf("3.%s %lu\n", str.c_str(), words.size());
    for(auto word: words) {
        printf("<%s>\n", word.c_str());
        for(uint32_t j = 0; j < word.size(); j++) {
            std::string s;
            s += word.substr(0,j);
            //s.push_back(t1);
            s += first;
            s += word.substr(j+1, word.size()-j-1);
            //s.push_back(t);
            //for(uint32_t i = j+1; i < word.size(); i++) {    
              //  s.push_back(word[i]);
            //}
            printf(">>%d %s %s\n", j, word.c_str(), s.c_str());
            perms.push_back(s);
        }
    }

    return(perms);
}
*/

int main(int argc, char** argv) {
    std::string str = "abc";
    std::vector<std::string> perms = permutations(str);
    //for(uint32_t i = 0; i <= str.size(); i++) {
      //  std::string s = insert_char_at(str, i, 'd');
        //printf("%s ", s.c_str());
    //}
    
    for(auto perm: perms) {
        printf("%s ", perm.c_str());
    }
    printf("\n");
    
    //printf("%s\n", str.c_str());
    

    //printf("%s\n", str.c_str());
    
    return(0);
}