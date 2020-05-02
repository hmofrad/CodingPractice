/*
 *  https://leetcode.com/problems/connecting-cities-with-minimum-cost/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int union_find(std::vector<int>& u, int a) {
        return u[a] == -1 ? a : union_find(u, u[a]);
    }
    bool union_merge(std::vector<int>& u, int a, int b) {
        int u_a = union_find(u, a);
        int u_b = union_find(u, b);
        bool new_union = false;
        if(u_a != u_b) {u[u_a]=u_b; new_union = true;}
        return new_union;
    }
    bool union_check(std::vector<int>& u, int N) {
        int nmineses=1;
        for(int i = 1; i <= N; i++) {
            if(u[i]==-1) nmineses--;
        }
        return nmineses==0 ? true : false;
    }
    int minimumCost(int N, vector<vector<int>>& connections) {
        std::sort(connections.begin(), connections.end(), [](const std::vector<int> a, const std::vector<int> b) {return a[2]<b[2];});
        //for(std::vector<int>& connection: connections) {
         //   printf("%d-->%d:%d\n", connection[0], connection[1], connection[2]);
        //}
        //printf("\n");
        std::vector<int> u(N+1, -1);
        
        int min_cost = 0;
        //std::vector<bool> visited(N+1);
        for(std::vector<int>& connection: connections) {
            
            int a = connection[0];
            int b = connection[1];
            int c = connection[2];
            //printf("%d-->%d:%d\n", a, b, c);
            int u_a = union_find(u, a);
            //printf("a=%d u_a=%d\n", a, u_a);
            int u_b = union_find(u, b);
            //printf("b=%d u_b=%d\n", b, u_b);
            bool new_union = union_merge(u, u_a, u_b);
            if(new_union) {
                min_cost+=c;            
                
            }
            //printf("min_cost=%d %d\n", min_cost, union_check(u, N));
            //for(int i = 0; i <= N; i++) {
            //    printf("%d ", u[i]);
            //}
            //printf("\n");
        }
        
        //printf("%d %d\n", min_cost, union_check(u, N));
        return (union_check(u, N)) ? min_cost : -1;
        //return -1;
        /*
        std::vector<std::vector<int>> grid(N+1, std::vector<int>(N+1));
        for(std::vector<int>& connection: connections) {
            int v1=connection[0];
            int v2=connection[1];
            int c=connection[2];
            grid[v1][v2]=c;
            grid[v2][v1]=c;
        }

        for(int i = 0; i <= N; i++) {
            std::vector<bool> visited(N+1);
            int c = 0;
            min_cost = min(min_cost, dfs(grid, i, visited, 0, c, N));
        }
        return min_cost == INT_MAX ? -1 : min_cost;
        */
    }
    
    
    
    
    int dfs(std::vector<std::vector<int>>& grid, int row, std::vector<bool>& visited, int cost, int& min_cost, int N) {
        visited[row]=true;
        
        int s = std::accumulate(visited.begin(), visited.end(), 0);
        if(s==N) return cost;
        
        int path_cost=INT_MAX;
        for(int j = 0; j <= N; j++) {
            if(grid[row][j] and not visited[j]) {
                //int this_cost = dfs(grid, j, visited, cost+grid[row][j], N);
                
                path_cost = dfs(grid, j, visited, cost, min_cost, N);
                min_cost = min(min_cost, grid[row][j]);
                path_cost+=min_cost;
            }
        }
        return path_cost;
    }
    int min_cost = INT_MAX;
    int minimumCost1(int N, vector<vector<int>>& connections) {
        std::vector<std::vector<int>> grid(N+1, std::vector<int>(N+1));
        for(std::vector<int>& connection: connections) {
            int v1=connection[0];
            int v2=connection[1];
            int c=connection[2];
            grid[v1][v2]=c;
            grid[v2][v1]=c;
        }

        for(int i = 0; i <= N; i++) {
            std::vector<bool> visited(N+1);
            int c = 0;
            min_cost = min(min_cost, dfs(grid, i, visited, 0, c, N));
        }
        return min_cost == INT_MAX ? -1 : min_cost;
    }
};




