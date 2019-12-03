/*
 *  Problem: https://leetcode.com/problems/add-strings/
 *  Compile: g++ -o toHex toHex.cpp -std=c++11 && ./toHex #-fsanitize=address 
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

//char num2char

std::string toHex(int num) {
    if(!num) return("0");
    std::string hex;
    std::vector<char> map = {'0', '1', '2', '3', '4',
                             '5', '6', '7', '8', '9',
                             'a', 'b', 'c', 'd', 'e',
                             'f'};
   
    bool first = false;
    for(int i = 31; i >= 3; i-=4) {
        unsigned int j = i - 4 + 1;
        //unsigned int mask = 0xF << j;
        //unsigned int h = (num & mask) >> j;
        unsigned int h = (num >> j) & 0xF;
        if(h) first = true;
        if(first)
            hex += map[h];
        j--;
    }

    return(hex);
}

int main(int argc, char **argv){
    int n = -1;
    std::string hex = toHex(n);
    printf(">>%s\n", hex.c_str());
    return(0);
}






