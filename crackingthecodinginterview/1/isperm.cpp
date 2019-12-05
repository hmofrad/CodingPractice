/*
 * Cracking the coding interview: Problem 1.3: Determine if a string is a permutation of another one
 * Compile and run: g++ -o isperm isperm.cpp -g -Wall  -std=c++11 -fsanitize=address && ./isperm
 * (c) Mohammad Hasanzadeh mofrad, 2019
 * (e) m.hasanzadeh.mofrad@gmail.com
*/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>

bool is_perm(std::string str1, std::string str2) {
    if(str1.size() != str2.size()) return(false);
    
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    
    return(str1.compare(str2) == 0);
}


bool is_perm1(std::string str1, std::string str2) {
    std::vector<int> map(256);
    
    for(auto c: str1) map[c]++;
    
    for(auto c: str2) {
        if((--map[c]) < 0) return(false);
    }
    
    return(true);
}


int main(int argc, char** argv) {
    std::string str1 = "helloworld1  ";
    std::string str2 = "worldhello1  ";
    printf("%s %s\n", str1.c_str(), str2.c_str());
    
    bool perm = is_perm1(str1, str2);
    printf("? %d\n", perm);

    return(0);
}