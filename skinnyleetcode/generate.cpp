/*
 *  Compile & Execute: g++ -o generate generate.cpp -std=c++11 && ./generate
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <string.h>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> pascals_triangle;
    int m = 0;
    int n = numRows;
    
    if(n) {
        pascals_triangle.resize(numRows);
        pascals_triangle[0].push_back(1);
    }
    else
        return(pascals_triangle);
        
    for(int i = 1; i < n; i++) {
        auto& row = pascals_triangle[i];
        for(int j = 0; j < i+1; j++) {
            //if(j >
            //row.push_back(pascals_triangle[i-1]
            if(j%i+1 == 1)
                row.push_back(1);
            else
                row.push_back((pascals_triangle[i-1][j-1] + pascals_triangle[i-1][j]));
            printf("[i=%d j=%d %d]", i, j, j%i+1);
        }
        printf("\n");
    }
    return(pascals_triangle);
    
}


int main(int argc, char** argv) {
    int numRows = 5;
    std::vector<std::vector<int>> pascals_triangle = generate(numRows);
    int m = pascals_triangle.size();
    int n = 0;
    for (int i = 0; i < m; i++) {
        auto& row = pascals_triangle[i];
        n = row.size();
        for (int j = 0; j < n; j++) {    
            printf("%d", row[j]);
        }
        printf("\n");
    }
    
    
    return(0);
}