/*
 *  Cracking the coding interview: Problem 18.2: Shuffle cards
 *  Compile & run: g++ -o shuffle shuffle.cpp -g -Wall -std=c++11 -fsanitize=address  && ./shuffle
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>

int my_rand(int min, int max) {
    
    return(min + (rand() % (max - min + 1)));
}

void shuffle(std::vector<int>& cards) {
    for(uint32_t i = 0; i < cards.size(); i++) {
        int k = my_rand(0, i);
        std::swap(cards[k], cards[i]);
        printf("%d %d\n", i, k);
    }
}

int main(int argc, char** argv) {
    srand(time(NULL));
    std::vector<int> cards = {1, 2, 3, 4, 5};
    
    shuffle(cards);
    
    for(auto c: cards) {
        printf("%d ", c);
    }
    printf("\n");
    
    return(0);
}