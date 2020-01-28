/*
 *  Problem: https://leetcode.com/problems/remove-k-digits/
 *  Compile: g++ -o removeKdigits removeKdigits.cpp -std=c++11 -g -Wall -fsanitize=address && ./removeKdigits    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
/*
std::string removeKdigits(std::string num, int k) {
    if(num.size() == (uint32_t) k) return("0");
    std::string new_num;
    std::vector<uint32_t> pos;
    char n = num[0];
    for(uint32_t i = 1; ((i < num.size()) and (pos.size() != (uint32_t) k)); i++) {
        if(num[i] > n) {
            pos.push_back(i);
        }
        else {
                pos.push_back(i-1);
                n = num[i];
        }
    }

    
    for(auto p: pos) {
        printf("%d ", p);
    }
    printf("\n");
    
    uint32_t j = 0;
    for(uint32_t i = 0; i < num.size(); i++) {
        if(j < pos.size()) {
            if(i != pos[j]) {
                if ((not new_num.empty()) or (num[i] != '0')) {
                    new_num += num[i];
                }
            }
            else {
                j++;
            }
        }
        else {
            if((not new_num.empty()) or (num[i] != '0')) {
                new_num += num[i];
            }
        }
    }
    
    if(new_num.empty()) new_num = "0";
    
    return(new_num);
}
*/


std::string removeKdigits(std::string num, int k) {
    if ((uint32_t) k == num.size()) {
        return("0");
    }        
    
    std::string res;
    for (uint32_t i = 0; i < num.size(); i++) {
        if (((i - k) == res.size()) or (res.empty())) {
            res.push_back(num[i]);
        } 
        else if ((res.back() > num[i]) and ((res.size() + k) > i)) {
            do {
                res.pop_back();
            } while ((res.back() > num[i]) and ((res.size() + k) > i));
            res.push_back(num[i]);
        } 
        else if (res.size() < (num.size() - k)) {
            res.push_back(num[i]);
        }
    }
    printf("%s\n", res.c_str());
    uint32_t i = 0;
    while((i < res.size()) and (res[i] == '0')) i++; 

    return((i == res.size()) ? "0" : res.substr(i));
}



int main(int argc, char **argv){
    std::string s = "1432219"; // 4,3,2 --> 1219
   // std::string s = "001111111";
    int k = 3;
    //std::string s = "112";
    //int k = 1;
    printf("Num=%s\n", s.c_str());
    std::string t = removeKdigits(s, k);
    printf("New num=%s\n", t.c_str());
    return(0);
}
