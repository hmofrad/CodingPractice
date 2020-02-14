/*
 *  Problem: https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
 *  Reverse a Linked List in groups of given size
 *  Input: 1->2->3->4->5->6->7->8->NULL, K = 3
 *  Output: 3->2->1->6->5->4->8->7->NULL
 *  Compile: gcc -o reverseKnodes reverseKnodes.c -g -Wall -fsanitize=address && ./reverseKnodes   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* allocate(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return(node);
}

void deallocate(struct Node* node) {
    if(node) free(node);
}

void enqueue(struct Node** head, int data) {
    struct Node* current = *head;
    if(current == NULL) {
        *head = allocate(data);
    }
    else {
        while(current->next) current = current->next;
        current->next = allocate(data);
    }
}

void dequeue(struct Node** head) {
    if(*head) {
        struct Node* node = *head;
        *head = (*head)->next;
        deallocate(node);
    }
}

void traverse(struct Node* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;     
}


struct Node* reverse1(struct Node* head, int k) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    int i = 0;
    while(curr && i < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }
    //*head = prev;
    //printf("%p %p %p\n", prev, curr, next);
    if(next != NULL) {
        //printf("1.\n");
        //traverse(prev);
        //printf("2.%d %d\n", (*head)->data);
        //printf("%d %d %d\n", prev->data, curr->data, next->data);
        head->next = reverse1(next, k);
        //printf("3.\n");
        //curr->next = next;
        //traverse(prev);
    }
    return(prev);
    //else {
    //    *head = prev;
    //}
}


int main(int argc, char** argv){
    int k = 3;
    struct Node* queue = NULL;
    for(int i = 0; i < 10; i++) enqueue(&queue, i);
    
    traverse(queue);
    //reverse(&queue);
    queue = reverse1(queue, k);
    //printf("xxxx\n");
    traverse(queue);
    
    for(int i = 0; i < 10; i++) dequeue(&queue);
    
    return(0);
}
