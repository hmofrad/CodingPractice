/*
 * Cracking the coding interview: Problem 3.2: Stack with push, pop, and min
 * Compile and run: g++ -o set_of_stacks set_of_stacks.cpp -g -Wall -std=c++11 -fsanitize=address  && ./set_of_stacks
 * (c) Mohammad Hasanzadeh Mofrad, 2019
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

std::vector<struct Node*> set_of_stacks;
const uint32_t LIMIT = 5;
uint32_t count = 0;
struct Node{
    Node() {};
    Node(int val) : value(val), prev(nullptr) {};
    int value;
    Node* prev;
};

void push(Node** stack, int val) {
    if(*stack == nullptr) {
        *stack = new Node(val);
    }
    else {
        Node* temp = new Node(val);
        temp->prev = *stack;
        *stack = temp;
    }
}

int pop(Node** stack) {
    int val = 0;
    if(*stack) {
        Node* temp = *stack;
        *stack = (*stack)->prev;
        val = temp->value;
        delete temp;
    }
    return(val);
}

void traverse(Node* stack) {
    while(stack) {
        printf("%d ", stack->value);
        stack = stack->prev;
    }
    printf("\n");
}




void setOfStacks_push(Node** stack, int val) {
    if(((double) count/LIMIT) == set_of_stacks.size()) {
        Node* setOfStacks_top = nullptr;
        push(&setOfStacks_top, val);
        set_of_stacks.push_back(setOfStacks_top);
        *stack = setOfStacks_top;
    } 
    else {
        push(stack, val);
        set_of_stacks.back() = *stack;
    }
    count++;
}

int setOfStacks_pop(Node** stack) {
    int val = 0;
    if(set_of_stacks.size()) {
        val = pop(&set_of_stacks.back());
        *stack = set_of_stacks.back();
        count--;
        if(count % LIMIT == 0) {
            set_of_stacks.pop_back();
        }
    }
    return(val);
}


void setofStacks_traverse() {
    for(int i = set_of_stacks.size() - 1; i >= 0; i--) {
        traverse(set_of_stacks[i]);
    }
}


int main(int argc, char** argv) {
    Node* stack = nullptr;
    for(int i = 0; i < 10; i++) {
        setOfStacks_push(&stack, i);
    }
    setofStacks_traverse();
    
    for(int i = 0; i < 10; i++) {
        (void)setOfStacks_pop(&stack);
        setofStacks_traverse();
    }
    setofStacks_traverse();
    

    return(0);
}