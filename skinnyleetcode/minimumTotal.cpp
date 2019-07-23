/*
 *  Compile & Execute: g++ -o minimumTotal minimumTotal.cpp -std=c++11 && ./minimumTotal
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

int minimumTotal(std::vector<std::vector<int>>& triangle) {
    int path = 0;
    int m = triangle.size();
    for(int i = 0; i < m; i++) {
        std::vector<int>& t = triangle[i];
        for(int j: t) {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    std::vector<std::vector<int>> paths(m);
    for(int i = 0; i < m; i++) {
        
        //pathes[i].push_back()
    }
    
    
    return(0);
}


int main(int argc, char** argv) {
    std::vector<std::vector<int>> triangle = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    printf("minimumTotal=%d\n", minimumTotal(triangle));
    return(0);
}