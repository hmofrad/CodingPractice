/*
 *  Problem: Implement Pow(x, n)
 *  Compile: g++ -o canJump canJump.cpp -std=c++11 && ./canJump
 *  Execute: ./canJump
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

bool delve(std::vector<int> &nums, int idx)
{
    bool can = false;
    if(nums.size() <= idx)
    {
        if(idx == nums.size())
        {
            
            printf("Done\n");
            return (true);
        }
        else
        {
            printf("Not done\n");
            return (false);
        }
    }  
    else
    {
        printf("11.idx=%d\n", idx);
        if(nums[idx] == 0)
        {
            if(idx + 1 == nums.size())
                return(true);
            else
                return(false);
            
        }        

        for(int i = 1; i <= nums[idx]; i++)
        //for(int i = 0; i <= nums[idx]; i++)
        {
            printf("1.idx=%d,i=%d\n", idx, i);

                
            can = delve(nums, idx + i);
            printf("2.idx=%d,i=%dc=%d\n", idx, i, can==true);
            if(can)
                return(can);
        }
        printf("2.idx=%d\n", idx);
    }
    return(can);
}

bool canJump(std::vector<int>& nums)
{
    bool can = false;
    int n = nums.size();
    //if(nums.size() == 1 and nums[0] == 0)
    //    return(true);
    can = delve(nums, 0);
    //std::cout << can << std::endl;
    //for(int i = 1; i <= nums[0]; i++)
    //{
    //    printf("i=%d\n", i);
        
    //}
    
    
    return(can);
}

int main(int argc, char **argv)
{
    int n = 5;
    std::vector<int> nums(n); 
    nums = {2, 3, 1, 1, 4};
    
    //int n = 3;
    //std::vector<int> nums(n);
    //nums = {2, 0, 0};
    
    for(int i = 0; i < n; i++)
        printf("%d ", nums[i]);
    printf("\n");
    
    printf("canJump=%d %d\n", canJump(nums), false);
    

    return(0);
}