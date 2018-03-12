/*
 *  Problem: Breadth First Search (BFS)
 *  Compile: gcc -o bfs bfs.c -g -Wall -Werror 
 *  Execute: ./bfs
 *  (c) Mohammad HMofrad, 2018
 *  (e) mohammad.hmofrad@pitt.edu       
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node *next;
};


struct Node *addEdge(int data) {
    struct Node *node =  malloc(sizeof(node));
    memset(node, 0, sizeof(node));
    node->data = data;
    return(node);
}

void traverse(struct Node *head) {
    while(head) {
        printf("<%d %p>", head->data, head);
        head = head->next;
    }
    printf("\n");
}

void my_free(struct Node *head) {
    if(head->next) {
        my_free(head->next);
    }
    free(head);
}

int main(int argc, char *argv[]) {
    struct Node *head;
    struct Node *list;
    
    int i = 0;
    int max = 10;
    head = addEdge(i);
    list = head;
    for(i = 1; i < max; i++) {
        list->next = addEdge(i);
        list = list->next;
    }
    traverse(head);
    my_free(head);
    
    return(0);
}