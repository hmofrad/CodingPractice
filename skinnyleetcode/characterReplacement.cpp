/*
 *  Problem: https://leetcode.com/problems/longest-repeating-character-replacement/
 *  Compile: g++ -o characterReplacement characterReplacement.cpp -std=c++11 -g -Wall -fsanitize=address && ./characterReplacement
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

int characterReplacement0(std::string s, int k) {
    if(s.empty()) return(0);
    uint32_t n = 0;
    printf("%s\n", s.c_str());
    const int NUM_ALPHA = 26;
    std::vector<int> map(NUM_ALPHA, 0);
    for(auto c: s) map[c-'A']++;
    
    int max_v = 0;
    //int max_i = 0;
    for(uint32_t i = 0; i < map.size(); i++) {
        if(map[i] > max_v) {
            max_v = map[i];
            //max_i = i;
        }
    }
    
    n = max_v + k;
    return((n <= s.size()) ? n : s.size());
}

int max(int a, int b) {
    return((a > b) ? a : b);
}

int characterReplacement(std::string s, int k) {
    std::vector<int> counts(26, 0);
    int ans = 0;
    int major = 0; 
    for (int i = 0, j = 0; j < (int) s.size(); j++){
        counts[s[j] - 'A']++;
        major = (major < counts[s[j] - 'A']) ? counts[s[j] - 'A'] : major;
        if ((j - i + 1) > (k + major)) {
            counts[s[i] - 'A']--;
            i++; 
        }
        ans = ((j - i + 1) < ans) ? ans : (j - i + 1);
    }
    return(ans); 
    
    /*
    std::vector<int> counts(26, 0);
    
    int ans = 0;
    int major = 0;
    
    for(uint32_t i = 0, j = 0; j < s.size(); j++) {
        auto& c = counts[s[j] - 'A'];
        c++;
        major = (major < c) ? c : major;
        if((j - i + 1) > (k + major)) c--, i++;
        ans = ((j-i+1) < ans) ? ans :  (j-i+1);
    }
    
    return(ans);
    */
}

int main(int argc, char **argv){
    std::string s = "AABABBA";
    int k = 1;
    int n = characterReplacement(s, k);
    printf("N=%d\n", n);
    return(0);
}






