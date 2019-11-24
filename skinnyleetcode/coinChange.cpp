/*
 *  Problem: https://leetcode.com/problems/coin-change/
 *  Compile: g++ -o coinChange coinChange.cpp -std=c++11 && ./coinChange #-fsanitize=address 
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
int coinChange(std::vector<int>& coins, int amount) {

    std::sort(coins.begin(), coins.end());
    //for(auto& i: coins) printf("%d\n", i);
    int dividend = amount;
    int num = 0;
    int i = coins.size() - 1;
    
    int quotient = 0;
    int remainder = 0;
    while(i>=0) {
        auto divisor = coins[i];
        quotient  = dividend / divisor;
        remainder = dividend % divisor;
        num += quotient;
        printf("%d %d %d %d %d\n", i, dividend, divisor, quotient, remainder);
        dividend = remainder;
        i--;
    }
    printf("%d\n", dividend);
          
    
    return((dividend) ? -1 : num);    
}
*/

int coinChange(std::vector<int>& coins, int amount) {
    
    if(not coins.size()) return(- 1);
    if(not amount) return(0);
    
    std::vector<int> dp(amount+1);
    dp[0] = 0;
    
    for(int i = 1; i <= amount; i++) {
        dp[i] = -1;
        for(int j = 0; j < coins.size(); j++) {
            int k = i - coins[j];
            if(k >= 0) {
                if(dp[k] >= 0) {
                dp[i] = (dp[i] == -1) ? dp[k] + 1: std::min(dp[k]+1, dp[i]);
                }
            }                
        }
    }
    
    
    for(int d: dp) {
        printf("%d ", d);
    }
    printf("\n");
    
    
    return(dp[amount]);
}

int main(int argc, char **argv){
    std::vector<int> coins = {1, 2, 5};
    int amount = 11;
    int output = coinChange(coins, amount);
    printf("coinChange(%d) = %d\n",amount, output);
    
    return(0);
}






