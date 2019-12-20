/*
  * Cracking the coding interview: Problem 1.4: Replace spaces with %20
  * Compile and run:  g++ -o replace replace.c -g -Wall  -std=c++11 -fsanitize=address && ./replace
  * (c) Mohammad Hasanzadeh mofrad, 2019
  * (e) m.hasanzadeh.mofrad@gmail.com
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
/*
void replace_spaces(std::string& str) {
    // Circular Shift the string to right
    uint32_t j = str.size()-1;
    for(uint32_t i = str.size()-1; i+1 >= 0+1; i--) {
        if(str[i] == ' ') {
            j--;
        }
        else {
            break;
        }
                
    }
    uint32_t k = 0;
    uint32_t l = 0;
    for(uint32_t i = j; i+1 >= 0+1; i--) {
        l = str.size()-1-k;
        str[l] = str[i];
        k++;
    }
    
    for(uint32_t i = 0; i < l; i++) {
            str[i] = ' ';
    }    
    
    
    // Shift the string to left while replacing spaces
    j = 0;
    for(uint32_t i = l; i < str.size(); i++) {
        if(str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
        else {
            str[j] = '%';
            str[j+1] = '2';
            str[j+2] = '0';
            //i++;
            j+=3;
        }
    }
    
}
*/

void replace_spaces(std::string& str) {
    // Circular Shift the string to right
    uint32_t j = str.size()-1;
    for(uint32_t i = str.size()-1; i+1 >= 0+1; i--) {
        if(str[i] == ' ') {
            j--;
        }
        else {
            break;
        }
                
    }
    uint32_t k = str.size()-1;
    for(uint32_t i = j; i+1 >= 0+1; i--) {
        if(str[i] == ' ') {
            str[k] = '0';
            str[k-1] = '2';
            str[k-2] = '%';
            k-=3;
        }
        else {
            str[k] = str[i];
            k--;
        }
    }
}


int main(int argc, char* argv[]) {
    std::string str = "Mar John  Smith      ";
    printf("[%s]\n", str.c_str());
    replace_spaces(str);
    printf("[%s]\n", str.c_str());
    return(0);
}