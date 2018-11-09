/*
 *  Problem: Find First and Last Position of Element in Sorted Array (https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
 *  Compile: g++ -o searchRange searchRange.cpp && ./searchRange
 *  Execute: ./searchRange
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

std::vector<int> searchRange(std::vector<int>& nums, int target)
{
    std::vector<int> ret(2, -1);
    int size = nums.size();    
    
    if(size < 1)
        return(ret);
    /*
    else if(size == 1)
    {
        if(
    }
    */
    
    int i = 0;
    int i1 = 0;
    int i2 = size - 1;
    //for(uint32_t i = 0; i < size; i++)
    while(i1 <= i2 and (ret[0] != i1 or ret[1] != i2))
    {
        if(nums[i1] == target)
        {
            ret[0] = i1;
            //i2--;
        }
        else
        {
            i1++;
            i++;
        }
        if(nums[i2] == target)
        {
            ret[1] = i2;
            //i1++;
        }
        else
        {
            i2--;
            i++;
        }
        //printf("%d %d %d %d\n", i, i1, i2, size);
        //else
        //{
            //i1++;
            //i2--;
        //}
    }     
    if(ret[0] == -1 or ret[1] == -1)
    {
        ret[0] = -1;
        ret[1] = -1;
    }

    return(ret);
}



int main(int argc, char **argv)
{    

    printf("Hello, World\n");
    /*
    std::vector<int> nums;
    
    int n = 10;
    for(uint32_t i = 0; i < n; i++)
        nums.push_back(i);
    nums[5] = 4;
    nums[8] = 7;
    */
    
    std::vector<int> nums(7);
    nums[0] = 5;
    nums[1] = 7;
    nums[2] = 7;
    nums[3] = 6;
    nums[4] = 8;
    nums[5] = 8;
    nums[6] = 10;
    /*
    std::vector<int> nums(1);
    nums[0] = 1;
    */
    for(uint32_t i = 0; i < nums.size(); i++)
        printf("%d ", nums[i]);
    printf("\n");
    
    int target = 6;
    std::vector<int> res = searchRange(nums, target);
    printf("[%d %d]\n", res[0], res[1]);

    return(0);
}