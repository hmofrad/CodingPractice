/*
 *  Problem: Group Anagrams
 *  Compile: g++ -o groupAnagrams groupAnagrams.cpp -std=c++11 && ./groupAnagrams
 *  Execute: ./groupAnagrams
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

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &str)
{
    std::vector<std::vector<std::string>> anagrams;
    int s = str.size();
    std::vector<std::vector<int>> u;
    u.resize(s);
    
    /*
    for(int i = 0; i < s; i++)
    {
        std::string &st = str[i];
        std::sort(std::begin(st), std::end(st));
    }
    */
    
    for(int i = 0; i < s; i++)
    {
        int n = str[i].size();
        auto &uu = u[i];
        uu.resize(n);
        for(int j = 0; j < n; j++)
            uu[j] = str[i][j];
        std::sort(std::begin(uu), std::end(uu));
    }
    
    std::vector<std::vector<int>> unique;
    std::vector<std::vector<int>> ids;
    int unique_count = 0;
    /*
    int unique_count = 0;
    if(s > 1)
    {
        unique_count = 1;
        unique
    }
    */
    
    
    for(int i = 0; i < s - 1; i++)
    {
        for(int j = i + 1; j < s; j++)
        {
            auto &u1 = u[i];
            auto &u2 = u[j];
            int n1 = u1.size();
            int n2 = u2.size();
            bool the_same = true;
            for(int k = 0; k < n1; k++)
            {
                if(u1[k] != u2[k])
                {
                    the_same = false;
                    break;
                }
            }
            
            
            bool new_anagram = false;
            if(the_same)
            {
                if(unique.size() == 0)
                {
                    unique.resize(1);
                    unique[0].resize(n1);
                    for(int k = 0; k < n1; k++)
                        unique[0][k] = u1[k];  
                    unique_count++;    
                }
                else
                {
                    
                    int n = unique.size();
                    for(int k = 0; k < n; k++)
                    {
                        for(int l = 0; l < n1; l++)
                        {
                            if(u1[l] != unique[k][l])
                            {
                                new_anagram = true;
                                break;
                            }
                        }
                    }
                    if(new_anagram)
                    {
                        printf("new\n");
                        int n = unique.size();
                        unique.resize(n+1);
                        unique[n].resize(n1);
                        for(int k = 0; k < n1; k++)
                            unique[n][k] = u1[k];  
                        unique_count++;    
                    }
                        
                    
                    
                }
                    printf("%d %d %d %d %d\n", i, j, the_same, new_anagram, unique_count);
            }
        }
        printf("\n");
    }
    
    auto &u1 = u[s-1];
    int n1 = u1.size();
    bool new_anagram = false;
    int n = unique.size();
    for(int k = 0; k < n; k++)
    {
        for(int l = 0; l < n1; l++)
        {
            if(u1[l] != unique[k][l])
            {
                new_anagram = true;
                break;
            }
        }
    }
    if(new_anagram)
    {
        printf("new\n");
        int n = unique.size();
        unique.resize(n+1);
        unique[n].resize(n1);
        for(int k = 0; k < n1; k++)
            unique[n][k] = u1[k];  
        unique_count++;    
    }
    
    

    
    for(int i = 0; i < unique.size(); i++)
    {
        for(int j = 0; j < unique[i].size(); j++)
        {
            printf("%d ", unique[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
        
    
    
    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < u[i].size(); j++)
        {
            printf("%d ", u[i][j]);
        }
        printf("\n");
    }
    return(anagrams);
}

int main(int argc, char **argv)
{
    std::vector<std::string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    for(std::string &anagram : str)
        printf("%s\n", anagram.c_str());
    
    std::vector<std::vector<std::string>> res = groupAnagrams(str);
    
    for(std::string &anagram : str)
        printf("%s\n", anagram.c_str());
    
    return(0);
}