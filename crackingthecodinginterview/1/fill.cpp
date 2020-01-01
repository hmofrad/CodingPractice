/*
  * Cracking the coding interview: Problem 1.7: Fill row/column if an element is zero
  * Compile and run:  g++ -o fill fill.cpp -g -Wall -std=c++11 -fsanitize=address && ./fill
  * (c) Mohammad Hasanzadeh mofrad, 2019
  * (e) m.hasanzadeh.mofrad@gmail.com
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

void print(std::vector<std::vector<char>> matrix) {
    for(auto row: matrix) {
        for(auto col: row) {
            printf("%d ", col);
        }
        printf("\n");
    }
    printf("\n");
}

void fill(std::vector<std::vector<char>>& matrix) {
    uint32_t nrows = matrix.size();
    uint32_t ncols = 0;
    if(nrows) {
        ncols = matrix[0].size();
    }
    
    std::vector<std::pair<int, int>> points;
    for(uint32_t i = 0; i < nrows; i++) {
        for(uint32_t j = 0; j < ncols; j++) {
            if(matrix[i][j]) {
                points.push_back({i,j});
            }
        }
    }
    std::vector<int> rows;
    std::vector<int> cols;
    for(auto p: points) {
        //printf("%d %d\n", p.first, p.second);
        if((std::find(rows.begin(), rows.end(), p.first) == rows.end())){
            rows.push_back(p.first);
        }
        if((std::find(cols.begin(), cols.end(), p.second) == cols.end())){
            cols.push_back(p.second);
        }
    }
    
    
    for(auto r: rows) {
        for(uint32_t j = 0; j < ncols; j++) {
            matrix[r][j] = 1;
        }
    }
    
    for(auto c: cols) {
        for(uint32_t i = 0; i < nrows; i++) {
            matrix[i][c] = 1;
        }
    }
}

int main(int argc, char* argv[]) {
    std::vector<std::vector<char>> matrix = {{0,0,0,0,0},
                                             {0,1,0,0,0},
                                             {0,0,1,0,1},
                                             {0,0,0,0,0}};
    
    print(matrix);
    
    fill(matrix);
    
    print(matrix);
    
    return(0);
}