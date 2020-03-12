/*
 *  Problem: https://leetcode.com/problems/minimum-index-sum-of-two-lists/
 *  Compile: g++ -o findRestaurant findRestaurant.cpp -std=c++11 -g -Wall -fsanitize=address && ./findRestaurant
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits.h>


std::vector<std::string> findRestaurant1(std::vector<std::string>& list1, std::vector<std::string>& list2) {
    std::vector<std::string> list;
    int len = -1;
    for(uint32_t i = 0; i < list1.size(); i++) {
        for(uint32_t j = 0; j < list2.size(); j++) { 
            if(not list1[i].compare(list2[j])) {
                printf("%d %d %s\n", i, j, list1[i].c_str());
                if(len == -1) {
                    list = {list1[i]};
                    len = i+j;
                }
                else {
                    int l = i+j;
                    if(l == len) {
                        list.push_back(list1[i]);
                    }
                }
            }
        }
    }
    
    return(list);
}

std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
    std::vector<std::string> list;
    
    std::unordered_map<std::string, int> m1;
    std::unordered_map<std::string, int> map;
    
    for(uint32_t i = 0; i< list1.size(); i++) {
        m1[list1[i]] = i;
    }
    
    for(uint32_t i = 0; i< list2.size(); i++) {
        if(m1.find(list2[i]) != m1.end()) {
            map[list2[i]] = i + m1[list2[i]];
        }
    }
    
    int min = INT_MAX;
    for(auto m: map) {
        if(m.second < min) {
            min = m.second;
        }
    }
    
    for(auto m: map) {
        if(m.second == min) {
            list.push_back(m.first);
        }
    }
    
    return(list);
}


int main(int argc, char **argv){
    std::vector<std::string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    std::vector<std::string> list2 = {"KFC","Burger King","Tapioca Express","Shogun"};
    std::vector<std::string> list = findRestaurant1(list1, list2);
    for(auto l: list) {printf("\"%s\" ", l.c_str());} printf("\n");
    return(0);
}