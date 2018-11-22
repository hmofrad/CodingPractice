/*
 *  Problem: Permutation sequence
 *  Compile: g++ -o getPermutation getPermutation.cpp && ./getPermutation
 *  Execute: ./getPermutation
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

//std::vector<std::vector<int>> 
void permutations(std::vector<int> seq, int l, int r)
{
    //printf("%d %d %d\n", seq[0], l, r);
    if(l == r)
    {
        for(int i = 0; i < seq.size(); i++)
            printf("%d ", seq[i]);
        printf("\n");
    }
    else
    {
        for(int i = l; i <= r; i++)
        {
            std::swap(seq[l], seq[i]);
            permutations(seq, l+1, r);
            std::swap(seq[l], seq[i]);
        }
        
    }
    //std::vector<std::string> perms;
    /*
    if(n == 1)
    {
        printf("%d\n", n);
        return(perms);
    }
    else
    {
        permutations(n-1);
        printf("%d\n", n);
    }
    */
    //return(perms);
}

std::string getPermutation(int n, int k)
{
    std::vector<int> seq;
    for(int i = 1; i <= n; i++)
        seq.push_back(i);
    
    //std::vector<std::vector<int>> perms = 
    permutations(seq, 0, n-1);
    std::string perm = "0";
    return(perm);
}

int main(int argc, char **argv)
{
    
    int n = 3; 
    int k = 3; 
    std::string perm = getPermutation(n, k);
    printf("getPermutation(n=3, k=3)=%s\n", perm.c_str());
    return(0);
}