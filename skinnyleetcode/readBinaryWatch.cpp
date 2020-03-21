/*
 *  Problem: https://leetcode.com/problems/binary-watch/
 *  Compile: g++ -o readBinaryWatch readBinaryWatch.cpp -std=c++11  -g -Wall -fsanitize=address && ./readBinaryWatch
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> readBinaryWatch(int num) {
    std::vector<std::string> times;
    
    for(int i = 0; i < 4; i++) {
        for(int j = i+num; j < 4; j++) {
            
        }
    }
    
    
    return(times);
}

int main(int argc, char **argv){
    int num = 1;
    std::vector<std::string> times = readBinaryWatch(num);
    for(auto t: times) {
        printf("%s ", t.c_str());
    }
    printf("\n");
    return(0);
}






