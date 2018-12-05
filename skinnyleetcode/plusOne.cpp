/*
 *  Problem: Implement Pow(x, n)
 *  Compile: g++ -o plusOne plusOne.cpp -std=c++11 && ./plusOne
 *  Execute: ./plusOne
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



std::vector<int> plusOne(std::vector<int>& digits)
{
    std::vector<int> ret;
    std::vector<int> tmp;
    int n = digits.size();
    int carry = 1;
    for(int i = n - 1; i >= 0; i--)
    {
        if(digits[i] + carry > 9)
        {
            tmp.push_back((10 - (digits[i] + carry)));
            carry = 1;
        }
        else
        {
            tmp.push_back(digits[i] + carry);
            carry = 0;
        }
    }
    if(carry)
        tmp.push_back(carry);
    
    int m = tmp.size();
    ret.resize(m);
    for(int i = 0; i < m; i++)
    {
        ret[i] = tmp[m - (i + 1)];
    }
    return(ret);    
}

int main(int argc, char **argv)
{
    std::vector<int> digits = {9, 9, 9};
    for(int i = 0; i < digits.size(); i++)
        printf("%d ", digits[i]);
    printf("\n");
    
    std::vector<int> ret = plusOne(digits);
    for(int i = 0; i < ret.size(); i++)
        printf("%d ", ret[i]);
    printf("\n");
    return(0);
}