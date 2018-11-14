/*
 *  Problem: find min height tree ()
 *  Compile: g++ -o findMinHeightTrees findMinHeightTrees.cpp && ./findMinHeightTrees
 *  Execute: ./findMinHeightTrees
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


std::vector<int> IA;
std::vector<int> J;
int nvertices;
int nedges;

void csr(int n, std::vector<std::pair<int, int>>& edges)
{
    nvertices = n;
    nedges = edges.size();
    IA.resize(nvertices + 1);
    J.resize(nedges);
    int i = 1;
    int j = 0;
    IA[0] = 0;
    for(auto& edge : edges)
    {
        while(edge.first > (i - 1))
        {
            i++;
            IA[i] = IA[i-1];
        }
        IA[i]++;
        J[j] = edge.second;
        j++;
    }
    while(i + 1 < nvertices + 1)
    {
        i++;
        IA[i] = IA[i-1];
    }
}

void print()
{
    for(int i = 0; i < nvertices; i++)
    {
        printf("Row:%d\n", i);
        for(int j = IA[i]; j < IA[i+1]; j++)
        {
            printf("   i=%d j=%d\n", i, J[j]);
        }
    }
}
std::vector<char> visited;

int lookup(int src, int height)
{
    int i = src;
    int h = height;
    bool is_leaf = true;
    
    //int height = 0;
    if(not visited[i])
    {
        visited[i] = true;
        h++;
        for(int j = IA[i]; j < IA[i+1]; j++)
        {
            printf("1. i=%d j=%d h=%d v=%d\n", i, J[j], h, visited[J[j]]);
            if(not visited[J[j]])
            {
                //h = h + 1;
                h = lookup(J[j], h);
            }
            printf("2. i=%d j=%d h=%d v=%d\n", i, J[j], h, visited[J[j]]);
            //if(mht < h)
            //    h = mht;
        }
    }
    printf("%d %d\n", src, is_leaf);
    return(h);
}

std::vector<int> findMinHeightTrees(int n, std::vector<std::pair<int, int>>& edges)
{
    std::vector<int> mhts;
    int m = edges.size();
    for(int i = 0; i < m; i++)
        edges.push_back(std::make_pair(edges[i].second, edges[i].first));
    std::sort(edges.begin(), edges.end());
    
    //for(int i = 0; i < edges.size(); i++)
    //    printf("%d %d\n", edges[i].first, edges[i].second);
    
    csr(n, edges);
    print();
    visited.resize(n);
    printf("\n");
    int ret = lookup(1, -1);
    printf("Result:%d\n", ret);
    //for(int i = 0; i < nvertices; i++)
    //{
        //printf("Row:%d\n", i);
        
    //}
    
    
    
    /*
    int nnz = edges.size();
    J.resize(nnz);
    IA.resize(n+1);
    int i = 1;
    int j = 0;
    IA[0] = 0;
    for(auto& edge : edges)
    {
        printf("%d %d\n", edge.first, edge.second);
        while(edge.first > (i - 1))
        {
            i++;
            IA[i] = IA[i-1];
        }
        IA[i]++;
        J[j] = edge.second;
        j++;
    }
    while(i + 1< n + 1)
    {
        i++;
        IA[i] = IA[i-1];
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d\n", i);
        for(int j = IA[i]; j < IA[i+1]; j++)
        {
            printf("i=%d j=%d\n", i, J[j]);
        }
    }
*/
    
    
    //for(int i = 0; i < n; i++)
    //{        
      //  printf("%d\n", i);
        //std::find(edges.begin(), edges.end(), n, 
    //}
    
    return(mhts);
}
int main(int argc, char **argv)
{
    
    int n = 4 + 1;
    int m = 3;
    std::vector<std::pair<int, int>> edges;
    int srcs[] = {1, 1, 1};
    int dsts[] = {0, 3, 2};
    
    for(int i = 0; i < m; i++)
        edges.push_back(std::make_pair(srcs[i], dsts[i]));
    
    
    
   // for(int i = 0; i < m; i++)
   //     printf("%d %d\n", edges[i].first, edges[i].second);
    
    /*
    int n = 6;
    int m = 5;
    std::vector<std::pair<int, int>> edges;
    int srcs[] = {1, 1, 2, 4, 5};
    int dsts[] = {3, 3, 3, 3, 4};
    
    for(int i = 0; i < m; i++)
        edges.push_back(std::make_pair(srcs[i], dsts[i]));
    
    for(int i = 0; i < m; i++)
        printf("%d %d\n", edges[i].first, edges[i].second);
    */
    
    std::vector<int> ret = findMinHeightTrees(n, edges);
   // for(int i = 0; i < ret.size(); i++)
     //   printf("%d\n", ret[i]);
    
    
    return(0);
}