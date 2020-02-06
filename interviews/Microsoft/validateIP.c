/*
 *  Problem: https://www.geeksforgeeks.org/program-to-validate-an-ip-address/
 *  Program to validate an IP address
 *  Compile: gcc -o validateIP validateIP.c -g -Wall -fsanitize=address && ./validateIP    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_valid_char(char c) {
    return(((c >= '0') && (c <= '9')) || (c == '.'));
}

int is_digit(char c) {
    return((c >= '0') && (c <= '9'));
}

int to_int(char c) {
    return(c-'0');
}

int validate_ip(char* ip) {
    int valid = 0;
    int len = strlen(ip);
    
    if(len > 15) {
        return(0);
    }
    
    /*
    for(int i = 0; i < len; i++) {
        char c = ip[i];
        if(is_valid_char(ip[i])) {
            return(0);
        }
    }
    */
    /*
    char* c = ip;
    while(*c) {
        if(!is_valid_char(*c)) {
            return(0);
        }
        c++;
    }
    */
    
    /*
    int j = 0;
    char b[len+1];
    memset(b, 0, sizeof(b));
    int k = 0;
    //char* c = ip;
    //while(*c) {
        
      
    for(int i = 0; i < len; i++) {
        char c = ip[i];
        b[k] = ip[i];
        k++;
        if(!is_valid_char(c)) {
            return(0);
        }
        
        if((c == '.') || ((i+1) == len)) {
            printf(">>%d %d %d %d\n", i, j, i-j, i-j+1);
            if((i+1) == len) {
                if(((i-j+1) > 0) && ((i-j+1) <= 3)) {
                    j = i+1;
                    for(int l = 0; l < k-1; l++) {
                        if((l == 0) && (b[l] > 2)) return(0);
                        if(((l == 1) || (l == 2)) && (b[l] > 5)) return(0);
                    }
                    k = 0;
                }
                else {
                    return(0);
                }
            }
            else {
                if(((i-j) > 0) && ((i-j) <= 3)) {
                    j = i+1;
                    for(int l = 0; l < k-1; l++) {
                        printf(">>%c %d\n", b[l], l);
                        if((l == 0) && (b[l] > '2')) return(0);
                        if(((l == 1) || (l == 2)) && (b[l] > '5')) return(0);
                    }
                    k = 0;
                }
                else {
                    return(0);
                }
            }
        }
        printf("%c %c %d\n", c, c, is_valid_char(c));
        //c++;
    }
    */
    char* c = ip;
    int d = 0;
    int n = 0;
    int f = 10;
    while(*c) {
        if(is_digit(*c)) {
            d = to_int(*c);
            n = n*f;
            n += d;
            if(*(c+1) == '\0') {
                if((n > 255) || (n == 0)) return(0);
            }
        }
        else {
            if((n > 255) || (n == 0)) return(0);
            
            
            d = -1;
            n = 0;
        }
        printf("%c %d %d %d\n", *c, *c, d, n);
        c++;
    }
        
    
    
    return(1);
}

int main(int argc, char **argv){
   char* ip = "1.234.122.255";
   int ret = validate_ip(ip);
    printf("%s ? %d\n", ip, ret);
    return(0);
}
