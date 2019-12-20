/*
  * Cracking the coding interview: Problem 1.5: Compress a string
  * Compile and run: g++ -o compress compress.c -g -Wall  -std=c++11 -fsanitize=address && ./compress
  * (c) Mohammad Hasanzadeh mofrad, 2019
  * (e) m.hasanzadeh.mofrad@gmail.com
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

std::string compress(std::string str) {
    if(str.empty()) 
        return(str);
    
    
    std::string str1;
    str1 = str[0];
    int n = 1;
    for(uint32_t i = 1; i < str.size(); i++) {
        if(str[i] == str1.back()) {
            n++;
        }
        else {
            str1 += std::to_string(n);
            str1 += str[i];
            n = 1;
        }
    }
    str1 += std::to_string(n);

    if(str1.size() > str.size())
        str1 = str;
    
    return(str1);
}

int main(int argc, char* argv[]) {
    std::string str = "aa";// "aabccccccddddee";
    printf("[%s]\n", str.c_str());
    std::string compressed = compress(str);
    printf("[%s]\n", compressed.c_str());
    return(0);
}