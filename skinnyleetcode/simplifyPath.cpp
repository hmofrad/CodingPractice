/*
 *  Problem: Implement Pow(x, n)
 *  Compile: g++ -o simplifyPath simplifyPath.cpp -std=c++11 && ./simplifyPath
 *  Execute: ./simplifyPath
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

const char slash = '/';
const char dot = '.';



std::string simplifyPath(std::string path)
{
    std::string spath;
    std::vector<char> stack;
    int n = path.size();
    if(n == 0 or n == 1)
    {
        spath = path;
        return(spath);
    }
    
    if(path[0] == slash and path[1] == dot and path[2] == dot)
    {
        spath = "/..";
        return(spath);
    }
    
    char c = '0';
    stack.push_back(path[0]);
    for(int i = 1; i < n; i++)
    {
        if(path[i] == slash)
        {
            if((i + 1 < n) and not (stack.back() == slash)) {
                stack.push_back(path[i]);
            }
        }
        else if (path[i] == dot)
        {
            if(stack.back() == dot)
            {
                stack.push_back(path[i]);
                if(stack.size() - 2 == 1)
                {
                    stack.pop_back();
                    stack.pop_back();
                }
                else
                {
                    stack.pop_back();
                    stack.pop_back();
                    if(stack.size() > 1)
                        stack.pop_back();
                    while(stack.back() != slash)
                        stack.pop_back();
                        
                    //stack.pop_back();
                    //stack.pop_back();
                    if(stack.size() > 1)
                        stack.pop_back();
                }
                
            }
            else
            {
                if((i + 1 < n))
                {
                    if(path[i+1] == dot)
                        stack.push_back(path[i]);
                }
            }
        }
        else
        {
            stack.push_back(path[i]);
        }
    }
    
    //for(int i = stack.size(); i >= 0; i--)
      //  printf("%c", stack[(stack.size() - 1) - i]);
    //printf("\n");
    
    spath.resize(stack.size());
    for(int i = 0; i < stack.size(); i++)
    {
      //  printf("%d %d %c\n", i, (stack.size() - 1) - i, stack[(stack.size() - 1) - i]);
         spath[i] = stack[i];
    }
        //printf("%c", stack[(stack.size() - 1) - i]);
    
    return(spath);
}

int main(int argc, char **argv)
{
    //std::string path = "/a//b////c/d//././/../";
    //std::string path = "/a//bbbb/..///c/dddd//././/../";
    std::string path = "/abc/...";
    std::string spath = simplifyPath(path);
    printf("simplifyPath(%s)=%s\n", path.c_str(), spath.c_str());
    return(0);
}