/*
 *  Problem: Valid parentheses (https://leetcode.com/problems/valid-parentheses/description/)
 *  Compile: g++ -o isValid isValid.cpp && ./isValid -g -Wall -Werror
 *  Execute: ./addTwoNumbers
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>

class ValidParentheses{
    public:
        bool isValid(std::string s)
        {
            //std::cout << s.c_str() << std::endl;
            bool ret = false;
            if(!s.empty() and !(s.size()%2))
            {
                uint32_t i = 0, j = 0;
                std::vector<char> stack;
                for(i = 0; i < s.size(); i++)
                {
                    printf("%c\n", s[i]);
                    char c1, c2;
                    if((s[i] == '(') or (s[i] == ')'))
                    {
                        c1 = '(';
                        c2 = ')';
                    }
                    else if((s[i] == '[') or (s[i] == ']'))
                    {
                        c1 = '[';
                        c2 = ']';
                    }
                    else if((s[i] == '{') or (s[i] == '}'))
                    {
                        c1 = '{';
                        c2 = '}';
                    }
                    else
                        break;
                    
                    if((s[i] == c1))
                    {
                        stack.push_back(c1);
                    }
                    else
                    {
                        if(stack.size())
                        {
                            char r = stack.back();
                            stack.pop_back();
                            if(r != c1)
                                break;
                        }
                        else
                            break;
                    }
                } 
                //printf("%d %lu %lu\n", i, s.size(), stack.size());
                if(!stack.size() and i == s.size())                
                    ret = true;
            }
            else if(s.empty())
                ret = true;
            return(ret);
        }
};

int main(int argc, char **argv){
    
    
    ValidParentheses Test;
    std::string str = "";
    bool ret = Test.isValid(str);
    std::cout << ret << std::endl;
    return(0);
}