    /*
 *  Problem: https://leetcode.com/problems/valid-anagram/
 *  Compile: g++ -o isAnagram isAnagram.cpp -std=c++11 && ./isAnagram
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <string.h>
#include <unordered_set>
#include <stack>
#include <numeric>

bool isAnagram1(std::string s, std::string t) {
    int n = s.size();
    int m = t.size();
    
    if((n == 0) or (m == 0)) return(true);
    if(n != m) return(false);
    
    std::string s_;
    
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(s[i] > s[j])
                std::swap(s[i],s[j]);
            if(t[i] > t[j])
                std::swap(t[i],t[j]);
        }
    }
    if(s == t)
        return(true);
    else
        return(false);
}

bool isAnagram(std::string s, std::string t) {
    int n = s.size();
    int m = t.size();
    
    if((n == 0) or (m == 0)) return(true);
    if(n != m) return(false);
    
    std::vector<int> uniq(26);
    
    for(int i = 0; i < n; i++) {
        //char& c = s[i];
        uniq[s[i] - 'a']++;
        uniq[t[i] - 'a']--;
    }

   for(auto& i: uniq) {
       if(i != 0)
           return(false);
   }
   return(true);
    
}



int main(int argc, char **argv){
    //std::string s = "a";
    //std::string t = "b";
    std::string s = "anagram";
    std::string t = "nagaram";
    printf("%s, %s ? %d\n", s.c_str(), t.c_str(), isAnagram(s, t));
    return(0);
}






