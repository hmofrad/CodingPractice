/*
 *  Problem: reverseWords
 *  Compile: g++ -o reverseWords reverseWords.cpp -std=c++11 && ./reverseWords
 *  Execute: ./reverseWords
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



std::string reverseWords(std::string s) {
    std::string ret;
    int i = 0;
    char ss = s[i];
    while(ss == ' ') {
        i++;
        ss = s[i];
    }
    for(; i < s.size(); i++) {
        ss = s[i];
        
        if((ss == ' ')) {
            while((i + 1) < s.size()) {
                if(s[i+1] == ' ') {
                    i++;
                }
                else {
                    //i++;
                    break;
                }
            }
            ss = s[i];
        }
        
        //if(ss != ' ') {
            ret += ss;
            printf("%c", ss);
        //}
    }
    printf("\n");
    if(ret[ret.size() - 1] == ' ')
        ret.pop_back();
    std::string ret1;
    i = 0;
    int j = ret.size()-1;
    //for(int i = ret.size() - 1; i > 0; i--) {
    while(i < ret.size()) {
        printf("<");
        std::string t;
        while((j >= 0) and ret[j] != ' '){
            t += ret[j];
            printf("%c", ret[j]);
            j--;
            i++;
        }
        j--;
        i++;
        for(int k = 0; k < t.size()/2; k++)
            std::swap(t[k], t[t.size() - k - 1]);
        printf("> %s\n", t.c_str());
        ret1 += t;
        ret1 += ' ';
    }
    if(ret1[ret1.size() - 1] == ' ')
        ret1.pop_back();
    
    
    return(ret1);
}

int main(int argc, char** argv) {
    std::string s =  "        a good   example       ";
    std::string r = reverseWords(s);
    printf("hammingWeight(%s)=\"%s\"\n", s.c_str(), r.c_str());
    return(0);
}