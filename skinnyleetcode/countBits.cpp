/*
 *  Problem: https://leetcode.com/problems/counting-bits/
 *  Compile: g++ -o countBits countBits.cpp -std=c++11 && ./countBits #-fsanitize=address 
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
#include<bits/stdc++.h> 

/*
std::vector<int> countBits(int num) {
    std::vector<int> counts(num+1);
    for(int i = 0; i <= num; i++) {
        int n = i;
        int count = 0;
        while(n) {
            n &= (n-1);
            count++;
        }
        counts[i] = count;
        printf("%d\n", count);
    }
 
    return(counts);
        
}
*/

std::vector<int> countBits(int num) {
    std::vector<int> counts(num+1);
   
    int n = 0;
    while((++n) <= num) {
        //n &= (n-1);
        counts[n] = counts[n & (n-1)]+1;
        //n++;
    }
    
   /*
   int n = 1;
    while(n <= num) {
        //n &= (n-1);
        counts[n] = counts[n & (n-1)]+1;
        n++;
    }
    */
    return(counts);
        
}

int main(int argc, char **argv){
    int n = 5;
    std::vector<int> counts = countBits(n);
    for(auto& c: counts) printf("%d ", c); printf("\n");
    
    
    return(0);
}






