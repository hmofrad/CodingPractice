/*
 *  Problem: https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
 *  Function to check if a singly linked list is palindrome
 *  Compile: gcc -o palindromeList palindromeList.c -g -Wall -fsanitize=address && ./palindromeList   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

struct Node {
    char data;
    struct Node* next;
};

void traverse(struct Node* root) {
    if(root) {
        printf("%c ", root->data);
        traverse(root->next);
    }
}

struct Node_Stack {
    char data;
    struct Node_Stack* prev;
};

struct Node_Stack* allocate(char data) {
    struct Node_Stack* node = (struct Node_Stack*) malloc(sizeof(struct Node_Stack));
    node->data = data;
    node->prev = NULL;
    return(node);
}

void deallocate(struct Node_Stack* node) {
    if(node) free(node);
}

void push(struct Node_Stack** top, char data) {
    if(*top == NULL) {
        *top = allocate(data);
    }
    else {
        struct Node_Stack* node = allocate(data);
        node->prev = *top;
        *top = node;
    }
}

void pop(struct Node_Stack** top) {
    if(*top) {
        struct Node_Stack* node = *top;
        *top = (*top)->prev;
        deallocate(node);
    }
}




char isPalindrome(struct Node* root) {
    char ret = 1;
    if(root) {
        struct Node_Stack* s = NULL;
        struct Node* slow = root;
        struct Node* fast = root->next;
        int i = 0;
        while(slow && fast) {
            push(&s, slow->data);
            slow = slow->next;
            i++;
            
            if(fast->next)
                fast = fast->next->next;
            else 
                break;
        }
        printf("%c %d %c %p\n", slow->data, i, s->data, fast);
        
        if(fast == NULL) slow = slow->next;
        
        while(slow && s) {
            if(slow->data != s->data) {
                ret = 0;
                break;
            }
            slow = slow->next;
            pop(&s);
        }
        
        while(s) pop(&s);
    }
    else {
        ret = 0;
    }
    
    return(ret);
}


int main(int argc, char** argv){
    struct Node* root = (struct Node*) malloc(sizeof(struct Node));
    root->data = 'R';
    root->next = (struct Node*) malloc(sizeof(struct Node));
    root->next->data = 'A';
    root->next->next = (struct Node*) malloc(sizeof(struct Node));
    root->next->next->data = 'D';
    root->next->next->next = (struct Node*) malloc(sizeof(struct Node));
    root->next->next->next->data = 'A';
    //root->next->next->next->next = NULL;
    root->next->next->next->next = (struct Node*) malloc(sizeof(struct Node));
    root->next->next->next->next->data = 'R';
    root->next->next->next->next->next = NULL;
    
    traverse(root);
    printf("\n");
    
    char is = isPalindrome(root);
    printf("? %d\n", is);
    
    free(root->next->next->next->next);
    free(root->next->next->next);
    free(root->next->next);
    free(root->next);
    free(root);
    
    return(0);
}
