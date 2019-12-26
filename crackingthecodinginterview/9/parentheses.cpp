/*
 *  Cracking the coding interview: Problem 9.6: All valid combinations of n-pair parenthesis
 *  Compile & run: g++ -o parentheses parentheses.cpp -g -Wall -std=c++11 -fsanitize=address  && ./parentheses
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>  
#include <string>

std::string insertInside(std::string str, int leftIndex) {
    std::string left = str.substr(0, leftIndex+1);
    std::string right = str.substr(leftIndex+1, str.size());
    return(left + "()" + right);
}

std::vector<std::string> parentheses(int n) {
    std::vector<std::string> all;
    if(n == 0) {
        //return(all);
        all.push_back("");
    }
    else {
        std::vector<std::string> some = parentheses(n-1);
        for(auto s: some) {
            for(uint32_t i = 0; i < s.size(); i++) {
                if(s[i] == '(') {
                    std::string ss = insertInside(s, i);
                    all.push_back(ss); /* might add duplicates */
                }
            }
            all.push_back("()" + s);
        }
    }
    
    return(all);
}

int main(int argc, char** argv) {
    
    int n = 4;
    std::vector<std::string> parent = parentheses(n);
    for(auto p: parent) {
        printf("%s ", p.c_str());
    }
    printf("\n");
    
    return(0);
}