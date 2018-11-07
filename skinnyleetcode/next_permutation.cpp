/*
 *  Problem: Next permutation (https://leetcode.com/problems/next-permutation/)
 *  Compile: g++ -o next_permutation next_permutation.cpp && ./next_permutation -g -Wall -Werror
 *  Execute: ./next_permutation
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums)
    {
        
        
    }
};

void permutation(std::vector<int>& nums)
{
    //if(nums.size() >= 1)
    //{
    for(int i = 0; i < nums.size(); i++)
    {
        
        int v = nums[i];
        //printf("%d %d %lu\n ", i, v, nums.size());
        std::vector<int> next;
        int next_len = nums.size() - 1;
        //printf(">>>>>%d %d %lu\n", next_len, i, nums.size());
        //next.resize(next_len);
        if(next_len > 0)
            next.resize(next_len);
        /*
        else
        {
            printf("%d\n", v);
            return;
        }
        */
        
        int j = 0;
        for(int k = 0; k < nums.size(); k++)
        {
            int v_next = nums[k];
            if(v != v_next)
            {
                //next.push_back(v_next);
                next[j] = v_next;
                //printf("[%d] ", next[j]);
                j++;
            }
        }
        
        
        if(next.size())
        {
            printf("%d ", v);
            permutation(next);
        }
        else
            printf("%d\n ", v);    
        
        
        //if(next.size() > 1)
            /*
        if(next_len > 1)
        {
            permutation(next);
            printf("<%d> ", v);
        }
        else
        {
            printf("%d\n", next[0]);
            //return;
        }
        */
    }
    //}
   // else
    //    return;
        
    
}
/*
void nextPermutation(std::vector<int>& nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        printf("");
    }
}
*/
int main(int argc, char **argv)
{    
   // printf("HEllo\n");
    
    std::vector<int> nums(3);
    nums[0] = 1; nums[1] = 2; nums[2] = 3;
    permutation(nums);
    return(0);
}