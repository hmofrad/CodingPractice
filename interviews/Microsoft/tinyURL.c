/*
 *  Problem: https://www.geeksforgeeks.org/how-to-design-a-tiny-url-or-url-shortener/
 *  How to design a system that takes big URLs like “https://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/” and convert them into a short 6 character URL. 
 *  It is given that URLs are stored in the database and every URL has an associated integer id.
 *  For example, for the above input list, output list should be 5->7->8->10->19->20->22->28->30->35->40->45->50.
 *  Compile: gcc -o tinyURL tinyURL.c -g -Wall -fsanitize=address && ./tinyURL   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char map[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int map_size = 62;
const int max_url_len = 6;

char* hash(int id) {
    
    char* url = (char*) malloc(max_url_len+1);
    memset(url, 0, sizeof(char) * (max_url_len+1));
    
    int i = 0;
    while(id) {
        url[i] = map[id%map_size];
        i++;
        id /= map_size;
    }
    
    for(i = 0; i < max_url_len; i++) {
        url[i] = url[max_url_len-1-i];
    }

    return(url);
}

int unhash(char url[]) {
    int id = 0;

    for(int i = 0; i < max_url_len; i++) {
        if(url[i] >= 'a' && url[i] <= 'z') {
            id = (id*map_size) + url[i] - 'a';
        }
        else if(url[i] >= 'A' && url[i] <= 'Z') {
            id = (id*map_size) + url[i] - 'A' + 26;
        }
        else if(url[i] >= '0' && url[i] <= '9') {
            id = (id*map_size) + url[i] - '0' + 56;
        }
        //printf("%d %c %d\n", i, url[i], );
    }
    return(id);
}

int main(int argc, char** argv){
    int id = 1234587908;
    char* url = hash(id);
    int id1 = unhash(url);
    printf("%d --> %s --> %d\n", id, url, id1);
    free(url);
    return(0);
}
