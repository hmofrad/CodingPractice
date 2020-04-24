/*
 *  https://leetcode.com/problems/print-words-vertically/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
    vector<string> tokenize(std::string s) {
        int len = s.length();
        int i = 0;
        int j = 0;
        std::vector<string> words;
        while(i < len) {
            if(s[i] == ' ') {
                int len = i-j;
                std::string str = s.substr(j, len);
                words.push_back(str);
                j=i+1;
            }
            i++;
        }
        int len1 = i-j+1;
        std::string str = s.substr(j, len1);
        words.push_back(str);
        return words;
    }
    std::vector<std::string> flip_vertically(std::vector<std::string> words) {
        
        //for(std::string word: words) longest = std::max((int) word.length(), longest);
        
        int size = words.size();
        std::vector<int> lengthes(size);
        int longest = 0;
        for(int i = size-1; i >= 0; i--) {
            lengthes[i] = longest = std::max((int) words[i].length(), longest);
        }
        std::vector<std::string> flipped(longest);
        for(int i = 0; i < size; i++) {
            int len = words[i].length();
            for(int j = 0; j < len; j++) {
                flipped[j].push_back(words[i][j]);
            }
            for(int j = len; j < lengthes[i]; j++) {
                flipped[j].push_back(' ');
            }
        }
        return flipped;
    }
    vector<string> printVertically(string s) {
        vector<string> words = tokenize(s);
        std::vector<std::string> flipped = flip_vertically(words);
        return flipped;
    }
    
        vector<string> printVertically1(string s) {
        std::vector<std::string> ans;
        int count = 0;
        int word = 0;
        for(char c: s) {
            if(c == ' ') {
                count = 0;
                word++;
            }
            else {
                if(count >= ans.size()) {
                    ans.push_back(std::string ());
                }
                while(word > ans[count].size()) ans[count].push_back(' ');
                ans[count++].push_back(c);
            }
        }
        return ans;    
    }

int main() {
    std::string s = "TO BE OR NOT TO BE";
    std::vector<std::string> w = printVertically(s);
    for(auto v: w) printf("<%s>\n", v.c_str());
    return 0;
}