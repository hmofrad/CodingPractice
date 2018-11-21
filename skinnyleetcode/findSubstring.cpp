/*
 *  Problem: Substring with Concatenation of all words()
 *  Compile: g++ -o findSubstring findSubstring.cpp && ./findSubstring
 *  Execute: ./findSubstring
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




std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
{
    std::vector<int> positions;
    
    int k = 0;
    for(int i = 0; i < words.size(); i++)
    {
        for(int j = 0; j < s.size(); j++)
        {
            std::string temp = s.substr(k, words[i].size());
            if(!strcmp(words[i].c_str(), temp.c_str()))
                positions.push_back(j);
            k++;
        }
    }
    
    positions.push_back(0);
    return(positions);
}


int main(int argc, char **argv)
{
    std::string str = "barfoothefoobarman";
    printf("input=%s\n", str.c_str());
    
    std::vector<std::string> words(1);
    words[0] = "foo";
    printf("words=%s\n", words[0].c_str());
    
    //std::vector<std::string> words(2);
    //words[0] = "foo";
    //words[1] = "bar";
    //printf("words=%s, %s\n", words[0].c_str(), words[1].c_str());
        
    std::vector<int> positions = findSubstring(str, words);
    for(int i = 0; i < positions.size(); i++)
    {
        printf("i=%d pos=%d\n", i, positions[i]);
    }
    
    return(0);
}