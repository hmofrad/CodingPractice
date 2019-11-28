/*
 * Cracking the coding interview: Problem 3.1: How to use a single array to implement three stacks
 * Compile and run: g++ -o 3stacks 3stacks.cpp -g -Wall -Werror && ./3stacks
 * (c) Mohammad Hasanzadeh mofrad, 2019
 * (e) m.hasanzadeh.mofrad@gmail.com
*/

#include <iostream> 
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>


int main(int argc, char **argv)
{
    uint32_t NUM_STACKS = 3;
    std::vector<std::vector<uint32_t> > input_array;
    input_array.resize(NUM_STACKS);
    std::vector<uint32_t> output_array;
    
    for(uint32_t i = 0; i < NUM_STACKS; i++)
    {
        uint32_t num = NUM_STACKS*(i+1);
        for(uint32_t j = 0; j < num; j++)
        {
            input_array[i].push_back(i + rand() % num);
        }
    }

    for(uint32_t i = 0; i < NUM_STACKS; i++)
    {
        printf("%d: ", i);
        for(uint32_t j = 0; j < input_array[i].size(); j++)
        {
            printf("%d ", input_array[i][j]);
        }
        printf("\n");
    }
    
    uint32_t stack_size = 0;
    
    for(uint32_t i = 0; i < NUM_STACKS; i++)
    {
        stack_size += input_array[i].size();
    }
    stack_size = stack_size * 3;
    printf("size=%d\n", stack_size);
    
    for(uint32_t i = 0; i < NUM_STACKS; i++)
    {
        for(uint32_t j = 0; j < input_array[i].size(); j++)
        {
            output_array.push_back(input_array[i][j]);
            output_array.push_back(i);
        }
        input_array[i].clear();
    }
    
    for(uint32_t i = 0; i < output_array.size(); i++)
    {
        printf("%d ", output_array[i]);
    }
    printf("\n");
    
    for(uint32_t i = output_array.size(); i > 1; i = i - 2)
    {
        uint32_t stack_idx = output_array[i-1];
        input_array[stack_idx].push_back(output_array[i-2]);
        printf("[%d %d %d]\n", i, output_array[i-1], output_array[i-2]);
    }
    output_array.clear();

    
    for(uint32_t i = 0; i < NUM_STACKS; i++)
    {
        printf("%d: ", i);
        for(uint32_t j = 0; j < input_array[i].size(); j++)
        {
            printf("%d ", input_array[i][j]);
        }
        printf("\n");
    }
}