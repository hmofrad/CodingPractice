/*
 *  Problem: https://leetcode.com/problems/rotate-string/
 *  Compile: g++ -o rotateString rotateString.cpp -std=c++11 -g -Wall -fsanitize=address && ./rotateString
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

std::string rotate(std::string str, int m) {
    m = m % str.length();
    int n = str.length() - m;
    std::string str1 = str.substr(n, m);
    str1 += str.substr(0, n);
    return(str1);
}

bool rotateString1(std::string A, std::string B) {
    bool ret = false;
    if(A.length() != B.length()) return(false);
    
    for(uint32_t i = 0; i < A.length(); i++) {
        std::string C = rotate(A, i);
        if(not C.compare(B)) {
            ret = true;
            break;
        }
    }
    return(ret);    
}

bool rotateString(std::string A, std::string B) {
    A += A;
    printf("%s %s\n", A.c_str(), B.c_str());
    
    bool ret = false;
    int curr_index = 0;
    int len = 0;
    int len_so_far = 0;
    
    for(uint32_t i = 0; i < A.size()-B.size(); i++) {
        printf("%d %c %d\n", i, A[i], ret);
        if(A[i] == B[0]) {
            bool found = true;
            for(uint32_t j = 0; j < B.size(); j++) {
                if(A[i+j] != B[j]) {
                    found = false;
                    break;
                }
            }
            ret |= found;
            if(ret) break;
        }
    }
    return(ret);
}

int main(int argc, char** argv){
    std::string A = "abcde";
    std::string B = "cdeab";
    bool r = rotateString(A, B);
    printf("%s %s %d\n", A.c_str(), B.c_str(), r);
    return(0);
}