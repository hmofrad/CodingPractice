/*
 * Cracking the coding interview: Problem 3.4: Implement a queue using 2 stacks
 * Compile and run: g++ -o queue_using_2stacks queue_using_2stacks.cpp -g -Wall -std=c++11 -fsanitize=address  && ./queue_using_2stacks
 * (c) Mohammad Hasanzadeh Mofrad, 2019
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

void push(std::vector<int>& top, int value) {
    top.push_back(value);
}

int pop(std::vector<int>& top) {
    int value = top.back();
    top.pop_back();
    return(value);
}

void enqueue(std::vector<int>& stack0, std::vector<int>& stack1, int value) {
    if(stack0.empty() and stack1.empty()) {
        push(stack0, value);
    }
    else {
     //   if(not stack1.empty()) {
            uint32_t sz1 = stack1.size();
            for(uint32_t i = 0; i < sz1; i++) {
                push(stack0, pop(stack1));
            }
            push(stack1, value);
            uint32_t sz0 = stack0.size();
            for(uint32_t i = 0; i < sz0; i++) {
                push(stack1, pop(stack0));
            }
          /*  
        }
        else {
            uint32_t sz0 = stack0.size();
            for(uint32_t i = 0; i < sz0; i++) {
                push(stack1, pop(stack0));
            }
            push(stack0, value);
            uint32_t sz1 = stack1.size();
            for(uint32_t i = 0; i < sz1; i++) {
                push(stack0, pop(stack1));
            }
        }
        */
    }
    
    printf("\nenq:%d: %lu %lu\n",value, stack0.size(), stack1.size());    
    printf("stack0: ");
    for(int32_t i = stack0.size()-1; i >= 0; i--) {
        printf("%d ", stack0[i]);
    }
    printf("\n");
    printf("stack1: ");
    for(int32_t i = stack1.size()-1; i >= 0; i--) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
    
}

int dequeue(std::vector<int>& stack0, std::vector<int>& stack1) {
    printf("\ndeq: %lu %lu\n", stack0.size(), stack1.size());    
    printf("stack0: ");
    for(int32_t i = stack0.size()-1; i >= 0; i--) {
        printf("%d ", stack0[i]);
    }
    printf("\n");
    printf("stack1: ");
    for(int32_t i = stack1.size()-1; i >= 0; i--) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
    
    
    if(stack0.empty() and stack1.empty()) {
        return(-1);
    }
    else {
        if(not stack1.empty()) {
            return(pop(stack1));
        }
        else {
            return(pop(stack0));
        }
    }
    return(-1);
}


int main(int argc, char** argv) {
    std::vector<int> stack0;   
    std::vector<int> stack1;
    
    
    
    
    for(int i = 0; i < 5; i++) {
        enqueue(stack0, stack1, i);
    }
    

    
    
    for(int i = 0; i < 5; i++) {
        int v = dequeue(stack0, stack1);
        enqueue(stack0, stack1, i);
        printf("%d ", v);
    }
    printf("\n");
    
    for(int i = 0; i < 5; i++) {
        int v = dequeue(stack0, stack1);
        printf("%d ", v);
    }
    printf("\n");
    
    
    
    
    return(0);
}