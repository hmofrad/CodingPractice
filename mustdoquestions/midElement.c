/*
 *  Problem: https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
 *  Reverse Find the middle of a given linked list
 *  Compile: gcc -o midElement midElement.c -g -Wall -fsanitize=address && ./midElement   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

int mid(struct Node* root) {
    int m = 0;
    if(root) {
        struct Node* slow = root;
        struct Node* fast = root->next;
        while(slow && (fast && fast->next)) {
            slow = slow->next;
            fast = fast->next->next;
            //if(fast->next) 
                
            //else break;
        }
        printf("%p\n", fast);
        m = (fast) ? (slow->data + slow->next->data)/2 : slow->data;
        
    }
    return(m);
}


int main(int argc, char** argv){
    struct Node* root = (struct Node*) malloc(sizeof(struct Node));
    root->data = 1;
    root->next = (struct Node*) malloc(sizeof(struct Node));
    root->next->data = 2;
    root->next->next = (struct Node*) malloc(sizeof(struct Node));
    root->next->next->data = 3;
    root->next->next->next = (struct Node*) malloc(sizeof(struct Node));
    root->next->next->next->data = 4;
    root->next->next->next->next = (struct Node*) malloc(sizeof(struct Node));
    root->next->next->next->next->data = 5;
    root->next->next->next->next->next = (struct Node*) malloc(sizeof(struct Node));
    root->next->next->next->next->next->data = 6;
    root->next->next->next->next->next->next = (struct Node*) malloc(sizeof(struct Node));
    root->next->next->next->next->next->next->data = 7;
    root->next->next->next->next->next->next->next = NULL;
    
    printf("Middle=%d\n", mid(root));
    
    free(root->next->next->next->next->next->next);
    free(root->next->next->next->next->next);
    free(root->next->next->next->next);
    free(root->next->next->next);
    free(root->next->next);
    free(root->next);
    free(root);
    
    return(0);
}
