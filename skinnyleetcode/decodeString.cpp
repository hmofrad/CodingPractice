/*
 *  Problem: https://leetcode.com/problems/decode-string/
 *  Compile: g++ -o decodeString decodeString.cpp -std=c++11 -g -Wall -fsanitize=address && ./decodeString
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <deque>
#include <tuple>


 std::string decodeString(std::string s) {
    std::string decoded;
    std::deque<std::pair<int, std::string>> stack;
    
    for(auto c: s) {
        if(((c - '0') >= 0) and ((c - '9') <= 9)) {
            int digit = (c-'0');
            if(!stack.empty()) {
                if(((stack.back().first) >= 0 and (stack.back().first <= 9)) and stack.back().second.empty()) {
                    stack.back().first = stack.back().first*10 + digit;
                }
                else {
                    stack.push_back({digit,""});
                }
            }
            else {
                stack.push_back({digit,""});
            }
            //printf("%d\n", stack.back().first);
        }
        else {
            //if(not((c == '[') or (c == ']'))) {
                stack.back().second.push_back(c);
            //}
            //else if(c == ']') {
                
            //}
      //      printf("%c\n", c);
        }
    }
    //printf("=====\n");
    //;
    std::string next_str;
    for(auto rit = stack.rbegin(); rit != stack.rend();  rit++) {
        printf("%d %s\n", rit->first, rit->second.c_str());
        std::string str;
        
        //printf("%s\n", str.c_str());
        if(decoded.empty()) {
            for(int i = 0; i < rit->first; i++) {
                str += rit->second;
            }
            decoded = str;
        }
        else {
            str += rit->second;
            str += decoded;
           for(int i = 1; i < rit->first; i++) {
                str += str;
            }
            decoded = str;
        }
        
    }
    //printf("======\n");
    
    return(decoded);    
}

int main(int argc, char **argv){
    std::string s = "3[a4[cbb]]"; //"3[a]2[bc]"
    std::string t = decodeString(s);
    printf("%s --> %s\n", s.c_str(), t.c_str());
    return(0);
}






