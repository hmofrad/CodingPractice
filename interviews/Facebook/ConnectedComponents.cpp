
/* 
 * Facebook
 * Given information about the links between various data centers, 
 * find the groups of isolated but connected data centers. 
 * For example --> Input : {A<->B, B<->C, D<->E}, Output : {{A, B, C}, {D, E}}
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//g++ -o fb fb.cpp && ./fb
//n various data centers, find the groups of isolated but connected data centers. 
//For example --> Input : {A<->B, B<->C, D<->E}, Output : {{A, B, C}, {D, E}}


std::vector<bool> visited;

void getPath(std::vector<std::vector<int>> adj, int n, std::vector<int>& path) {
    for(int i = 0; i < adj[n].size(); i++) {
        if(adj[n][i]) {
            if(path.empty()) {
                path.push_back(n);
                visited[n] = true;
            }
            if(i != n) {
                path.push_back(i);
                visited[i] = true;
                getPath(adj, i, path);
            }
        }
    }    
}

std::vector<std::vector<int>> f(uint32_t numNodes, std::vector<std::vector<int>> edges){
    std::vector<std::vector<int>> adj(numNodes, std::vector<int>(numNodes));
    std::vector<std::vector<int>> components;
    std::vector<int> nodes;
    printf("Edges\n");
    for(auto e:edges){
        printf("%d %d\n", e[0], e[1]);
        int e0 = 0;
        int e1 = 0;

        if(e[0] <= e[1]) {
            e0 = e[0];
            e1 = e[1];
        }
        else {
            e0 = e[1];
            e1 = e[0];
        }
        adj[e0][e1] = 1;        
        
        if(std::find(nodes.begin(), nodes.end(), e0) == nodes.end()) {
            nodes.push_back(e0);
        }
        
        if(std::find(nodes.begin(), nodes.end(), e1) == nodes.end()) {
            nodes.push_back(e1);
        }
    }
    printf("\n");
    
    printf("Adjacency list\n");
    for(auto r: adj) {
        for(auto c: r) {
            printf("%d ", c);
        }
        printf("\n");
    }

    
    std::vector<std::vector<int>> paths;
    paths.resize(numNodes);
    visited.resize(numNodes);
    for(auto n: nodes) {
        if(not visited[n])
            getPath(adj, n, paths[n]);
    }
    
    for(auto path: paths) {
        if(not path.empty())
            components.push_back(path);
    }
    
    return(components);   
}

int main(int argc, char** argv) {
    std::vector<std::vector<int>> edges = {{0,1}, {1,2}, {3,3}, {3,4}, {5, 5}};
    
    std::vector<std::vector<int>> components = f(6  , edges);
    
    printf("Components= {");
    for(auto component: components) {
        printf("{");
        for(auto c:component) {
            printf("%d ", c);
        }
        printf("},");
    }
    printf("}\n");
    
    
    
    return(0);
}