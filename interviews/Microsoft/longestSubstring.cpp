/*
 *  Problem: https://leetcode.com/discuss/interview-question/398031/
 *  Given a string s containing only a and b, find longest substring of s such that s does not contain more than two contiguous occurrences of a and b.
 *  Example 1: Input: "aabbaaaaabb"    Output: "aabbaa"
 *  Example 2: Input: "aabbaabbaabbaa" Output: "aabbaabbaabbaa"
 *  Compile: g++ -o longestSubstring longestSubstring.cpp -std=c++11 -g -Wall -fsanitize=address && ./longestSubstring
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

std::string longestSubStr(std::string s) {
    std::string longest;
    std::vector<int> counts(2);
    //int countsA = 0;
    //int countsB = 0;
    char prev = s[0];
    char curr; 
    counts[s[0]-'a']++;
    int i1 = 0;
    int i2 = 0;
    for(uint32_t i = 1; i < s.size(); i++) {
        printf("s[%d]=%c, %d\n", i, s[i], counts[s[i]-'a']);
        curr = s[i];
        counts[curr-'a']++;
        if((curr != prev) or ((i+1) == s.size())) {
            printf("i=%d c=%c,%d p=%c,%d\n", i, curr, counts[curr-'a'], prev, counts[prev-'a']);
            if(counts[prev-'a'] > 2) {
                uint32_t j = counts[prev-'a'];
                int i2 = i - j + 2;
                std::string str = s.substr(i1, i2);
                printf("[%s] i=%d j=%d i1=%d i2=%d\n", str.c_str(), i, j, i1, i2);
                if(str.size() > longest.size()) {
                    longest = str;
                }
                counts[0] = 0;
                counts[1] = 0;
                i -= 3;
                i1 = i+1;
                printf("i=%d i1=%d\n", i, i1);
                prev = s[i];
            }
            else {
                if((i+1) == s.size()) {
                    i2 = i;
                    std::string str = s.substr(i1, i2);
                    printf("%s\n", str.c_str());
                    if(str.size() > longest.size()) {
                        longest = str;
                    }
                    
                    
                }
                counts[prev-'a'] = 0;
                prev = curr;
            }
        }
    }
    
    printf("%d %d\n", counts[0], counts[1]);
    
    return(longest);
}

int main(int argc, char **argv){
    std::string s = "aabbaaaaabb";
    //std::string s = "aabbaabbaabbaa";
    std::string l = longestSubStr(s);
    printf("%s --> %s\n", s.c_str(), l.c_str());
    return(0);
}
