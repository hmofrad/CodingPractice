/*
 *  Problem: https://leetcode.com/problems/find-the-difference/
 *  Compile: g++ -o findTheDifference findTheDifference.cpp -std=c++11  -g -Wall -fsanitize=address && ./findTheDifference
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

char findTheDifference(std::string s, std::string t) {
    std::vector<int> alpha(27);
    for(auto& c: s) {
        alpha[c-'a']++;
    }
    
    for(auto& c: t) {
        if(alpha[c-'a'] == 0) {
            return(c);
        }
        alpha[c-'a']--;
    }
    return('0');
}

/*
char findTheDifference(std::string s, std::string t) {
    int diff = 0;
    uint32_t i;
    
    for(i = 0; i < s.size(); i++){
        diff += (t[i] - s[i]);
    }
    diff += t[i];

    return((char)diff);
}
*/
int main(int argc, char **argv){
    std::string s = "abcd";
    std::string t = "abcde";
    char d = findTheDifference(s, t);
    printf(">>> %c\n", d);
    return(0);
}






