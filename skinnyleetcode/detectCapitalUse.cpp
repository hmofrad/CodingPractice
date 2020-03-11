/*
 *  Problem: https://leetcode.com/problems/detect-capital/
 *  Compile: g++ -o detectCapitalUse detectCapitalUse.cpp -std=c++11 -g -Wall -fsanitize=address && ./detectCapitalUse
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

bool isCapital(char c) {
    return(c >= 'A' and c <= 'Z');
}


bool detectCapitalUse(std::string word) {
    bool ret = true;
    if(not word.empty()) {
        bool tf = isCapital(word[0]);
        for(uint32_t i = 1; i < word.size(); i++){
            bool tf0 = tf;
            tf = isCapital(word[i]);
            printf("%d %d %d\n", i, tf0, tf);
            if(i == 1) {
                if(tf0 == false and tf == true) {
                    ret = false;
                    break;
                }
            }
            else {
                //printf("%d %d %d\n", i, tf0, tf);
                if(tf0 != tf) {
                    ret = false;
                    break;
                }
            }
        }
    }
    return(ret);        
}

int main(int argc, char **argv){
    std::string s = "USA";    
    std::string s1 = "leetcode";
    std::string s2 = "Google";
    std::string s3 = "FlaG";
    
    bool ret = false;
    //ret = detectCapitalUse(s);
    //printf("%s=%d\n", s.c_str(), ret);
    
    //ret = detectCapitalUse(s1);
    //printf("%s=%d\n", s1.c_str(), ret);
    
    //ret = detectCapitalUse(s2);
    //printf("%s=%d\n", s2.c_str(), ret);
    
    //ret = detectCapitalUse(s3);
    //printf("%s=%d\n", s3.c_str(), ret);
    
    ret = detectCapitalUse("fLs");
    printf("%s=%d\n", s3.c_str(), ret);
    
    return(0);
}