/*
 *  Cracking the coding interview: Problem 9.1: Possible ways to run up the stairs
 *  Compile & run: g++ -o countWays countWays.cpp -g -Wall && ./countWays
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>

int countWays(int n) {
    if(n < 0) return 0;
    else if(n == 0) return 1;
    else return countWays(n-1) + countWays(n-2) + countWays(n-3);
}


int countWaysDP(int n, std::vector<int>& dp) {
    if(n < 0) return 0;
    else if(n == 0) return 1;
    else if (dp[n] > -1) return dp[n];
    else {
        dp[n] = countWaysDP(n-1, dp) + countWaysDP(n-2, dp) + countWaysDP(n-3, dp);
        return dp[n];
    }
}

int main(int argc, char** argv) {

    int n = 10;
    int w = countWays(n);
    printf("countWays(%d) = %d\n", n, w);
    
    std::vector<int> dp(n+1, -1);
    
    w = countWaysDP(n, dp);
    printf("countWays(%d) = %d\n", n, w);
}