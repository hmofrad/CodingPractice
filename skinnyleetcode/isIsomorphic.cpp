/*
 *  Problem: https://leetcode.com/problems/isomorphic-strings/
 *  Compile: g++ -o isIsomorphic isIsomorphic.cpp -std=c++11
 *  Execute: ./isIsomorphic
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
#include <unordered_map>




class Solution {
public:
    static bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<unsigned char, unsigned char> r;
        bool ret = true;
        int m = s.size();
        int n = t.size();
        if(m != n) {
            ret = false;
        }
        else if(m > 0) {
            
            //std::string r;
            for(int i = 0; i < m; i++) {
                unsigned char k = s[i];
                unsigned char v = t[i];
                //printf("<%c, %c>\n", k, v);
                std::unordered_map<unsigned char, unsigned char>::const_iterator f1 = r.find (k);
                //std::unordered_map<unsigned char, unsigned char>::const_iterator f2 = r.find (v);
                //if((f1 == r.end()) and (f2 == r.end())) {
                if(f1 == r.end()) {
                    r[k] = v;
                    //printf("%c, %c %c %c\n", k, r[k], got->first, got->second);
                   // r[v] = k;
                }
                //else if(f1 != r.end()){
                else {
                    //printf("%d %d\n", f1 == r.end(), f2 == r.end());
                    //printf("%c, %c %c\n", k, r[k], f1->first);
                    if(f1->second != v) {
                      //  printf("xxxx\n");
                        ret = false;
                        break;
                    }
                }
                /*
                else {
                    if(f2->first!= k) {
                        //printf("kkkk\n");
                        ret = false;
                        break;
                    }
                }
                */
            }
                
        }
        
        for (auto const& pair: r) {
            std::cout << "{" << pair.first << ": " << pair.second << "}\n";
        }
        
        return(ret);
	}
};

int main(int argc, char **argv)
{
	std::string s = "ab";
    std::string t = "aa";
    
    printf("isIsomorphic(%s, %s)=%d\n", s.c_str(), t.c_str(), Solution::isIsomorphic(s, t));
    return(0);
}