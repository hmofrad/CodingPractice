/* 
 * g++ -o colonies colonies.cpp && ./colonies
 * DFS solution for undirected cyclic graphs: Time complexity O(nedges+nvertice)
 * Union solution for directed acyclic graphs (one I wrote in my interview): O(l) where l is the number of edges between src and dst
*/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>


/* DFS solution */
std::unordered_map<int, std::unordered_set<int>> read_edges(std::vector<std::vector<int>>& edges) {
    std::unordered_map<int, std::unordered_set<int>> grid;
    for(std::vector<int>& edge: edges) {
        int v1 = edge[0];
        int v2 = edge[1];
        grid[v1].insert(v2);
        grid[v2].insert(v1);
    }
    return grid;
}

bool isAllied(std::unordered_map<int, std::unordered_set<int>>& grid, int src, int dst) {
    return grid[src].count(dst) != 0;
}

bool isAtTheSameColony(std::unordered_map<int, std::unordered_set<int>>& grid, std::unordered_set<int>& visited, int src, int dst) {
    if(src == dst) { return true; }
    if(visited.insert(src).second == false) { return false; }
    std::unordered_set<int>& row = grid[src];
    bool connected = false;
    for(int col: row) {
        connected = isAtTheSameColony(grid, visited, col, dst);
        if(connected) { break; }
    }
    visited.erase(src);
    return connected;
}


void dfs(std::vector<std::vector<int>>& edges) {
    std::unordered_map<int, std::unordered_set<int>> grid = read_edges(edges);
    
    std::cout << "isAllied(0,1):" << isAllied(grid,0,1) << std::endl;
    std::cout << "isAllied(1,5):" << isAllied(grid,1,5) << std::endl;
    std::cout << "isAllied(4,2):" << isAllied(grid,4,2) << std::endl;
    
    std::unordered_set<int> visited;
    std::cout << "isAtTheSameColony(0,5):" << isAtTheSameColony(grid,visited,0,5) << std::endl;
    std::cout << "isAtTheSameColony(1,5):" << isAtTheSameColony(grid,visited,1,5) << std::endl;
    std::cout << "isAtTheSameColony(2,4):" << isAtTheSameColony(grid,visited,2,4) << std::endl;      
}


/* Union Solution */
int union_find(std::vector<int>& union_set, int u) {
    return union_set[u]==-1 ? u : union_find(union_set, union_set[u]);
}

int union_merge(std::vector<int>& union_set, int u, int v) {
    int p_u = union_find(union_set, u);
    int p_v = union_find(union_set, v);
    if(p_u != p_v) { union_set[p_u] = p_v; }
}


std::vector<int> read_edges_(std::vector<std::vector<int>>& edges, int nvertices) {
    std::vector<int> union_set(nvertices,-1);
    for(std::vector<int>& edge: edges) {
        int v1 = edge[0];
        int v2 = edge[1];
        int p_v1 = union_find(union_set, v1);
        int p_v2 = union_find(union_set, v2);
        if(v1 < v2) { union_merge(union_set, p_v1, p_v2); }
        else { union_merge(union_set, p_v2, p_v1); }
    }
    return union_set;
}

bool isAllied_(std::vector<int>& union_set, int u, int v) {
    return u < v ? union_set[u]==v : union_set[v]==u; // small change here to support indirected graphs
}

bool isAtTheSameColony(std::vector<int>& union_set, int u, int v) {
    int p_u = union_find(union_set, u);
    int p_v = union_find(union_set, v);
    return p_v==p_u;
}

void union_(std::vector<std::vector<int>>& edges, int nvertices) {
    std::vector<int> union_set = read_edges_(edges, nvertices);
    
    std::cout << "isAllied(0,1):" << isAllied_(union_set, 0,1) << std::endl;
    std::cout << "isAllied(1,5):" << isAllied_(union_set, 1,5) << std::endl;
    std::cout << "isAllied(4,2):" << isAllied_(union_set, 4,2) << std::endl;
    
    std::cout << "isAtTheSameColony(0,5):" << isAtTheSameColony(union_set, 0,5) << std::endl;
    std::cout << "isAtTheSameColony(1,5):" << isAtTheSameColony(union_set, 1,5) << std::endl;
    std::cout << "isAtTheSameColony(2,4):" << isAtTheSameColony(union_set, 4,2) << std::endl; 
}

int main() {
    //Colony 1: [0,1,3,5], Colony 2: [2,4]
    std::vector<std::vector<int>> edges = {{0,1}, {0,3}, {2,4}, {3,5}, {5,0}};
    std::cout << "DFS Solution:" << std::endl;
    dfs(edges);
    std::cout << "\nUNION Solution:" << std::endl;
    int nvertices = 6;
    union_(edges, nvertices);
    
    return 0;
}
