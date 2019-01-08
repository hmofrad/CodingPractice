/*
 *  Problem: Implement Pow(x, n)
 *  Compile: g++ -o maxSubArray maxSubArray.cpp -std=c++11 && ./maxSubArray
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

int maxSubArray(std::vector<int>& nums)
{
    int ret = 0;
    int n = nums.size();
    if(!n)
        return(0);
    int s = 0;
    for(int i = 0; i < n; i++)
        printf("%d ", nums[i]);
    printf("\n");
    
    int r = 0;
    int m = n;
    int max =  -2147483647;
    int count = 0;
    
    for(int i = 0; i < n; i++)
    {
        std::vector<int> sums(n);
        for(int j = 0; j < m; j++)
        {
            r = n - m + 1;
            for(int k = j; k < j + r; k++)
                sums[j] += nums[k];
            if(sums[j] > max)
            {
                max = sums[j];
                count = i;
            }
        }
        m--;
    }
    
    return(max);
}

int maxSubArray1(std::vector<int>& nums)
{
    int ret = 0;
    int n = nums.size();
    if(!n)
        return(0);
    int s = 0;
    for(int i = 0; i < n; i++)
        printf("%d ", nums[i]);
    printf("\n");
    
    int r = 0;
    int l = 0;
    int m = n;
    int max =  -2147483647;
    int count = 0;
    
    std::vector<int> sums(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
                l = i + j;
                r = n - m + 1;
                for(int k = l; k < j + r; k++)
                    sums[j] += nums[k];
                
                if(sums[j] > max)
                {
                    max = sums[j];
                    count = i;
                }
        }
        m--;
        l++;
    }
    
    return(max);
}

int main(int argc, char **argv)
{
    std::vector<int> input = {-2, 1, -3 , 4, -1, 2, 1, -5, 4};
    //std::vector<int> input = {};
    printf("maxSubArray=%d\n", maxSubArray1(input));    
    return(0);
}