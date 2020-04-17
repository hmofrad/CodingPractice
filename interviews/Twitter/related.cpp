/*
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool dfs(vector<string>& related, std::vector<bool>& visited, int row, int col) {
    int nrows = related.size();
    int ncols = (nrows) ? related[0].size() : false;
    if(row < 0 or row >= nrows) return false;
    if(col < 0 or col >= ncols) return false;
    if(related[row][col] == '0') return false;
    if(visited[row]) return false;
    visited[row] = true;
    related[row][col] == '0';
    
    for(int j = 0; j < ncols; j++) {
        if(related[row][j] and not visited[j]) {
            dfs(related, visited, j, row);
        }
    }
    
    return(true);
}

int countGroups(vector<string> related) {
    
    int nrows = related.size();
    int ncols = (nrows) ? related[0].size() : 0;
    
    printf("%d %d\n", nrows, ncols);
    for(int i = 0 ; i < nrows; i++) {
        for(int j = 0 ; j < ncols; j++) {
            printf("%c ", related[i][j]);
        }
        printf("\n");
    }
    std::vector<bool> visited(nrows);
    int groups = 0;
    for(int i = 0 ; i < nrows; i++) {
        for(int j = 0; j < ncols; j++) {
            groups += dfs(related, visited, i, j);
        }
    }
    

    
    return groups;
}


int main() {
    //std::vector<std::string> related = {"1100", "1110", "0110", "0001"};
    //std::vector<std::string> related = {"110", "110", "001"};
    std::vector<std::string> related = {"1100", "1110", "0110", "0001"};
    int r = countGroups(related);
    printf("\n>>>%d\n", r);
}