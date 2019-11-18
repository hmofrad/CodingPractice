    /*
 *  Problem: https://leetcode.com/problems/reverse-string/
 *  Compile: g++ -o reverseString reverseString.cpp -std=c++11 && ./reverseString #-fsanitize=address 
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
void reverseString(std::vector<char>& s) {
    
    for(int i = 0; i < s.size()/2; i++) {
        std::swap(s[i], s[s.size() - i -1]);
    }
        
}

int main(int argc, char **argv){
    std::vector<char> s = {'h','e','2','l','o', '1'};
    for(auto& c: s) printf("%c ", c);
    printf("\n");
    reverseString(s);
    for(auto& c: s) printf("%c ", c);
    printf("\n");

    return(0);
}






