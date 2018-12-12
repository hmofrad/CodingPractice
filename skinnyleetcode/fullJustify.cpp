/*
 *  Problem: Implement Pow(x, n)
 *  Compile: g++ -o fullJustify fullJustify.cpp -std=c++11 && ./fullJustify
 *  Execute: ./fullJustify
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

std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth)
{
    std::vector<std::string> justifiedStr;
    
    int n = words.size();
    std::vector<int> sizes(n);
    
    for(int i = 0; i < n; i++)
        sizes[i] = words[i].size();
    int wordsLength = std::accumulate(sizes.begin(), sizes.end(), 0);
    
    int i = 0, j = 0, i1 = 0, i2 = 0, k = 0;
    while(i < n)
    {
        printf("%d %s\n", i, words[i].c_str());
        j += (words[i].size() + 1);

        if(j == maxWidth)
        {
            printf("Clean: %d %d %s\n", i, j, words[i].c_str());
        }
        else if(j > maxWidth)
        {
            printf("Trimming: %d %d %s\n", i, j, words[i].c_str());
            if(j - 1 == maxWidth)
            {
                j--;
                printf("Done: %d %d %s\n", i, j, words[i].c_str());
            }
            else
            {
                j -= (words[i].size() + 1);
                i--;
                printf("Done: %d %d %s\n", i, j, words[i].c_str());
                std::string t = words[i1];
                t += " ";
                while(i1 < i)
                {
                    i1++;
                    t += words[i1];
                    t += " ";
                }
                printf("Done: %s\n", t.c_str());
                //justifiedStr[k]
                break;
            }
        }
        //i += words[j].size();
        i++;
    }
    
        
    
    //while(true)
    //{
        
    //}
    
    return(justifiedStr);
}

int main(int argc, char **argv)
{
    int maxWidth = 16;
    std::vector<std::string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    //std::vector<std::string> words = {"What","must","be","acknowledgment","shall","be"};
    //std::vector<std::string> words = {"Science","is","what","we","understand","well","enough","to","explain",
    //"to","a","computer.","Art","is","everything","else","we","do"}

    for(auto& w: words)
        std::cout << w << " ";
    std::cout << "\n";
    
    
    std::vector<std::string> justifiedStr = fullJustify(words, maxWidth);
    
    for(auto& w: justifiedStr)
        std::cout << w << " ";
    std::cout << "\n";
    
    return(0);
}