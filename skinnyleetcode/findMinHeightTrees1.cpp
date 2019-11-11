    /*
 *  Problem: https://leetcode.com/problems/minimum-height-trees/
 *  Compile: g++ -o findMinHeightTrees1 findMinHeightTrees1.cpp -std=c++11 && ./findMinHeightTrees1 #-fsanitize=address 
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
#include <unordered_set>
#include <stack>
#include <numeric>
#include <map>
#include <cmath>
#include <unordered_map>

std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
    std::vector<int> roots;
    std::vector<std::vector<int>> A(n, std::vector<int>()); 
    
    for(int i = 0; i < edges.size(); i++) {
        A[edges[i][0]].push_back(edges[i][1]);
        A[edges[i][1]].push_back(edges[i][0]);
    }
    
    std::vector<int> leaves;
    
    for(int i = 0; i < n; i++) {
        auto a = A[i];
        printf("%d: ", i);
        for(int j = 0; j < a.size(); j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
        if(a.size() <= 1) {
            leaves.push_back(i);
        }
    }
    
    for(auto l: leaves)
        printf("%d ", l);
    printf("\n\n");
    
    for(int i = 0; i < leaves.size(); i++) {
        printf("%d- ", i);
        for(int j = 0; j < A[leaves[i]].size(); j++) {    
            printf("-%d, ", j);
            for(int k = 0; k < A[j].size(); k++) {
                printf("[%d, %d %d] ", k, A[j][k], leaves[i]);
                if(A[j][k] == leaves[i])
                    A[j].erase(A[j].begin() + k);
            }
        }
        printf("\n");
    }
    
    for(int i = 0; i < n; i++) {
        auto a = A[i];
        printf("%d: ", i);
        for(int j = 0; j < a.size(); j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
    
    
    /*
    for(auto l: leaves)
        printf("%d ", l);
    printf("\n");
    */
    
    
    return(roots);
}

int main(int argc, char **argv){
    std::vector<std::vector<int>> edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    int n = 6;
    
    for(auto edge: edges) {
        for(auto e: edge)
            printf("%d ", e);
        printf("\n");
    }
    
    std::vector<int> roots = findMinHeightTrees(n, edges);
    
    for(auto r: roots)
        printf("%d ", r);
    printf("\n");
    
    return(0);
}






