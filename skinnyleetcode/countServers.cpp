/*
 *  https://leetcode.com/problems/count-servers-that-communicate/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 #include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dfs(vector<vector<int>>& grid, int row, int col) {
    int nrows = grid.size();
    int ncols = nrows ? grid[0].size() : 0;
    if(row < 0 or row >= nrows or col < 0 or col >= ncols) return 0;
    if(grid[row][col] == 0) return 0;
    grid[row][col] = 0;
    
    return 1 + dfs(grid, row,col+1) + 
               dfs(grid, row,col-1) + 
               dfs(grid, row-1,col) + 
               dfs(grid, row+1,col);
}
int countServers(vector<vector<int>>& grid) {
    int nrows = grid.size();
    int ncols = nrows ? grid[0].size() : 0;
    int nnodes = 0;
    /*
    for(int i = 0; i < nrows; i++) {
        for(int j = 0; j < ncols; j++) {
            if(grid[i][j]) {int n = dfs(grid, i, j); nnodes += n>1 ? n : 0;}
        }
    }
    */
    for(int i = 0; i < nrows; i++) {
        std::vector<int> nodes;
        for(int j = 0; j < ncols; j++) {
            if(grid[i][j]) nodes.push_back(j);
        }
        if(nodes.size() > 1) {
            nnodes += nodes.size();
            for(int j: nodes) {
                grid[i][j]=2;
            }
        }
    }
    
    for(int i = 0; i < nrows; i++) {
        for(int j = 0; j < ncols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    for(int j = 0; j < ncols; j++) {
        std::vector<int> nodes;
        for(int i = 0; i < nrows; i++) {
            if(grid[i][j]) nodes.push_back(i);
        }
        if(nodes.size() > 1) {
            for(int i: nodes) {
                printf("%d ", i);
                if(grid[i][j] != 2) nnodes++;
            }
            printf("\n");
        }
    }
    
    
    
    return nnodes;
}



int main() {
    vector<vector<int>> grid = {{1,0},{1,1}};
    int c = countServers(grid);
    printf("Count = %d\n", c);
    
}