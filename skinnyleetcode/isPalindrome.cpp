/*
 *  Compile & Execute: g++ -o isPalindrome isPalindrome.cpp -std=c++11 && ./isPalindrome
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

char get_token(std::string s, int& ptr, bool direction) {
    char c;
    if(direction) {
        do {
            ptr++;
        } while((ptr < s.size()) and not((s[ptr] >= 'a' and  s[ptr] <= 'z') 
        or (s[ptr] >= 'A' and  s[ptr] <= 'Z')
        or (s[ptr] >= '0' and  s[ptr] <= '9')));
        if(ptr == s.size())
            c = ' ';
    }
    else {
        do {
            ptr--;
        } while((ptr > 0) and not((s[ptr] >= 'a' and  s[ptr] <= 'z') 
        or (s[ptr] >= 'A' and  s[ptr] <= 'Z')
        or (s[ptr] >= '0' and  s[ptr] <= '9')));
        if(ptr == 0)
            c = ' ';
    }
    
    

    
    if(s[ptr] >= 'A' and  s[ptr] <= 'Z')
        c = c + 32;
    return(c);
        
}

bool isPalindrome(std::string s) {
    //int i = s.size();
    //next_token(s, i, false);
    //printf("%d %c\n", i, s[i]);
    //std::exit(0);
    
    bool tf = true;
    int32_t length = s.size();
    if(length) {
        int left_ptr = -1;
        char left_char = '\0';
        bool left_direction = true;
        int right_ptr = length;
        char right_char = '\0';
        bool right_direction = false;
        while(left_ptr < right_ptr) {
            left_char = get_token(s, left_ptr, left_direction);
            right_char = get_token(s, right_ptr, right_direction);
            //printf("%c ? %c\n", s[left_ptr], s[right_ptr]);
            printf("%c ? %c\n", left_char, right_char);
            printf("%d ? %d\n", left_ptr, right_ptr);
            
            
            if(left_char != right_char) {
                tf = false;
                break;
            }
            //else {
            //    left_ptr++;
            //    right_ptr--;
            //}
        }
    }
    return(tf);
}


int main(int argc, char** argv) {
    //std::string s = "A man, a plan, a canal: Panama";
    //std::string s = "     Rac a car";
    std::string s = "a.";
    std::cout << s << std::endl;
    
    printf("%d\n", isPalindrome(s));
    return(0);
}