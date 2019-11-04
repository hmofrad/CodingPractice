    /*
 *  Problem: https://leetcode.com/problems/perfect-squares/
 *  Compile: g++ -o numSquares numSquares.cpp -std=c++11 && ./numSquares
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

/*
int numSquares(int n) {
    int ret = 0;
    int smallest_sq = 1;
    int sq = std::sqrt(n);
    std::vector<int> rets;
    for(int i = sq; i >= 1; i--) {
        
        int j = i;
        int k = i;
        while(k >= 1) {
            int largest_sq = (j * j);
            int v = largest_sq;
            ret = 1;
            while(v != n) {
                //printf("%d %d %d\n", v, largest_sq, ret);
                int t = v + largest_sq;
                if(t > n) {
                    j--;
                    largest_sq = j * j; 
                }
                else if(t < n) {
                    v += largest_sq;
                    ret++;
                }
                else {
                    v += largest_sq;
                    ret++;
                    break;
                }
            }
            rets.push_back(ret);
            k--;
            printf("v=%d ret = %d %d %d %d\n", v, ret, i , j, k);
        }
        
    }
    ret = *std::min_element(rets.begin(), rets.end());
    return(ret);    
}
*/


int numSquares(int n) {
     std::unordered_map<int,int> results;
    std::vector<int> squares;
        for(int i=1;i*i<=n;i++)
        {
            squares.push_back(i*i);
            printf("%d %d %d \n", i, i * i, n);
        }
        
        // O(n)
        for(int i=1;i<=n;i++)
        {
            results[i]=1+results[i-1];
            // O(√n)
            for(auto square: squares)
            {
                if(square>i) break;
                results[i]=std::min(results[i],1+results[i-square]);
                
            }
            
        
            
        }
        
        
        
        return results[n];
    }
    
int main(int argc, char **argv){
    int n = 43;
    int m = numSquares(n);
    printf("numSquares(%d)=%d\n", n, m);
    
    return(0);
}






