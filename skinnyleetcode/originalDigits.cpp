/*
 *  Problem: https://leetcode.com/problems/reconstruct-original-digits-from-english/
 *  Compile: g++ -o originalDigits originalDigits.cpp -std=c++11 -g -Wall -fsanitize=address && ./originalDigits
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>



std::string originalDigits(std::string& s) {

std::vector<std::string> digits = {"zero", "one", "two", "three", "four",
                                   "five", "six", "seven", "eight", "nine"};    
    
    std::string t;
    
    std::unordered_map<char, std::vector<std::string>> map;
    
    for(std::string d: digits) {
        for(char c: d) {
            if(map.find(c) == map.end()) {
                map[c] = {d};    
            }
            else {
                if(std::find(map[c].begin(), map[c].end(), d) == map[c].end()) {
                    map[c].push_back(d);    
                }
            }
        }
    }
    /*
    for(auto m: map) {
        printf("%c: ", m.first);
        for(auto v: m.second) {
            printf("%s ", v.c_str());
        }
        printf("\n");
    }
    */
    
    std::vector<std::string> strs;
    for(auto it = s.begin(); it != s.end(); it++) {
        //uint32_t i = it - s.begin();
        //printf("%d %c\n", i, *it); 
        auto& vec = map[*it];
        for(auto v: vec) {
            //printf("%s ", v.c_str());
            std::vector<int> alphas(26);
            for(auto it1 = s.begin(); it1 != s.end(); it1++) {
                alphas[*it1 - 'a']++;
            }
            
            for(auto c: v) {
                alphas[c - 'a']--;
            }
            bool found = true;
            for(auto a: alphas) {
                if(a < 0) {
                    found = false;
                    break;
                }
            }
            
            if(found) {
                if(std::find(strs.begin(), strs.end(), v) == strs.end()) {
                    strs.push_back(v);
                }
            }
        }
        //printf("\n");
    }
    
    for(auto str: strs) {
        auto it = std::find(digits.begin(), digits.end(), str);
        uint32_t dist = it - digits.begin();
        //printf("%s %d\n", str.c_str(), dist);
        t += '0'+dist;
    }
    
    return(t);
}



int main(int argc, char **argv){
    std::string s = "fviefuro"; //"owoztneoer"; //zero, one, two  //"fviefuro";
    std::string t = originalDigits(s);
    printf("<%s>\n", t.c_str());
    return(0);
}






