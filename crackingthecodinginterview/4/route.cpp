/*
 *  Cracking the coding interview: Problem 4.2: Route
 *  Compile & run: g++ -o route route.cpp -g -Wall -std=c++11 -fsanitize=address  && ./route
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>

void get_path(std::vector<std::vector<bool>> adjacency, uint32_t nStart, uint32_t nEnd, std::vector<uint32_t>& path) {
    //if(path.empty()) {
        auto row = adjacency[nStart];
        for(uint32_t j = 0; j < row.size(); j++) {
            if(row[j]) {
                path.push_back(j);
                if(j == nEnd) {
                    for(auto p: path)
                        printf("%d ", p);
                    printf("\n");
                    path.clear();
                }
                else
                    get_path(adjacency, j, nEnd, path);
            }
        }
    //}
}

bool route(std::vector<std::vector<uint32_t>> edges, uint32_t nStart, uint32_t nEnd, uint32_t numNodes) {
    std::vector<std::vector<bool>> adjacency(numNodes, std::vector<bool>(numNodes));
    
    uint32_t n0 = 0;
    uint32_t n1 = 0;
    for(auto e: edges) {
        if(e[0] > e[1]) {
            n0 = e[1];
            n1 = e[0];
        }
        else {
            n0 = e[0];
            n1 = e[1];
        }
        
        adjacency[n0][n1] = 1;
    }
    
    for(auto r: adjacency) {
        for(auto c: r) {
            printf("%d ", c == 1);
        }
        printf("\n");
    }
    printf("\n\n");
    
    std::vector<uint32_t> path;
    bool ret = 0;
    path.push_back(nStart);
    get_path(adjacency, nStart, nEnd, path);
    

    
    return(ret);
}




int main(int argc, char** argv) {
    uint32_t numNodes = 6;
    std::vector<std::vector<uint32_t>> edges = {{1, 2}, {2, 3}, {3, 5}, {1, 4}, {5, 5}};
    uint32_t nStart = 1;
    uint32_t nEnd = 5;
    
    bool r = route(edges, nStart, nEnd, numNodes);
    printf("%d\n", r);
    
    return(0);
}