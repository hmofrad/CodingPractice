/*
 *  Problem: https://leetcode.com/discuss/interview-question/398035/
 *  Compile: g++ -o minDeletions minDeletions.cpp -std=c++11 -g -Wall -fsanitize=address && ./minDeletions 
 *  Min Deletions to Make Frequency of Each Letter Unique
 *  Example 1: Input: "eeeeffff" Output: 1
 *  Explanation: We can delete one occurence of 'e' or one occurence of 'f'. Then one letter will occur four times and the other three times.
 *  Example 2: Input: "aabbffddeaee" Output: 6
 *  Explanation: For example, we can delete all occurences of 'e' and 'f' and one occurence of 'd' to obtain the word "aabbda".
 *  Note that both 'e' and 'f' will occur zero times in the new word, but that's fine, since we only care about the letter that appear at least once.
 *  Example 3: Input: "llll" Output: 0
 *  Explanation: There is no need to delete any character.
 *  Example 4: Input: "example" Output: 4 
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

int minDeletions(std::string s) {
    int count = 0;
    /*
    std::unordered_map<char, int> map; 
    for(auto c: s) {
        map[c]++;
    }
    
    for(auto m: map) {
        printf("%c %d\n", m.first, m.second);
    }
    */
    
    
    
    std::vector<int> alphas(26);
    for(auto c: s) {
        alphas[c-'a']++;
    }
    
    std::vector<int> counts;
    
   
    
    for(auto a: alphas) {
        if(a) {
            counts.push_back(a);
        }
    }
    std::sort(counts.rbegin(), counts.rend());
    for(auto c: counts) {
        printf("%d ", c);
    }
    printf("\n");
    
    for(uint32_t i = 1; i < counts.size(); i++) {
        if(counts[i-1] == counts[i]) {
            uint32_t j = i;
            while((counts[i-1] == counts[j]) and counts[j]){
                counts[j]--;
                count++;
                j++;
            }
        }
        for(auto c: counts) {
            printf("%d ", c);
        }
        printf("\n");
        
    }
    
    
    

    
    return(count);
}


int main(int argc, char **argv){
    //std::string s = "aabbffddeaee"; 
    //std::string s = "llll";
    std::string s = "example";    
    printf("Str=%s\n", s.c_str());
    int count = minDeletions(s);
    printf("Count=%d\n", count);
    return(0);
}
