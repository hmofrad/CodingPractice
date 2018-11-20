/*
 *  Problem: Count and say ()
 *  Compile: g++ -o countAndSay countAndSay.cpp && ./countAndSay
 *  Execute: ./countAndSay
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

std::string countAndSay(int n)
{
    printf("1.n=%d\n", n);
    std::string out, tmp;
    if(n == 0)
        out = "0";
    else if(n == 1)
        out = "1";
    else
    {
        out.append(countAndSay(n-1));
        uint32_t count = 1;
        char value = out[0];
        uint32_t pos = 0;
        uint32_t i = 1;
        bool remained = true;
        std::vector<uint32_t> counts;
        std::vector<char> values;
        for(uint32_t i = 1; i < out.size(); i++)
        {
            if(out[i] == out[i-1])
            {
                count++;
            }
            else
            {
                counts.push_back(count);
                values.push_back(value);
                count = 1;
                value = out[i];
                if(i + 1 < out.size())
                {
                    remained = true;
                }
            }
        }
        
        if(remained)
        {
            counts.push_back(count);
            values.push_back(value);
        }
        
        out.resize((counts.size() * 2) + 1, 0);
        uint32_t j = 0;
        for(uint32_t i = 0; i < counts.size(); i++)
        {
            out.replace(j, 1, std::to_string(counts[i]));
            //strcpy(out[j], std::to_string(counts[i]))
            //.c_str() = std::to_string(counts[i]);
            j++;
            out[j] = values[i];
            printf("[%d %c %c%c] ", counts[i], values[i], out[j-1], out[j]);
        }
        printf("%s\n", out.c_str());   
        //printf("<%s>\n", out.c_str());
        
        /*
        
        //if(i < out.size())
        //{
            while(i < out.size())  
            //for(uint32_t i = 1; i < out.size(); i++)
            {
                printf("<%d %c>\n", i, out[i]);
                if(out[i-1] == out[i])
                {
                    count++;
                    i++;
                }
                else
                {
                    //out.insert(pos, std::to_string(count));

                    if(i < out.size())
                    {
                        insert = true;
                    }
                    else
                    {
                        tmp.insert(pos, std::to_string(count));
                        pos++;
                        tmp.insert(pos, std::to_string(out[i-1]));
                        count = 1;
                        insert = true;
                    }
                }
            }
        //}
        //else
            if(insert)
            {
                
                out.insert(pos, std::to_string(count)); 
            }
            */
        
    }
    printf("2.n=%d out=%s\n", n, out.c_str());
    return(out);
}

int main(int argc, char **argv)
{
    
    std::string out = countAndSay(4);
    printf("%s %lu\n", out.c_str(), out.size());
    return(0);
}