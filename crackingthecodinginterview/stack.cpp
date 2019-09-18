/*
 (c) Mohammad Hasanzadeh Mofrad, 2019
 (e) m.hasanzadeh.mofrad@gmail.com
 Compile and run: 
    g++ -o stack stack.cpp && ./stack
*/

#include <stdio.h>

struct Node {
    public:
        Node(){data = 0; next = nullptr;}
        Node(int d) {data = d; next = nullptr;}
        int data;
        Node* next;
};

void push(Node** top, int data) {
    if((*top) == nullptr) {
        (*top) = new Node(data);
    }
    else {
        Node* node = new Node(data);
        node->next = (*top);
        (*top) = node;
    }
}

void pick(Node* top) {
    if(top != nullptr) {
        printf("%d\n", top->data);
    }
}

void pop(Node** top) {
    if((*top) != nullptr) {
        Node* node = (*top)->next;
        delete (*top);
        (*top) = node;
    }
}

int main(int argc, char** argv) {
    printf("Hello Stack\n");
    Node* stack = nullptr;
    //printf("%d %p\n", stack->data, stack);
    push(&stack, 0);
    pick(stack);
    //printf("%d %p\n", stack->data, stack);
    
    for(int i = 1; i < 10; i++) {
        //Node* top = stack;
        push(&stack, i);
        pick(stack);
    }
    
    
    
    for(int i = 0; i < 10; i++) {
        pop(&stack);
        pick(stack);
    }
    pick(stack);
    
    return(0);
}