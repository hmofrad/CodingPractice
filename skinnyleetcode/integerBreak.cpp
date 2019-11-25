/*
 *  Problem: https://leetcode.com/problems/integer-break/
 *  Compile: g++ -o integerBreak integerBreak.cpp -std=c++11 && ./integerBreak #-fsanitize=address 
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

int integerBreak(int n) {
    int prod = 0;
    std::vector<int> dp(n+1);
    
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        //int mid = (i/2) + 1;
        int ans = 0;
        for(int j = 1; j < i; j++) {
            dp[i] = std::max(std::max(dp[i],(j*(i-j))), dp[j]*(i-j));
            //ans = std::max(ans, std::max(dp[j], j) * std::max(dp[i-j], i-j));
        }
        //dp[i] = ans;
       for(auto& d: dp) printf("%2d ", d); printf(": %2d\n", i);    
        //if(i> 5) break;
    }
    
    
    //for(auto& d: dp) printf("%d ", d); printf("\n");
    return(dp[n]);
}

int main(int argc, char **argv){
    
    int input = 10;
    int output = integerBreak(input);
    printf("integerBreak(%d) = %d\n",input, output);
    
    return(0);
}






