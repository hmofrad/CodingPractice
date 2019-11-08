    /*
 *  Problem: https://leetcode.com/problems/bulls-and-cows/
 *  Compile: g++ -o getHint getHint.cpp -std=c++11 -fsanitize=address && ./getHint
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
#include <unordered_set>
#include <stack>
#include <numeric>
#include <map>
#include <cmath>
#include <unordered_map>

std::string getHint(std::string secret, std::string guess) {
    int bulls = 0;
    int cows = 0;
    int n = secret.size();
    std::vector<int> counts(10);
    
    for(int i = 0; i < n; i++) {
        int digit = secret[i] - '0';
        counts[digit]++;
    }

    //for(auto c : counts)
    //    printf("%d ", c);
    //printf("\n");
    
    
    for(int i = 0; i < n; i++) {
        int digit = guess[i] - '0';
        if(secret[i] == guess[i]) {
            bulls++;
            counts[digit]--;
        }
    }

    //for(auto c : counts)
    //    printf("%d ", c);
    //printf("\n");

    
    for(int i = 0; i < n; i++) {
        int digit = guess[i] - '0';
        if(secret[i] != guess[i]) {
            if(counts[digit] > 0) {
                cows++;
                counts[digit]--;
            }
        }
    }
    
    //for(auto c : counts)
    //    printf("%d ", c);
    //printf("\n");
    
    
    std::string cipher = std::to_string(bulls) + 'A' + std::to_string(cows) + 'B';

    return(cipher);
}

int main(int argc, char **argv){
    //std::string secret = "1807";
    //std::string guess = "7810";
    
    std::string secret = "1123";
    std::string guess = "0111";
    
    
    std::string cipher = getHint(secret, guess);
    printf("secret = %s, guess = %s, cipher = %s, 1A1B\n", secret.c_str(), guess.c_str(), cipher.c_str());
    return(0);
}






