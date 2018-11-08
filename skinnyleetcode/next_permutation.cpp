/*
 *  Problem: Next permutation (https://leetcode.com/problems/next-permutation/)
 *  Compile: g++ -o next_permutation next_permutation.cpp && ./next_permutation
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
    for(int i = 0; i < nums.size(); i++)
    {
        
        int v = nums[i];
        printf("%d,", v);
        int next_len = nums.size() - 1;
        if(next_len)
        {
            std::vector<int> next;
            next.resize(next_len);
            int j = 0;
            for(int k = 0; k < nums.size(); k++)
            {
                int v_next = nums[k];
                if(v != v_next)
                {
                    next[j] = v_next;
                    j++;
                }
            }
            //printf("%d,", v);
            permutation(next);
        }
        else
           printf("\n");
    }
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