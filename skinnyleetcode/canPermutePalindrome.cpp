/*
 *  https://leetcode.com/problems/palindrome-permutation/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        bool tf = true;
        int size = s.size();
        for(int i = 0; i < size/2; i++) {
            if(s[i] != s[size-1-i]) {
                tf = false;
                break;
            }
        }
        return(tf);
    }
    
    std::string insert_at(std::string t, int index, char c) {
        std::string first  = t.substr(0, index);
        std::string last = t.substr(index, t.size()-index);
        printf("%s %d %c: <%s> <%s>\n", t.c_str(), index, c, first.c_str(), last.c_str());
        return(first + c + last);
    }
    
    std::vector<std::string> permutations(std::string s) {
        //printf("%s\n", s.c_str());
        std::vector<std::string> perms;
        
        if(s.empty()) {
            perms.push_back("");
            return perms;
        }
        
        char first = s[0];
        s.erase(s.begin());
        
        std::vector<std::string> words = permutations(s);
        
        for(std::string word: words) {
        //    printf(">%s\n", word.c_str());
            int size = word.length();
            for(int i = 0; i <= size; i++) {
               // printf("%d %c\n", i, first);
                std::string t = insert_at(word, i, first);
                perms.push_back(t);
            }
        }
        return(perms);
    }
    
    bool canPermutePalindrome(string s) {
        bool tf = false;
        std::vector<std::string> ps = permutations(s);
        for(std::string p: ps) {
            if(isPalindrome(p)) {tf = true; break;}
        }
        return(tf);
    }
    
    bool canPermutePalindrome3(string s) {
        int size = s.length();
        //std::vector<std::string> p = permutations(s);
        std::vector<int> map(128);
        for(char c: s) {
            map[c]++;
        }
        
        bool tf = true;
        if(size%2) {
            int count = 0;
            for(int i = 0; i < 128; i++) {
                if(map[i]%2) {
                    count++;
                }
            }
            if(count > 1) tf = false;
        }
        else {
            for(int i = 0; i < 128; i++) {
                if(map[i]%2) {
                    tf = false;
                    break;
                }
            }
        }
        return(tf);
    }
    
    bool permutation(std::string s, std::string t, std::vector<int> indices) {
        int size = s.length();
        if(indices.empty()) return(isPalindrome(t));
        
        std::vector<int> indices1 = indices;
        int index1 = indices1.front();
        indices1.erase(indices1.begin());
        
        std::vector<int> indices2 = indices;
        int index2 = 0;
        if(indices.size() > 1) {        
            index2 = indices2[1];
            indices2.erase(indices2.begin()+1);
        }
        else {
           index2 = index1;
            indices2 = indices1;
        }
        
        return(permutation(s, t+s[index1], indices1) or permutation(s, t+s[index2], indices2));
    }

    bool canPermutePalindrome1(string s) {
        int size = s.length();
        std::vector<int> indices(size);
        for(int i = 0; i < size; i++) indices[i] = i;
        return permutation(s, "", indices);
    }
        
    bool canPermutePalindrome2(string s) {
        bool tf = false;
        int size = s.length();
        for(int i = 0; i < size; i++) {
            char temp = s[0];
            for(int i = 1; i < size; i++) s[i-1] = s[i];
            s[size-1] = temp;
            //printf("%s %d\n", s.c_str(), isPalindrome(s));
            if(isPalindrome(s)) {tf = true; break;}
        }
        
        return(tf);
    }
};