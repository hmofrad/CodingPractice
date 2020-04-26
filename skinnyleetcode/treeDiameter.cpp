/*
 *  https://leetcode.com/problems/tree-diameter/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
/*
I've never solved this problem before, so it got me thinking. Having a "global" diameter variable seems the way to go:

Start from 0 node.
For every unvisited sibling, run DFS to get the depth of that route.
- Track the maximum of any two depth in the global diameter variable.
- Track the maximum depth among all directions, and return it.
The picture below shows depth returned from running DFS on each node, with two maximums in green.
*/

 #include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

        int dfs(std::vector<std::vector<int>>& grid, std::vector<bool>& visited, int row, int& diameter) {
        visited[row] = true;
        int max_depth = 0;
        //int nrows = grid.size();
        //int ncols = nrows ? grid[0].size() : 0;
        //for(int j = 0; j < ncols; j++) {
            for(int j: grid[row]) {
            //if(grid[row][j] and not visited[j]) {
                if(not visited[j]){
                int depth = dfs(grid, visited, j, diameter);
                diameter = max(diameter, depth + max_depth);
                max_depth = max(depth, max_depth);
            }
        }
        return max_depth+1;
    }
    
    int treeDiameter(vector<vector<int>>& edges) {
        
        int nvertices = 0;
        for(std::vector<int> edge: edges) {
            if(edge[0] > nvertices) nvertices = edge[0];
            if(edge[1] > nvertices) nvertices = edge[1];
        }
        nvertices++;
        std::vector<bool> visited(nvertices);
        std::vector<std::vector<int>> grid(nvertices);
        for(std::vector<int>& edge: edges) {
            int& e1 = edge[0];
            int& e2 = edge[1];
            grid[e1].push_back(e2);
            grid[e2].push_back(e1);
        }
        
        int diameter = 0;
        dfs(grid, visited, 0, diameter);
        return diameter;
    }
    
    
    int union_len(std::vector<int>& u, int e) {
        return u[e] == -1 ? 0 : union_len(u, u[e])+1;
    }
    int union_find(std::vector<int>& u, int e) {
        return u[e] == -1 ? e : union_find(u, u[e]);
    }
    void union_merge(std::vector<int>& u, int e1, int e2) {
        int e1_p = union_find(u, e1);
        int e2_p = union_find(u, e2);
        u[e1_p] = e1_p != e2_p ? e2_p : u[e1_p];
    }
    int treeDiameter1(vector<vector<int>>& edges) {
        int nvertices = 0;
        for(std::vector<int> edge: edges) {
            if(edge[0] > nvertices) nvertices = edge[0];
            if(edge[1] > nvertices) nvertices = edge[1];
        }
        nvertices++;
        std::vector<int> u(nvertices, -1);
        
        for(std::vector<int> edge: edges) {
            
            int e1 = union_find(u, edge[0]);
            int e2 = union_find(u, edge[1]);
            //printf("[%d %d], [%d %d] [%d %d]\n", edge[0], edge[1], e1, e2, u[e1], u[e2]);
            union_merge(u, e1, e2);
        }
        
        //for(auto uu: u) printf("%d ", uu); printf("\n");
        
        int d = union_len(u, 0);
        for(int i = 1; i < nvertices; i++) {
            d = max(d, union_len(u, i));
        }
        
        return d;
    }
    

int main() {
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{1,4},{4,5}};//{{0,1},{1,2},{0,3},{3,4},{2,5},{3,6}};
    int d = treeDiameter(edges);
    printf("d=%d\n", d);
    return 0;
}