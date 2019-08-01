/*
 *  URL: https://leetcode.com/problems/excel-sheet-column-number/
 *  Compile & Execute: g++ -o titleToNumber titleToNumber.cpp -std=c++11 && ./titleToNumber
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

class Solution {
public:
    static int titleToNumber(std::string s) {
        int MAX_TITLE = 26;
        int n = 0;
        char c = '\0';
        int m = s.size();
        int e = 0;
        int j = 0;
        //int i = s.size();
        for(int i = 0; i < m; i++) {
            c = s[i];
            //m = (s.size() - i - 1);
            j = 0;
            e = 1;
            while(j < (m - i - 1)) {
                e *= MAX_TITLE;
                j++;
            }
            n += (s[i] - 'A' + 1) * e;
            //n += ((s[i] - 'A' + 1) ^ ((m - i - 1) * MAX_TITLE));
            //n += (s[i] - 'A' + 1) * (i * MAX_TITLE);
            //n += (s[i] - 'A' + 1);
            printf("%d %d %d %d\n", n, j, (m - i - 1), MAX_TITLE ^ (m - i - 1));
            
        }
        //n += (s[m-1] - 'A' + 1);
        return(n);
    }
};
int main(int argc, char **argv) {
    std::string s = "BAA";

    int n = Solution::titleToNumber(s);
    printf("<%d> %d\n", n, 'A');
    return(0);
}    
