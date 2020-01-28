/*
 *  Problem: https://leetcode.com/discuss/interview-question/398039/
 *  Compile: g++ -o withoutThreeConsecutive withoutThreeConsecutive.cpp -std=c++11 -g -Wall -fsanitize=address && ./withoutThreeConsecutive
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

/*
std::string wo3ConsecutiveLetters(std::string s) {
    std::string t;
    t += s[0];
    int count = 1;
    for(uint32_t i = 1; i < s.size(); i++) {
        if(s[i] == s[i-1]) {
            count++;
        }
        else {
            count = 1;
        }
        if(count <= 3) {
            t += s[i];
        }
    }
    return(t);
}
*/

std::string wo3ConsecutiveLetters(std::string s) {
    std::string t;
    t += s[0];
    int count = 1;
    for(uint32_t i = 1; i < s.size(); i++) {
        if((s[i-1] == s[i]) and (++count < 3)) {

            t += s[i];
        }
        else if(s[i-1] != s[i]){
            t += s[i];
            count = 1;
        }
    }
    return(t);
}



int main(int argc, char **argv){
    std::string s = "uuxaaaaxuu";
    std::string str = wo3ConsecutiveLetters(s);
    printf("Out=%s\n", str.c_str());
    return(0);
}
