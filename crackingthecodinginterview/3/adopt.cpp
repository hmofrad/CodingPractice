/*
 * Cracking the coding interview: Problem 3.7: Adopt the oldest dog, cat or any of them
 * Compile and run: g++ -o adopt adopt.cpp -g -Wall -std=c++11 -fsanitize=address  && ./adopt
 * (c) Mohammad Hasanzadeh Mofrad, 2019
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

void enqueue(std::vector<int>& head, int value) {
    head.push_back(value);
}

int dequeueAny(std::vector<int>& head) {
    int value = -1;
    if(!head.empty()) {
        value = head[0];
    }
    head.erase(head.begin());
    return(value);
}

int dequeueDog(std::vector<int>& head) {
    int value = -1;
    if(!head.empty()) {
        for(uint32_t i = 0; i < head.size(); i++) {
            if((head[i] % 2) == 0) { // For dogs
                value = head[i];
                head.erase(head.begin()+i);
                break;
            }
        }
    }
    return(value);
}

void print(std::vector<int> head) {
    for(auto n: head) {
        printf("%d ", n);
    }
    printf("\n");
}


int main(int argc, char** argv) {
    std::vector<int> queue;   
    
    for(int i = 0; i < 10; i++) {
        enqueue(queue, i);
    }
    print(queue);
    int v= dequeueAny(queue);
    v= dequeueAny(queue);
    v= dequeueAny(queue);
    v= dequeueDog(queue);
    printf("%d\n", v);
    print(queue);
    
    return(0);
}