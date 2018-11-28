/*
 *  Problem: Implement Pow(x, n)
 *  Compile: g++ -o myPow myPow.cpp -std=c++11 && ./myPow
 *  Execute: ./myPow
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

double mult(double x, int n)
{
    double ret = x;
    for(int i = 1; i < n; i++)
    {
        ret *= x;
    }
    return(ret);
}

double myPow(double x, int n)
{
    double ret = 0.0;
    if(n == 0)
        ret = 1.0;
    else if(n >= 1)
    {
        ret = x;
        for(int i = 1; i < n; i++)
        {
            ret *= x;
        }
    }
    else // n <= -1
    {
        if((x > 0) or (x < 0))
        {
            x = 1/x;
            ret = x;
            for(int i = 1; i < -n; i++)
            {
                ret *= x;
            }
        }
    }
    return(ret);
}

int main(int argc, char **argv)
{
    double x = -2.0;
    int n = -3;
    printf("Pow(%f, %d)=%f\n", x, n, myPow(x,n));
    return(0);
}