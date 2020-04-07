/*
 *  https://leetcode.com/problems/occurrences-after-bigram/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::string extract(std::string text, int& i, int& j) {
    int sz = text.size();
    while(i < sz and text[i] != ' ') i++;
    int len = i-j;
    std::string str = text.substr(j, len);
    j=++i;
//    printf("%d %d %s\n", i, j, str.c_str());
    return str;
}
void move_back(std::string text, int& i, int& j) {
    i-=2;
    while(i >= 0 and text[i] != ' ') i--;
    j=++i;
}
vector<string> findOcurrences(string text, string first, string second) {
    printf("%s\n", text.c_str());
    printf("%s, %s\n", first.c_str(), second.c_str());
    std::vector<string> out;
    int m = text.length();
    int i = 0;
    int j = 0;
    while(i < m) {
        std::string first1 = extract(text, i, j);
        printf("first1: %d %d %s\n", i, j, first1.c_str());
        if(i >= m) {
            break;
        }
        else if(first1 == first) {
            std::string second1 = extract(text, i, j);
            printf("second1: %d %d %s\n", i, j, second1.c_str());
            if(i >= m) {
                break;
            }
            else if (second1 == second) {
                std::string third = extract(text, i, j);
                out.push_back(third);
                printf("third: %d %d %s\n", i, j, third.c_str());
                if(third == first) {
                    move_back(text, i, j);
                }
            }
            else if(second1 == first) {
                move_back(text, i, j);
            }
        }
    }
    return(out);
}



int main() {
    std::string text = "jkypmsxd jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa kcyxdfnoa jkypmsxd kcyxdfnoa";
    std::string first = "kcyxdfnoa";
    std::string second = "jkypmsxd";
    std::vector<std::string> vec = findOcurrences(text, first, second);
    for(std::string s: vec) {
        printf("%s\n", s.c_str());
    }
}
    
