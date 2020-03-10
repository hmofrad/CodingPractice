/*
 *  Problem: https://leetcode.com/problems/island-perimeter/
 *  Compile: g++ -o islandPerimeter islandPerimeter.cpp -std=c++11 -g -Wall -fsanitize=address && ./islandPerimeter
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>



int islandPerimeter(std::vector<std::vector<int>>& grid) {
    /*
    std::vector<std::pair<int, int>> q;
    uint32_t m = grid.size();
    uint32_t n = grid[0].size();
    for(uint32_t i = 0; i < m; i++) {
        bool b = false;
        for(uint32_t j = 0; j < n; j++) {
            if(grid[i][j]) {
                q.push_back({i, j});
                b = true;
            }
        }
        if(b) break;
    }
    
    if(not q.empty()) {
        for(uint32_t i = 
        
    }
    
    printf("%d %d %lu\n", q[0].first, q[0].second, q.size());
    */
    int p = 0;
    uint32_t m = grid.size();
    uint32_t n = (m>0) ? grid[0].size() : 0;

    for(uint32_t i = 0; i < m; i++) {
        for(uint32_t j = 0; j < n; j++) {
            if(grid[i][j]) {
                if(i == 0) {
                    p++;
                }
                if(i == m-1) {
                    p++;
                    //if(not grid[i-1][j]) p++;
                }
                if(i > 0) {
                    if(not grid[i-1][j]) p++;
                }
                
                if(i < m-1) {
                    if(not grid[i+1][j]) p++;
                }
                
                
                printf("%d %d %d\n", p, i, j);
                if(j == 0) {
                    p++;
                }
                if(j == n-1) {
                    p++;
                }
                if(j > 0) {
                    if(not grid[i][j-1]) p++;
                }
                if(j < n-1) {
                    if(not grid[i][j+1]) p++;
                }
                printf("%d %d %d\n", i, j, p);
            }
        }
    }
    
    
    
    return(p);    
}

int main(int argc, char **argv){
    std::vector<std::vector<int>> grid = {{1, 1}, {0,0}}; /*{{0,1,0,0},
                                          {1,1,1,0},
                                          {0,1,0,0},
                                          {1,1,1,1}};*/
    int r = islandPerimeter(grid);
    printf("%d\n", r);
    return(0);
}