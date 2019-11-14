    /*
 *  Problem: https://leetcode.com/problems/maximum-product-of-word-lengths/
 *  Compile: g++ -o maxProduct maxProduct.cpp -std=c++11 && ./maxProduct #-fsanitize=address 
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

int maxProduct(std::vector<std::string>& words) {
    if(words.empty()) return 0;
    for(auto& w :words) {
        printf("%s ", w.c_str());
    }
    printf("\n");
    
    std::vector<std::vector<int>> counts(words.size(), std::vector<int>(27));
    for(int i = 0; i < words.size(); i++) {
        auto& w = words[i];
        for(auto& c: w) {
            counts[i][c-'a']++;
        }
    }
    
    for(int i = 0; i < words.size(); i++) {
        printf("%6s:", words[i].c_str());
        for(int j = 0; j < 27; j++) {
            printf("%d ", counts[i][j]);
        }
        printf("\n");
    }
    int max = 0;
    for(int i = 0; i < words.size() - 1; i++) {
        for(int j = i+1; j < words.size(); j++) {
            bool found = true;
            int len = words[i].size();
            int k1 = i;
            int k2 = j;
            if(words[j].size() < words[i].size()) {
                len = words[j].size();
                k1 = j;
                k2 = i;
            }
            for(int k = 0; k < len; k++) {
                if(counts[k1][words[k1][k]-'a'] and counts[k2][words[k1][k]-'a']) {
                    found = false;
                    break;
                }
            }
            if(found) {
                //printf("%s vs %s\n", words[i].c_str(), words[j].c_str());
                int mul = words[i].size() * words[j].size();
                max = (max < mul) ? mul : max;
            }
        }
    }
    
    return(max);
}

int main(int argc, char **argv){
    //std::vector<std::string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    //std::vector<std::string> words = {"a","ab","abc","d","cd","bcd","abcd"};
    //std::vector<std::string> words = {"a","aa","aaa","aaaa"};
    std::vector<std::string> words = {};
    int max = maxProduct(words);
    printf("maxProduct = %d\n", max);
    
    return(0);
}






