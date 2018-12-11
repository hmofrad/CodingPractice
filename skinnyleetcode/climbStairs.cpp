/*
 *  Problem: Implement Pow(x, n)
 *  Compile: g++ -o climbStairs climbStairs.cpp -std=c++11 && ./climbStairs
 *  Execute: ./climbStairs
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

int climb_Stairs(int i, int n) {
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
}

int climbStairs(int n) 
{
    //if(n <= 1)
    //    return(n);
    
    int num_ways = 0;
    int step_size = 2;
    num_ways = climb_Stairs(0, n);
    //num_ways++; // 1 + .. + 1
    
    //num_ways = !(n%2) ? num_ways+1 : num_ways; // 2 + ... + 2
    
    
    
    return(num_ways);
}

int main(int argc, char **argv)
{
    int n = 3;
    printf("climbStairs(%d)=%d\n", n, climbStairs(n));
    return(0);
}