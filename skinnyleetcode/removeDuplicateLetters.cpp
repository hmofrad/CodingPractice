    /*
 *  Problem: https://leetcode.com/problems/remove-duplicate-letters/discuss/404049/Easy-and-100-fast-c%2B%2B-solution
 *  Compile: g++ -o removeDuplicateLetters removeDuplicateLetters.cpp -std=c++11 && ./removeDuplicateLetters #-fsanitize=address 
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
#include <map>
#include <cmath>
#include <unordered_map>

std::string removeDuplicateLetters(std::string s) {
    std::string out = "\0";
    
    std::vector<int> count(26);
    std::vector<bool> notUsed(26, true);
    std::string s1="";
    for(auto c: s)
        count[c-'a']++;
    
    for(auto c: count)
        printf("%d ", c);
    printf("\n");
    
    for(auto c:s) {
        count[c-'a']--;
        printf("%c %d %d\n", c, c-'a', count[c-'a']--);
        if(notUsed[c-'a']) {
            while(s1.size() > 0 and
                  c < s1[s1.size()-1] and 
                  count[s1[s1.size()-1]-'a'] > 0) {
                printf("  %lu %d \n", s1.size()-1, (s1[s1.size()-1]-'a'));
                notUsed[s1[s1.size()-1]-'a'] = true;
                s1.erase(s1.size()-1);
            }
            s1+=c;
            notUsed[c-'a'] = false;
        }
    }
    return(s1);
}


int main(int argc, char **argv){
    std::string str = "cbacdcbc";
    std::string out = removeDuplicateLetters(str);
    printf("removeDuplicateLetters(%s)=%s\n", str.c_str(), out.c_str());
    

    return(0);
}






