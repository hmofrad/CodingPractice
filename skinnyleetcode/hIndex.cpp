    /*
 *  Problem: https://leetcode.com/problems/h-index/
 *  Compile: g++ -o hIndex hIndex.cpp -std=c++11 && ./hIndex
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
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
#include <unordered_set>
#include <stack>
#include <numeric>
#include <map>

/*
int hIndex(std::vector<int>& citations) {
    if(citations.empty())
        return(0);
    int n = citations.size();
    std::sort(citations.begin(), citations.end());
    
    int index = 0;
    
    for(int i = n-1; i >= 0; i--) {
        
        if(index >= citations[i])
            break;
        index++;
    }
    
    return(index);
}
*/

int hIndex(std::vector<int>& citations) {
    if(citations.empty())
        return(0);
    int n = citations.size();
    //std::sort(citations.begin(), citations.end());
    
    
    int index = 0;
    bool found = false;
    for(int k = n; k >= 0; k--) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(index <= citations[i]) {
                count++;
            }
        }
        printf("%d %d %d\n", k, count, index);
        if(count == index) {
            found = true;
            break;
        }
        index++;
    }
    if(not found) index = 0;
    
    return(index);
}


    
int main(int argc, char **argv){
    
    
    std::vector<int> citations = {1,1};//{3,0,6,1,5};

    for(auto& i: citations) {
        printf("%d ", i); 
    }
    printf("\n");

    
    int index = hIndex(citations);
    printf("hIndex ? %d\n", index);
    
    return(0);
}






