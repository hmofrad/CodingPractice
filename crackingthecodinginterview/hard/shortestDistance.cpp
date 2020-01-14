/*
 *  Cracking the coding interview: Problem 18.5: Find the shortet distance between two words
 *  Compile & run: g++ -o  shortestDistance shortestDistance.cpp -g -Wall -std=c++11 -fsanitize=address  && ./shortestDistance
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <string>


int dist(std::vector<std::string> strs, const std::string str1, const std::string str2) {
    int d = INT_MAX;
    int last_pos_str1 = -1;
    int last_pos_str2 = -1;
    for(uint32_t i = 0; i < strs.size(); i++) {
        if(strs[i] == str1) {
            printf("1. %d %d\n", i, d);
            last_pos_str1 = i;
            int dis = last_pos_str1 - last_pos_str2;
            if(last_pos_str2 >= 0 and d > dis) {
                d = dis;
            }
        }
        else if(strs[i] == str2) {
            printf("2. %d %d\n", i, d);
            last_pos_str2 = i;
            int dis = last_pos_str2 - last_pos_str1;
            if(last_pos_str1 >= 0 and d > dis) {
                d = dis;
            }
        }
    }
    
    return(d);
}

int main(int argc, char** argv) {
    std::vector<std::string> strs = {"the", "quick", "brown", "fox", "jumps", "over", "the", "tall", "wall", "yesterday"};
    std::string str1 = strs[0];
    std::string str2 = strs[8];
    int d = dist(strs, str1, str2);
    printf("%s <--> %s: distance=%d\n", str1.c_str(), str2.c_str(), d);
    return(0);
}