/*
 *  Problem: https://leetcode.com/problems/add-strings/
 *  Compile: g++ -o addStrings addStrings.cpp -std=c++11 && ./addStrings #-fsanitize=address 
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm> 

std::string addStrings(std::string num1, std::string num2) {
    std::string num;
    
    int i1 = num1.size()-1;
    int i2 = num2.size()-1;
    int c = 0;
    
    while(i1>=0 and i2>=0) {
        int d1 = num1[i1] - '0';
        int d2 = num2[i2] - '0';

        int d = d1 + d2 + c;
        c = 0;
        if(d > 9) {
            c = 1;
            d -= 10;
        }

        num += (d + '0');

        i1--;
        i2--;            
    }
    
    int i = (i1>=0) ? i1 : i2;
    auto& num3 = (i1>=0) ? num1 : num2;

    while(i>=0) {
        int d1 = num3[i] - '0';
        int d = d1 + c;
        c = 0;
        if(d > 9) {
            c = 1;
            d -= 10;
        }

        num += (d + '0');
        i--;
    }
    
    if(c) {
        num += (c + '0');
    }
    
    std::reverse(num.begin(), num.end());
    
    return(num);  
}


int main(int argc, char **argv){
    std::string num1 = "1";
    std::string num2 = "9";
    std::string num = addStrings(num1, num2);
    printf("addStrings(%s, %s) = %s\n", num1.c_str(), num2.c_str(), num.c_str());
    return(0);
}






