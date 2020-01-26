/*
 *  Problem: https://leetcode.com/discuss/interview-question/398026/
 *  Compile: g++ -o minMoves minMoves.cpp -std=c++11 -g -Wall -fsanitize=address && ./minMoves
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

/*
00
01 a
02 aa
03 aaa /2
04 aaaa /2
05 aaaaa /2
06 aaaaaa /2 + /2
07 aaaaaaa /2 + /2
08 aaaaaaaa /2 + /2 
09 aaaaaaaaa /2 + /2 + /2
10 aaaaaaaaaa /2 + /2 + /2

*/

int minMoves(std::string s) {
    //int min = 0;
    std::string t = s;
    int count = 0;
    char p = s[0];
    uint32_t i = 1;
    uint32_t i1 = 0;
    uint32_t i2 = 0;
    while(i < s.size()) {
        char c = s[i]; 
        //printf("%c\n", c);
        if((p != c) or ((i+1) == s.size())) {
            i2 = i;
            
            uint32_t j1 = i1+2;
            uint32_t j2 = i2-1;
            //printf("%d %d , %d %d\n", i1, i2, j1, j2);
            while(j1 <= j2) {
                //t[j1] = (t[j1] == 'a') ? 'b' : 'a'; 
                t[j1] = ('a'+'b') - t[j1];
                //char cc = (char)(('a' + 'b') % t[j1]);
                //t[j1] = ('a' + 'b') % t[j1];
                //printf("j1=%d a=%d b=%d aBb=%d t[j1]=%c\n", j1, 'a', 'b', 'a' + 'b', t[j1]);
                //printf("%d %d\n", 'b', ('a'+'b')-'b');
                j1 += 3;
                
                count++;
            }
            
            printf("%c: [%d %d]\n", p, i1, i2-1);
            i1 = i2;
            if(((i+1) == s.size()) and (p != c)) {
                printf("%c: [%d %d]\n", c, i1, i2);
            }
            p = c;

        }
        i++;
    }
    printf("s= %s\n", s.c_str());
    printf("t= %s\n", t.c_str());
    return(count);
}

int main(int argc, char **argv){
    //std::string s = "baaaaaab";
    std::string s = "baaabbaabbba";
    //std::string s = "baabab";
    
    int m = minMoves(s);
    printf("Min=%d\n", m);
    
    return(0);
}
