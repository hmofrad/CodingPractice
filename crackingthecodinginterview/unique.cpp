/*
 *  Problem:  Implement an algorithm to determine if a string has all unique characters
 *  Compile: g++ -o unique unique.cpp -g -Wall -Werror
 *  Execute: ./unique
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream> 
#include <stdlib.h>
#include <stdio.h>

bool unique(std::string str)
{
    bool cmp = true;
    int sz = str.size();
    for(int i = 0; i < sz - 1; i++)
    {
        for(int j = i + 1; j < sz; j++)
        {
            if(str[i] == str[j])
            {
                cmp = false;
                break;
            }
        }
        if(not cmp)
            break;
    }
    return(cmp);
}
 
int main(int argc, char **argv)
{
    if(argc != 2)
        exit(1);
    printf("%s: unique? %d\n", argv[1], unique(argv[1]));
    return(0);
}