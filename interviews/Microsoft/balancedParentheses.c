/*
 *  Problem: https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
 *  Check for balanced parentheses in an expression
 *  Compile: gcc -o balancedParentheses balancedParentheses.c -g -Wall -fsanitize=address && ./balancedParentheses   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node {
    char data;
    struct Node* prev;
};

struct Node* allocate(char data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    return(node);
}

void deallocate(struct Node* node) {
    if(node) free(node);
}

void push(struct Node** top, char data) {
    
    if(!*top) {
        *top = allocate(data);        
    }
    else {
        struct Node* node = allocate(data);
        node->prev = *top;
        *top = node;
    }
}

void pop(struct Node** top) {
    if(*top) {
        struct Node* node = *top;
        *top = (*top)->prev;
        deallocate(node);
    }
}

char peek(struct Node* top) {
    char c = '\0';
    if(top) {
        c = top->data;
    }
    return(c);
}

char isBalanced(char input[]) {
    char ret = 1;
    int len = strlen(input);

    struct Node* stack = NULL;
    push(&stack, input[0]);
    for(int i = 1; i < len; i++) {
        if((input[i] == '(') || (input[i] == '[') || (input[i] == '{')) {
            push(&stack, input[i]);
        }
        else {
            char c = peek(stack);
            if(((c == '(') && (input[i] == ')')) ||
               ((c == '[') && (input[i] == ']')) ||
               ((c == '{') && (input[i] == '}'))) {
                   pop(&stack);
            }
            else {
                ret = 0;
            }
        }
    }
    
    
    
    return(ret);    
}

int main(int argc, char** argv){
    char input[] = "[()]{}{[()()]()}";
    char out = isBalanced(input);
    printf("? %d\n", out);
    return(0);
}
