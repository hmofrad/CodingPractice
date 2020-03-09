/*
 *  Problem: https://leetcode.com/problems/assign-cookies/
 *  Compile: g++ -o findContentChildren findContentChildren.cpp -std=c++11 -g -Wall -fsanitize=address && ./findContentChildren
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int findContentChildren1(std::vector<int>& g, std::vector<int>& s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    
    std::vector<bool> g1(g.size(), false);
    std::vector<bool> s1(s.size(), false);
    
    uint32_t g_i = 0;
    uint32_t s_i = 0;
    int k = 0;
    while(g_i < g.size() and s_i < s.size()) {
        if(g[g_i] == s[s_i]) {
            k++;
            g1[g_i] = true;
            s1[s_i] = true;
            g_i++;
            s_i++;
            
        }
        else if(g[g_i] < s[s_i]) {
            g_i++;
        }
        else {
            s_i++;
        }
    }
    
    uint32_t ss = std::accumulate(s1.begin(), s1.end(), 0);
    uint32_t gg = std::accumulate(g1.begin(), g1.end(), 0);
    printf("%d %d\n", ss, gg);
    if(ss < s.size() and gg < g.size()) {
        g_i = 0;
        s_i = 0;
        while(g_i < g.size() and s_i < s.size()) {
            if(not g1[g_i] and not s1[s_i]) {
                if(s[s_i] >= g[g_i]) {
                    //printf("", s1[s_i], );
                    k++;
                    g1[g_i] = true;
                    s1[s_i] = true;
                    g_i++;
                    s_i++;
                }
                else {
                    s_i++;
                }
                continue;
            }
            if(g1[g_i]) g_i++;
            if(s1[s_i]) s_i++;
        }
    }

    return(k);
}

int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int32_t ig = g.size()-1;
    int32_t is = s.size()-1;
    int k = 0;
    while(ig >= 0 and is >= 0) {
        if(s[is] >= g[ig]) {is--; k++;}
        ig--;
    }
    return(k);
}

int main(int argc, char **argv){
    std::vector<int>  g = {1, 2, 3};
    std::vector<int>  s = {1, 1};
    int r = findContentChildren(g, s);
    printf("R=%d\n", r);
    return(0);
}






