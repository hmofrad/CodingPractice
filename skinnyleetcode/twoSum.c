/*
 *  Problem: twoSum (https://leetcode.com/problems/two-sum/description/)
 *  Compile: gcc -o twoSum twoSum.c -g -Wall -Werror 
 *  Run ./twoSum
 *  (c) Mohammad H-Mofrad, 2017
 *  (e) mohammad.hmofrad@pitt.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target) {
    int i = 0;
    int j = 0;
    int *returned_nums = NULL;
    for(i = 0; i < numsSize - 1; i++)
    {
        for(j = i + 1; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                returned_nums = malloc(2 * sizeof(int));
                memset(returned_nums, 0, 2 * sizeof(int));
                returned_nums[0] = i;
                returned_nums[1] = j;
                break;
            }
        }
    }
    return(returned_nums);
}

int main(int argc, char *argv[])
{
    
    int numSize = 3;
    int nums[numSize];
    nums[0] = 3;
    nums[1] = 2;
    nums[2] = 4; 
    int target = 6;
    int *result = twoSum(nums, numSize, target);
    free(result);
    printf("arr[%d] + arr[%d] == %d\n", result[0], result[1], target);
    return(0);
}

