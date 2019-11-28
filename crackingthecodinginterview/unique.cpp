/*
Cracking the coding interview: Problem 1.1
Compile and run: 
        g++ -o unique1 unique1.c && ./unique1
(c) Mohammad Hasanzadeh mofrad, 2019
(e) m.hasanzadeh.mofrad@gmail.com
*/


#include <stdio.h>
#include <string.h>

#include <string>
#include <vector>
#include <algorithm>

std::vector<char> unique(std::string str) {
    std::vector<char> u;
    for(unsigned char c: str) {
        printf("%c\n", c);
        if(find(u.begin(), u.end(), c) == u.end())
            u.push_back(c);
    }
    
    for(unsigned char c: u) 
        printf("%c ", c);
    printf("\n");
    return(u);
}    

bool is_unique(std::string str) {
    printf("%s\n", str.c_str());
    int n = str.size();
    bool uniq = true;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(str[i] == str[j]) {
                uniq = false;
                break;
            }
        }
        if(not uniq)
            break;
    }
    
    return(uniq);
}


bool is_unique1(std::string str) {
    bool uniq = true;
    int n = str.size();
    if(n > 256) {
        uniq = false;
    }
    else {
        bool u[256];
        memset(u, 0, 256 * sizeof(bool));
        for(int i = 0; i < n; i++) {
            if(u[str[i]]) {
                uniq = false;
                break;
            }
            u[str[i]] = true;
        }
    }
    return(uniq);
}

bool is_unique2(std::string str) {
    bool uniq = true;
    unsigned char checker = 0;
    printf("%d 0x%02x\n", checker, checker);
    checker = 0;
    printf("%d 0x%02x\n", checker, checker);
    unsigned char c = str[0];
    unsigned char flag =  c;
    printf("%d %c %d %d\n", c, c, c%8, c/8);
    checker = checker | flag;
    printf("%d 0x%02x\n", checker, checker);
    unsigned char m = 1;
    for(int i = 0; i < 8; i++) {
        
        printf("%x %x\n", m, c & m);
        m <<= 1;
    }
        
    
    exit(0);
    return(uniq);
    
}



int main(int argc, char** argv) {
    std::string str = "Helo, Wrd!";
    //std::string str = "Hello, World!";
    printf("%s\n", str.c_str());
    std::vector<char> u = unique(str);
//    printf("is_uniq(%s) ? %d/%d/%d\n", str.c_str(), is_unique(str), is_unique1(str), is_unique2(str));
printf("is_uniq(%s) ? %d\n", is_unique2(str));
    return(0);
}