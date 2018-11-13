/*
 *  Problem: Divide Two Integers (https://leetcode.com/problems/divide-two-integers/)
 *  Compile: g++ -o divide divide.cpp && ./divide
 *  Execute: ./divide
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

int divide(int dividend, int divisor)
{
    int dividend_ = dividend;
    int divisor_ = divisor;
    bool change_sign = false;
    
        

    if (dividend_ > 0 and divisor_ < 0)
    {
        if(divisor_ == -2147483648)
            divisor_ = 2147483647;
        else
            divisor_ = -divisor_;
        
        change_sign = true;
    }
    else if(dividend_ < 0 and divisor_ < 0)
    {
        if(dividend_ == -2147483648)
            dividend_ = 2147483647;
        else
            dividend_ = -dividend_;
        
        if(divisor_ == -2147483648)
            divisor_ = 2147483647;
        else
            divisor_ = -divisor_;
    }
    if(dividend_ < 0 and divisor_ > 0)
    {
        if(dividend_ == -2147483648)
            dividend_ = 2147483647;
        else
            dividend_ = -dividend_;
        
        change_sign = true;
    }

    int quotient = 0;
    int div = 0;
    int temp = divisor_;
    int step = 0;
    bool first = true;
    printf("%d %d\n", divisor_, dividend_);
    for(int32_t i = 0; i < dividend_; i++)
    {
        if(i == temp - 1)
        {
            if(first)
            {
                step = i + 1;
                first = false;
            }
            //printf("%d %d %d\n", i, div, temp);

            quotient++;
            temp += step;
        }
    }
    printf("%d\n", quotient);
    
    if(change_sign)
        quotient = -quotient;
    
    return(quotient);
}
int main(int argc, char **argv)
{
    int dividend = -2147483648;
    int divisor = -1; 
    int ret = divide(dividend, divisor);
    
    printf("Quotient=%d\n", ret);
    return(0);
}