/*
 *  Problem: https://leetcode.com/problems/the-skyline-problem/
 *  The Skyline Problem
 *  Compile: g++ -o skyline skyline.cpp -g -Wall -fsanitize=address && ./skyline   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>


void print_mat(std::vector<std::vector<int>> mat) {
    for(auto row: mat) {
        for(auto col: row) {
            printf("%d ", col);
        }
        printf("\n");
    }
    printf("\n");
}

std::vector<std::vector<int>> get_skyline(std::vector<std::vector<int>> buildings) {
    std::vector<std::vector<int>> skyline;
    
    int32_t length = 0;
    for(auto& building: buildings) {
        if(building[1] > length) length = building[1];
    }
    //printf("%d\n", length);
   
    for(int32_t i = 0; i <= length; i++) {
        std::vector<int> b;
        for(auto& building: buildings) {
            if((i >= building[0]) and (i <= building[1]-1)) {
                b.push_back(building[2]);
            }
        }
        int h = 0;
        if(!b.empty()) {
            //for(auto bb: b) {printf("%d ", bb);} printf("\n");
            h = *std::max_element(b.begin(), b.end());
        }
        if(!skyline.empty()) {
            auto& s = skyline.back();
            if(s[1] != h) skyline.push_back({i, h});
        //    if(i == length) skyline.push_back({i, 0});
        }
        else {
            skyline.push_back({i, h});
        }
        //printf("[%d %d] \n", i, h);
    }
    printf("\n");
    
    //for(uint32_t i = 0; i < skyline.size()-1; i++) {
    //    if(skyline[i]
    //}
    
    for(auto s: skyline) {
        printf("[%d %d] ", s[0], s[1]);
    }
    printf("\n");
    
    
    return(skyline);
}

int main(int argc, char** argv){
    std::vector<std::vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    //print_mat(buildings);
    std::vector<std::vector<int>> skyline = get_skyline(buildings);
    //print_mat(skyline);
    
    return(0);
}