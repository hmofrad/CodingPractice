/*
 *  Problem: Implement Pow(x, n)
 *  Compile: g++ -o lengthOfLastWord lengthOfLastWord.cpp -std=c++11 && ./lengthOfLastWord
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

int lengthOfLastWord(std::string s)
{
    int length = 0;
    int s_len = s.size();

    int n_spaces = 0;
    if(s_len)
    {
        for(int i = s_len - 1; i >= 0; i--)
        {
            if(s[i] == ' ')
                n_spaces++;
            else
                break;
            
            std::cout << s[i] << std::endl;
        }
        if(s_len > n_spaces)
        {
            int l1 = 0;
            int l2 = s_len - n_spaces;
            length = l2 - l1;
            printf("<%d %d>\n", l1, l2);
            for(int i = l2 - 1; i >= 0; i--)
            {
                if(s[i] == ' ')
                {
                    //printf("???\n");
                    l1 = i;
                    length = l2 - i - 1;
                    break;
                }
                else
                {
                    //l2
                }
                std::cout << s[i] << std::endl;
            }
        }
    }
    return(length);
    
/*    
    printf("%d %d\n", n_spaces, s_len - n_spaces);
    //exit(0);
    

    if(s.size())
    {
        for(int i = s_len - 2; i >= 0; i--)
        {
            if(s[i+1] == ' ' and s[i] == ' ')
            {
                printf("???\n");
                length = l2 - l1;
                break;
            }
            else
            {
                //l2
            }
            std::cout << s[i+1] << std::endl;
        }
        
        
    }
    
    printf("l1=%d l2=%d, %d\n", l1, l2, l2 - l1);
    
    return(length);
    */
}

int main(int argc, char **argv)
{
   // std::string s = "Hello World";
   std::string s = "a          ";
    //std::string s = "";
    
    printf("lengthOfLastWord(\"%s\")=%d\n", s.c_str(), lengthOfLastWord(s));
    

    return(0);
}