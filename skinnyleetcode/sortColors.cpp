/*
 *  Problem: Implement Pow(x, n)
 *  Compile: g++ -o sortColors sortColors.cpp -std=c++11 && ./sortColors
 *  Execute: ./sortColors
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


void sortColors(std::vector<int>& nums)
{
    int m = nums.size();
    for(int i = 0; i < m - 1; i++)
    {
        for(int j = i+1; j < m; j++)
        {
            if(nums[i] > nums[j])
            {
                std::swap(nums[i], nums[j]);
                //int t = nums[i];
                //nums[i] = nums[j];
                //nums[j] = t;
            }
        }
    }
        
}

int main(int argc, char **argv)
{
    int m = 6;
    std::vector<int> nums = {2,0,2,1,1,0};
    
    for(int i = 0; i < m; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    sortColors(nums);
    
    for(int i = 0; i < m; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    return(0);
}