/*
 *  Problem: https://leetcode.com/problems/repeated-substring-pattern/
 *  Compile: g++ -o repeatedSubstringPattern repeatedSubstringPattern.cpp -std=c++11 -g -Wall -fsanitize=address && ./repeatedSubstringPattern
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

bool unique(std::string str, int left, int right) {
    bool u = true;
    int ALPHABET_SIZE = 26; 
    std::vector<bool> map(ALPHABET_SIZE, false);
    
    for(int i = left; i <= right; i++) {
        if(not map[str[i] - 'a']) {
            map[str[i] - 'a'] = true;
        }
        else {
            u = false;
            break;
        }
    }
    return(u);
}


bool repeatedSubstringPattern1(std::string s) {
    
    if((s.size() == 1) or s.empty()) return(false);
    
    int m = s.size();
    
    int current_length = 0;
    int current_index = 0;
    int longest_so_far = 0;
    //int longest_index_so_far = 0;
    for(int j = 0; j < m; j++) {
        bool done = false;
        if(unique(s, current_index, j)) {
            current_length++;
        }
        else {
            done = true;
        }
        
        if(j+1 == m) {
            done = true;
        }
        
        //printf("s[%d]=%c %d %d %d\n", j, s[j], current_index, current_length, done);
        
        if(done) {
            if(current_length > longest_so_far) {
                longest_so_far = current_length;
                //longest_index_so_far = current_index;
            }
            current_length = j - current_index;
            current_index++;

        }
    }
    
    return((m%longest_so_far) == 0);
        //return(false);
    //}
    /*
    std::string s1;
    for(int i = 0; i < m/longest_so_far; i++) {
        s1 += s.substr(longest_index_so_far, longest_so_far);
    }
    printf("%s %d %d\n", s1.c_str(), longest_index_so_far, longest_so_far );
    
    //printf("%d %d\n", longest_index_so_far, longest_so_far);
    
    return(not s.compare(s1));    
    */
}  

 

bool check(std::string s, uint32_t len) {
    uint32_t t = len;
    uint32_t next = t + len;
    uint32_t index = 0;
    while(t < s.size()) {
        while(t < next) {
            if(s[index++] != s[t++]) {
                return(false);
            }
        }
        index = 0;
        next = t + len;
    }
    return(true);
}

bool repeatedSubstringPattern2(std::string s) {
    uint32_t len = s.size();
    for(uint32_t i = 2; i < s.size(); i++) {
        if(len%i == 0) {
            if(check(s, len/i)) {
                return(true);
            }
        }
    }
    return(false);
}




bool repeatedSubstringPattern3(std::string s) {
    //printf("%d %d\n", s.size(), s.size()/2);
    if(s.size() < 2) return(false);
    int current_length = 0;
    int current_index = 0;
    int longest_so_far = 0;
    int longest_index = 0;
    for(uint32_t i = 0; i < s.size()/2; i++) {
        printf("%d %c %c\n", i , s[i], s[s.size()/2+i]);
        bool tf = false;
        if(s[i] == s[s.size()/2+i]){
            current_length++;
        }
        else {
            tf = true;
        }
        
        if(i+1 == s.size()/2) {
            tf = true;
        }
        if(tf) {
            printf("dd %d\n", current_length);
            if(current_length > longest_so_far) {
                longest_so_far = current_length;
                longest_index = current_index;
            }
            current_length = i - current_index;
            current_index++;
        }
    }
    printf(">>%d %d\n", longest_index,  longest_so_far);
    return(longest_so_far and s.size()%(s.size()-longest_so_far) == 0);
}


bool repeatedSubstringPattern(std::string s) {
    int n=s.size();
    //uint32_t i=0,j;
    std::string x="";
    x+=s[0];
    
    while(x.size() <= s.size()/2) {
        int len=x.size();
        int k=len;
        int l=0;
        int flag=1;
        while(k<n) {
            if(s[k]==x[l]) {
                k++;
                l++;
                if(l==len) {
                    l=0;
                }
            }
            else  {
                flag=0;
                break;
            }
        }
        if(flag&&n%(len)==0) {
            return true;
        }
        x+=s[len];
    }
    return false;
}

int main(int argc, char **argv){
    std::string str = "abac";//"abcabdabcabc";// "abaababaab";//
    bool ret = repeatedSubstringPattern(str);
    printf("S=%s R=%d\n", str.c_str(), ret == true);

    return(0);
}






