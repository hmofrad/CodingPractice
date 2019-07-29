/*
 *  URL: https://leetcode.com/problems/excel-sheet-column-title/
 *  Compile & Execute: g++ -o convertToTitle convertToTitle.cpp -std=c++11 && ./convertToTitle
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <iostream>
#include <vector>
//#include <algorithm>

class Solution {
public:
    static std::string convertToTitle(int n) {
        std::string title;
        if(n <= 0)
            return(title);
        
        //title = '\0';
        int MAX = 26;
        int n1 = (n-1) % MAX;
        title += ('A' + n1);
        //int n2 = (n-1) / MAX;
        int n2 = (n-1) / MAX;
        int n0 = 0;;
        while(n2) {
            n0 = (n2-1) % MAX;
            title += ('A' + n0);
            printf("n2=%d n0=%d\n", n2, n0);
            n2 = (n2-1) / MAX;
            
        }
        
        
        //int n2 = 1 + ((n - 1) / MAX); // if x != 0
        //if(not n1 and n2) {
         //   n1 = MAX;
           // n2--;
        //}
            
        //do {
            //title += 
            
        //}while(n1 > 0);
        
        int len = title.length();
        for (int i = 0; i < len/2; i++)
            std::swap(title[i], title[len-i-1]);
        
        //printf("[%d %d] [%c %c]\n", n1, n2,  'A' + (n2-1), 'A' + n1);
            //std::reverse(title.begin(), title.end()); 
        return(title);
    }
};

int main(int argc, char **argv) {
    printf("[%d %d] [%c %c] [%d %d]\n", 'A', 'Z', 'A', 'Z', 'A'%26, 'Z'%26);
    int n = 800;
    std::string out = Solution::convertToTitle(n);
    printf("<%s>\n", out.c_str());
    return(0);
}    
