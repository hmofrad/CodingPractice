/*
  * Cracking the coding interview: Problem 1.8: Is a string, a rotation of another string
  * Compile and run:  g++ -o isRotation isRotation.cpp -g -Wall -std=c++11 -fsanitize=address && ./isRotation
  * (c) Mohammad Hasanzadeh mofrad, 2020
  * (e) m.hasanzadeh.mofrad@gmail.com
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
/*Assume s1 is always larger than s2 */
bool isSubstring(std::string s1, std::string s2) {
    uint32_t j = 0;
    for(uint32_t i = 0; i < s1.size(); i++) {
        if(s1[i] == s2[j]) {
            j++;
            if(j == s2.size()) {
                break;
            }
        }
        else {
            j = 0;
        }
    }
    
    return(j == s2.size());
}

bool isRotation(std::string s1, std::string s2) {
    
    
    return(isSubstring(s1+s1, s2));
}



int main(int argc, char* argv[]) {
    std::string s1 = "waterbottle";
    std::string s2 = "erbottlewat";
    bool tf = isRotation(s1, s2);
    printf("%d\n", tf);
    return(0);
}