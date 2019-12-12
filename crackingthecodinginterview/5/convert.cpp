/*
 *  Cracking the coding interview: Problem 5.2: Convert a double in the range of [0 1] to bits
 *  Compile & run: g++ -o convert convert.cpp -g -Wall -std=c++11 -fsanitize=address && ./convert
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <math.h>
/*
#define MAX_DECIMAL_POINTS 5
std::string dtoc(const double num) {
    std::string seq;
    double num1 = (int) num;
    int d = 0;
    int i = 0;
    do{
        d = (int) (((int)num1)%10);
        num1 = (double)((num1/10)); 
        seq.push_back(d+'0');
        i++;
    } while(d);
    seq.pop_back();
    std::reverse(seq.begin(), seq.end());
    
    num1 = num - (int) num;
    printf("111 %f\n", num1);
    do {
        d = (int) ((num1+0.0)*10);
        num1 = (double) (num1*10 - d); 
        seq.push_back(d+'0');
        printf("%f %d %d %d\n", num1, (int)(num1*10), num1 == 0.900000, d);
    } while(d);
    seq.pop_back();
    printf(">> %s\n", seq.c_str());
    
    
    return(seq);
}
*/

#define MAX_DECIMAL_POINTS 8
std::string dtoc(double num) {
    std::string seq;
    int d = 0;
    int i = 0;
    do {
        d = (int) (num*10);
        num = (double) (num*10 - d); 
        seq.push_back(d+'0');
        i++;
    } while(d and i < MAX_DECIMAL_POINTS);
    seq.pop_back();    
    return(seq);
}



void convert(double num) {
    std::string num_str = dtoc(num);
    printf("%s %f\n", num_str.c_str(), num);
    std::string binary;
    while(num > 0) {
        double r = num * 2;
        printf("1> %f %f\n", num, r);
        if(r>=1) {
            binary.push_back('1');
            num = r-1;
        }
        else {
            binary.push_back('0');
            num = r;
        }
        printf("2> %f %f\n", num, r);
        break;
    }
    printf(">>> %lu %s\n", binary.size(), binary.c_str());
}

int main(int argc, char** argv) {
    double num = .6236;
    convert(num);

    
    return(0);
}