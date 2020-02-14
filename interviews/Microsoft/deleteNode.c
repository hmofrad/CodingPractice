/*
 *  Problem: https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1
 *  You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. 
 *  The task is to delete the node. Pointer/ reference to head node is not given. 
 *  Compile: gcc -o deleteNode deleteNode.c -g -Wall -fsanitize=address && ./deleteNode   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteNode(struct Node** node) {
    struct Node* temp = (*node)->next;
    free(*node);
    *node = temp;
}

int main(int argc, char** argv){
    struct Node* q = (struct Node*) malloc(sizeof(struct Node));
    q->data = 10;
    q->next = (struct Node*) malloc(sizeof(struct Node));
    q->next->data = 20;
    q->next->next = (struct Node*) malloc(sizeof(struct Node));
    q->next->next->data = 30;
    q->next->next->next = (struct Node*) malloc(sizeof(struct Node));
    q->next->next->next->data = 40;
    q->next->next->next->next = NULL;
    
    traverse(q);
    deleteNode(&(q->next));
    traverse(q);
    
    
    free(q->next->next->next);
    free(q->next->next);
    free(q->next);
    free(q);
    
    return(0);
}
