/*
 *  Problem: Implement Pow(x, n)
 *  Compile: g++ -o addBinary addBinary.cpp -std=c++11 && ./addBinary
 *  Execute: ./addBinary
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




std::string addBinary(std::string a, std::string b)
{
    std::vector<int> c;
    int s_a = a.size();
    int s_b = b.size();
    int i_a = s_a;
    int i_b = s_b;
    bool carry = false;
    
    while(i_a > 0 or i_b > 0)
    {
        //printf("%d %d ", i_a, i_b);
        if(i_a > 0 and i_b > 0)
        {
            i_a--;
            i_b--;
            
          //  printf("1. a=%c b=%c ca=%d\n", a[i_a], b[i_b], carry);
            if(carry)
            {
                if(a[i_a] == '1' and b[i_b] == '1')
                {
                    c.push_back(1);
                    carry = true;
                }
                else if((a[i_a] == '1' and b[i_b] == '0') or (a[i_a] == '0' and b[i_b] == '1'))
                {
                    c.push_back(0);
                    carry = true;
                }
                else
                {
                    c.push_back(1);
                    carry = false;
                }
            }
            else
            {
                if(a[i_a] == '1' and b[i_b] == '1')
                {
                    c.push_back(0);
                    carry = true;
                }
                else if((a[i_a] == '1' and b[i_b] == '0') or (a[i_a] == '0' and b[i_b] == '1'))
                {
                    
                    c.push_back(1);
                    carry = false;
                }
                else
                {
                    //printf("xxxx\n");
                    c.push_back(0);
                    carry = false;
                }
            }
        }
        else if (i_a > 0)
        {
            i_a--;
         //   printf("2. a=%c\n", a[i_a]);
            if(carry)
            {
                if(a[i_a] == '1')
                {
                    c.push_back(0);
                    carry = true;
                }
                else
                {
                    c.push_back(1);
                    carry = false;
                }
            }
            else
            {
                if(a[i_a] == '1')
                {
                    c.push_back(1);
                    carry = false;
                }
                else
                {
                    c.push_back(0);
                    carry = false;
                }
            }
        }
        else if (i_b > 0)
        {
            i_b--;
            //printf("3. b=%c %d\n", a[i_b], carry);
            if(carry)
            {
                if(b[i_b] == '1')
                {
                    c.push_back(0);
                    carry = true;
                }
                else
                {
                    c.push_back(1);
                    carry = false;
                }
            }
            else
            {
                if(b[i_b] == '1')
                {
                    c.push_back(1);
                    carry = false;
                }
                else
                {
                    c.push_back(0);
                    carry = false;
                }
            }
        }
        //printf("back=%d\n", c.back());
    }
    if(carry)
        c.push_back(1);
    
   // for(int i = 0; i < c.size(); i++)
     //   printf("%d ", c[i]);
    //printf("\n");
    
    std::string sum(c.size(), '0');
    
    
    for(int i = 0; i < c.size(); i++)
    {
        if(c[i])
           sum[(c.size() - 1) - i] = '1';
            //sum.insert(i - (c.size() - 1), '1');
       // else
         //   sum[i + (c.size() - 1)] = '0';
     //printf("%s %d\n", sum.c_str(), (c.size() - 1) - i);
    }
    

    
    return(sum);
}

int main(int argc, char **argv)
{
    std::string a = "100";
    std::string b = "110010";
    std::string c = addBinary(a, b);
    printf("addBinary(%s, %s)=%s\n", a.c_str(), b.c_str(), c.c_str());
    return(0);
}