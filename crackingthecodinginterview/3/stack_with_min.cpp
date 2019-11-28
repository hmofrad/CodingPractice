/*
 * Cracking the coding interview: Problem 3.2: Stack with push, pop, and min
 * Compile and run: g++ -o stack_with_min stack_with_min.cpp && ./stack_with_min
 * (c) Mohammad Hasanzadeh Mofrad, 2019
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>



struct Node{
    Node() {};
    Node(int val) : value(val), prev(nullptr) {};
    int value;
    int min;
    Node* prev;
};

//Node* minimum;

void push(Node** stack, int val) {
    if(*stack) {
        Node* temp = new Node(val);
        temp->prev = *stack;
        *stack = temp;
        
        if((*stack)->value < (*stack)->prev->min)
            (*stack)->min = val;
    }
    else {
        *stack = new Node(val);
        (*stack)->min = val;
    }
}

int pop(Node** stack) {
    int val = 0;
    if(*stack) {
        Node* temp = *stack;
        *stack = (*stack)->prev;
        int val = temp->value;
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

int min(Node* stack) {
    return(stack->min);
}

int main(int argc, char** argv) {
    Node* stack = nullptr;
    for(int i = 0; i < 10; i++) {
        //printf("%d\n", i);
        push(&stack, i);
        traverse(stack);
    }
    for(int i = 0; i < 5; i++) {
        //printf("%d\n", i);
        push(&stack, -i);
        traverse(stack);
    }
    
    //traverse(stack);
    
    int mini = min(stack);
    printf("Minimum= %d\n", mini);
    
    for(int i = 0; i < 10; i++) {
        int v = pop(&stack);
        //delete curr;
        traverse(stack);
        printf("%d %d\n", v, min(stack));
    }
    
    
    //Node* stack = new Node(0);
    //Node* head = new Node(1);
    //curr->prev = head;
    
    //printf("Hello\n");
    return(0);
}