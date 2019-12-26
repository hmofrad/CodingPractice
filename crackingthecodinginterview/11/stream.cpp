/*
 *  Cracking the coding interview: Problem 11.8: Get the rank of a number  x
 *  Compile & run: g++ -o stream stream.cpp -g -Wall -std=c++11 -fsanitize=address && ./stream
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> numbers;
std::vector<int> counts;

void track(int x) {
    std::vector<int>::iterator it = std::find(numbers.begin(), numbers.end(), x);
    if (it != numbers.end()) {
        int index = std::distance(numbers.begin(), it);
        counts[index]++;
    }
    else {
        if(numbers.empty()) {
            numbers.push_back(x);
            counts.push_back(1);
        }
        else {
            int pos = numbers.size();
            for(uint32_t i = 0; i < numbers.size(); i++) {
                if(numbers[i] > x) {
                    pos = i;
                    break;
                }
            }
            numbers.resize(numbers.size()+1);
            counts.resize(counts.size()+1);
            for(int32_t i = numbers.size()-2; i >= pos; i--) {
                numbers[i+1] = numbers[i];
                counts[i+1]  = counts[i];
            }
            numbers[pos] = x;
            counts[pos] = 1;
        }
    }
}

int getRankofNumber(int x) {
    int rank = 0;
    for(uint32_t i = 0; i < numbers.size(); i++) {
        if(numbers[i] < x) {
            rank += counts[i];
        }
        else {
            rank += counts[i] - 1;
            break;
        }
    }
    return(rank);
}




int main(int argc, char** argv) {
    std::vector<int> stream = {5, 1, 4, 4, 5, 9, 7, 13, 3};
    for(auto s: stream) {printf("%d ", s);} printf("\n");
    for(uint32_t i = 0; i < stream.size(); i++) {
        track(stream[i]);
        for(uint32_t j = 0; j < numbers.size(); j++) {
            printf("[%d %d] ", numbers[j], counts[j]);
        }
        printf("\n");
    }
    
    for(auto s: stream) {
        printf("[%d %d] ", s, getRankofNumber(s));
    }
    printf("\n");
    
    return(0);
}