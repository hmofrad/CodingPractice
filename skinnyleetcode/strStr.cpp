/*
 *  Problem: Implement strStr() (https://leetcode.com/problems/implement-strstr/)
 *  Compile: g++ -o strStr strStr.cpp && ./strStr
 *  Execute: ./strStr
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

int strStr(std::string haystack, std::string needle)
{
    int size_h = haystack.size();
    int size_n = needle.size();
    
    if(size_h)
    {
        if(not size_n)
            return(0);
    }
    else
    {
        if(not size_n)
            return(0);
        else
            return(-1);
        
    }
    
    int num_steps = size_h / size_n;
    int ret = -1;

    if(not size_h or not size_n)
        return(0);
    printf("%d %d %d\n", size_h, size_n, num_steps);
    for(int i = 0; i < num_steps; i++)
    {
        
        int start = i*size_n;
        int end   = i*size_n + size_n;
        bool found = true;
        int k = 0;
        printf("%d %d %d\n", i, start, end);
        for(int j = start; j < end; j++)
        {
          //  printf("%d %d %c %c\n", j, k, haystack[j], needle[k]);
            if(haystack[j] != needle[k])
            {
                found = false;
                break;
            }
            k++;
        }
        if(found)
        {
            ret = start;
            break;
        }
    }
    return(ret);
}
int main(int argc, char **argv)
{    
    std::string haystack = "hello";
    std::string needle = "ll";
    int ret = strStr(haystack, needle);
    printf("[%s] [%s] [%d]\n", haystack.c_str(), needle.c_str(), ret);
    return(0);
}