/*
 *  Problem: https://leetcode.com/problems/queue-reconstruction-by-height/
 *  Compile: g++ -o reconstructQueue reconstructQueue.cpp -std=c++11 -g -Wall -fsanitize=address && ./reconstructQueue
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <numeric>

void print(std::vector<std::vector<int>> people) {
    for(auto p: people) {
        printf("[%d, %d] ", p[0], p[1]);
    }
    printf("\n");
}

std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
    std::vector<std::vector<int>> sorted_people;
    
    /*
    for(uint32_t i = 0; i < people.size()-1; i++) {
        for(uint32_t j = i; j < people.size(); j++) {    
            if((people[i][0] < people[j][0]) or ((people[i][0] == people[j][0]) and (people[i][1] < people[j][1]))) {
                std::swap(people[i], people[j]);
            }
        }
    }
    */
    
    //int i = 0;
    
    std::vector<int> visited(people.size(), 0);
    while(true) {
        int max = INT_MIN;
        for(uint32_t i = 0; i < people.size(); i++) {
            if(not visited[i] and people[i][0] > max) {
                max = people[i][0];
            }
        }
        std::vector<std::vector<int>> temp;
        for(uint32_t i = 0; i < people.size(); i++) {
            if(not visited[i] and people[i][0] == max) {
                temp.push_back(people[i]);
                visited[i] = 1;
            }
        }
        /*
        if(sorted_people.empty()) {
            sorted_people.insert(sorted_people.begin(), temp.begin(), temp.end());
        }
        else {
            printf("%lu\n", sorted_people.size());
            sorted_people.resize(sorted_people.size()+temp.size());
            printf("%lu\n", sorted_people.size());
            for(uint32_t i = 0; i < temp.size(); i++) {
                //for(uint32_t j = 0; j < sorted_people.size() - temp.size(); j++) {
              //      if(
                //}
                //sorted_people.insert(sorted_people.begin()+temp[i][0], temp.begin()+i, temp.begin()+i+1);
                //printf("%d %d\n", t[0], t[1]);
            }
            
            //for(auto p: sorted_people) printf("%d %d\n", p[0], p[1]);
            //printf("%lu\n", sorted_people.size());
            //std::exit(0);
        }
    */
        if(std::accumulate(visited.begin(), visited.end(), 0) == (int32_t) visited.size()) break;
    }
    
    
    /*
    std::sort(people.begin(), people.end(), [](std::vector<int>& a, std::vector<int>& b) {
        if(a[0] != b[0]) {
            return((a < b) and (a[1] > b[1]));
        }
        else {
            return(a[1]<b[1]);
        }
    });
    */
    /*
[7,0] [7,1]
[7,0] [6,1] [7,1]
[5,0] [7,0] [6,1] [5,2] [7,1]
[5,0] [7,0] [6,1] [5,2] [4,4] [7,1]
            
    */
    
    
    return(sorted_people);
}

int main(int argc, char **argv){
    std::vector<std::vector<int>> people = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    std::vector<std::vector<int>> sorted_people = reconstructQueue(people);
    print(people);
    print(sorted_people);
    return(0);
}






