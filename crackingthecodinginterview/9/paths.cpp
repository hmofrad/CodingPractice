/*
 *  Cracking the coding interview: Problem 9.2: Possible path from (0,0) to (x,y)
 *  Compile & run: g++ -o paths paths.cpp -g -Wall -std=c++11 -fsanitize=address  && ./paths
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>


//int ways(std::vector<std::vector<int>> grid, uint32_t i, uint32_t j) {
//    if((grid.size()-1 == i) and grid[0].size()-1 == i)
//}

int factorial(int n) {
    if(n == 1 || n == 0) {
        return(1);
    }
    
    return(factorial(n-1) * n);
}

int paths(std::vector<std::vector<int>> grid) {
    //printf("%d\n", factorial(3));
    //return(0);
    return(factorial(grid.size() + grid[0].size()) / (factorial(grid.size()) * factorial(grid[0].size())));
}



int main(int argc, char** argv) {
    std::vector<std::vector<int>> grid = {{1, 1,1,1}, {1,1,1,1}, {1,1,1,1}};
    int n = paths(grid);
    printf("paths=%d\n", n);
    
    return(0);
}