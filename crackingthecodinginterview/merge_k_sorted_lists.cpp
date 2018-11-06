/*
 *  Problem: Merge K sorted lists
 *  Compile: g++ -o merge_k_sorted_lists merge_k_sorted_lists.cpp -std=c++11
 *  Execute: ./merge_k_sorted_lists
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <iostream> 
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>

//struct printf("1.%d %d %d %d\n", i, pointers[i], lengths[pointers[i]], indices[pointers[i]]);

void reindex(uint32_t &num_pointers, std::vector<int32_t> &pointers, std::vector<int32_t> &indices, std::vector<int32_t> &lengths)
{
   int n;
    for(uint32_t i = 0; i < num_pointers; i++)
    {
        //n = num_pointers;
        //printf("1.%d %d %d %d\n", i, pointers[i], lengths[pointers[i]], indices[pointers[i]]);
        if(lengths[pointers[i]] == indices[pointers[i]])
        //if(not lengths[pointers[i]] and pointers[pointers[i]] != -1)
        {
            for(uint32_t j = i; j < num_pointers - 1; j++)  
            {
                pointers[j] = pointers[j+1];
                lengths[pointers[j+1]] = lengths[pointers[j+1]];
                indices[pointers[j+1]] = indices[pointers[j+1]];
            }
            //pointers[num_pointers - 1] = -1;
            //lengths[pointers[num_pointers - 1]] = 0;
            num_pointers--;
        }
        //printf("2.%d %d %d %d\n", i, pointers[i], lengths[pointers[i]], indices[pointers[i]]);
    }
    //num_pointers = n;
}

void sort(uint32_t k, std::vector<std::vector<uint32_t>> &arr)
{
    uint32_t length = 0;
    for(uint32_t i = 0; i < k; i++)
        length += arr[i].size();
    std::vector<uint32_t> out(length);
    uint32_t num_pointers = k;
    std::vector<int32_t> pointers(k);
    std::vector<int32_t> indices(k);
    std::vector<int32_t> lengths(k);
    
    for(uint32_t i = 0; i < k; i++)
    {
        lengths[i] = arr[i].size();
        pointers[i] = i;
        indices[i] = 0;
        /*
        if(lengths[i] == 0)
        {
            pointers[i] = -1;
            //num_pointers--;
        }
        */
        
    }
    
    
    for(uint32_t i = 0; i < k; i++)
        printf("[(%d) %d %d %d] ", i, pointers[i], indices[pointers[i]], lengths[pointers[i]]);
    printf("\n");
    
    /*
    for(uint32_t i = 0; i < k; i++)
    {
        if(not lengths[pointers[i]] and pointers[pointers[i]] != -1)
        {
            for(uint32_t j = i; j < num_pointers - 1; j++)
            {
                pointers[j] = pointers[j+1];
                lengths[pointers[j+1]] = lengths[pointers[j+1]];
                indices[pointers[j+1]] = indices[pointers[j+1]];
            }
            pointers[num_pointers - 1] = -1;
            lengths[pointers[num_pointers - 1]] = 0;
            num_pointers--;
        }
    }
    */
    /*
    for(uint32_t i = 0; i < k; i++)
        printf("[(%d) %d %d %d] ", i, pointers[i], indices[pointers[i]], lengths[pointers[i]]);
    printf("\n");
    */
    reindex(num_pointers, pointers, indices, lengths);
    for(uint32_t i = 0; i < num_pointers; i++)
        printf("[(%d) %d %d %d] ", i, pointers[i], indices[pointers[i]], lengths[pointers[i]]);
    printf("\n");
    

    
    
   // while(num_pointers > 1)
    //{
        
        int min = 2147483647;
        int ptr = -1;
        int min_idx = -1;
        int out_ptr = 0;
        std::vector<int> min_val;
        std::vector<int> min_ptr;
        for(uint32_t i = 0; i < num_pointers - 1; i++)
        {
            int j = pointers[i];
            int k = pointers[i+1];

            if(lengths[j] and lengths[k])
            {
                if(arr[j][indices[j]] < arr[k][indices[k]])
                {
                    min_val.push_back(arr[j][indices[j]]);
                    min_ptr.push_back(j);
                }
                else if(arr[j][indices[j]] > arr[k][indices[k]])
                {
                    min_val.push_back(arr[k][indices[k]]);
                    min_ptr.push_back(k);
                }
                else if(arr[j][indices[j]] == arr[k][indices[k]])
                {
                    min_val.push_back(arr[j][indices[j]]);
                    min_ptr.push_back(j);
                    
                    min_val.push_back(arr[k][indices[k]]);
                    min_ptr.push_back(k);
                    
                    //min_val = arr[k][indices[k]];
                    //min_ptr = k;

                    //lengths[k]--;
                }
                //else
                //{
                    //min_val.push_back(arr[j][indices[j]]);
                    min_ptr.push_back(k);
                //}
            }
            /*
            else if(lengths[j] and not lengths[k])
            {
                min_val = arr[j][indices[j]];
                min_ptr = j;
                //lengths[j]--;
            }
            else if(not lengths[j] and lengths[k])
            {
                min_val = arr[k][indices[k]];
                min_ptr = k;
                //lengths[k]--;
            }
            */

            if(min_val[0] <= min)
            {
                min = min_val;
                ptr = min_ptr;  
            }
            //printf("i=%d p=%d v=%d\n", i, pointers[i], arr[i][pointers[i]]);
        }
        for(uint32_t l = 0; l < min_ptr.size(); l++)
        {
            printf("%d %d %d\n", pointers[l], indices[l], lengths[l]);
                
        }
        min_ptr.clear();
        min_val.clear();
        
        /*
        //printf("%d ", min);
        //printf("min=%d, %d %d %d\n", min, ptr, indices[ptr], num_pointers);
        out[out_ptr] = min;
        //if((out_ptr + 1) < length)
        out_ptr++;
        //if((indices[ptr] + 1) < lengths[ptr])
        indices[ptr]++;
        //else
        if(lengths[ptr] == indices[ptr])
        {
            reindex(num_pointers, pointers, indices, lengths);
            //break;
        }
        */
   // }
    
    //for(uint32_t i = indices[pointers[0]]; i < lengths[pointers[0]]; i++)
      //  printf("%d ", arr[pointers[0]][i]);
    //printf("\n");
    
    
    

        
}

void print(std::string str, std::vector<uint32_t> &arr)
{
    printf("%s: ", str.c_str());
    for(uint32_t i = 0; i < arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char **argv)
{
    uint32_t k = 5;
    std::vector<std::vector<uint32_t>> arr(k);
    for(uint32_t i = 0; i < k-1; i++)
    {
        std::vector<uint32_t> &a = arr[i];
        for(uint32_t j = i; j < i * 5; j++)    
            a.push_back(j);
        print("arr" + 0, a);
    }
    sort(k, arr);
}