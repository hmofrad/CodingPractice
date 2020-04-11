/*
 *  https://leetcode.com/problems/brace-expansion/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std; 

void permute(std::vector<std::vector<std::string>> tokens, std::vector<std::string>& ans, std::string str, int index) {
    int size = tokens.size();
    if(size == index) {
        //printf()
        ans.push_back(str);
        return;
    }
    
    
    for(int i = 0; i < tokens[index].size(); i++) {
        permute(tokens, ans, str + tokens[index][i], index+1);
    }
    
}

vector<string> expand(string S) {
    std::vector<std::vector<std::string>> tokens;
    
    std::vector<char> stack;
    int size = S.length();
    int i = 0;
    while(i < size) {
        printf("%d %c\n", i, S[i]);
        std::vector<std::string> temp;
        if(S[i] == '{') {
            i++;
            std::string t; 
            while(S[i] != '}') {
                if(S[i] != ',') {
                    t.push_back(S[i]);
                    
                }
                else {
                    temp.push_back(t);    
                    t.clear();
                }
                i++;
            }
            temp.push_back(t);   
            i++;
        }
        else {
            std::string t;
            while(i < size and S[i] != '{') {
                t.push_back(S[i]);
                i++;
            }
            temp.push_back(t);
        }
        tokens.push_back(temp);
    }
    
    for(std::vector<std::string> token: tokens) {
        for(std::string t: token) {
            printf("%s ", t.c_str());
        }
        printf("\n");
    }
    
    for(std::vector<std::string>& token: tokens) {
        std::sort(token.begin(), token.end());
    }
    
    std::vector<std::string> ans;
    permute(tokens, ans, "", 0);
    
    for(std::string a: ans) {
        printf("%s\n", a.c_str());
    }
    
    return(ans);
    
}

int main() {
    std::string S = "{a,be}cdef{d,e}f";
    std::vector<string> out = expand(S);
    return 0;
}
