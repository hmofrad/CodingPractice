/*
 *  Problem: combine
 *  Compile: g++ -o combine combine.cpp -std=c++11 && ./combine
 *  Execute: ./combine
 *  (c) Mohammad Mofrad, 2018
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


/*
void combine_me(int n, int k, int d) {
    if(d == k) {
        for(int j = i+1; j <= n; j++) {
        printf
    }
    combine_me(n, k, d + 1);
}
*/

std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> combinations;
    for(int i = 1; i < n; i++) {
        for(int j = i+1; j <= n; j++) {
            printf("%d %d\n", i, j);
        }
    }
    return(combinations);
}

int main(int argc, char **argv) {
    int n = 4;
    int k = 2;
    std::vector<std::vector<int>> combinations = combine(n,k);
    
    int p = combinations.size();
    int q = 0;
    if(p)
        q = combinations[0].size();
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < q; j++) {
            printf("%d ", combinations[i][j]);
        }
        printf("\n");
    }
    
    return(0);
}