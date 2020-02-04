/*
 *  Problem: https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
 *  Detect and Remove Loop in a Linked List
 *  Compile: gcc -o detectAndRemoveLoop detectAndRemoveLoop.c -g -Wall -fsanitize=address && ./detectAndRemoveLoop    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* allocate(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    memset(node, 0, sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return(node);
}

void deallocate(struct Node* node) {
    free(node);
}

void enqueue(struct Node** head, int data) {
    if(*head) {
        while((*head)->next) {
            *head = (*head)->next;
        }
        (*head)->next = allocate(data);
    }
    else {
        *head = allocate(data);
    }
}

void dequeue(struct Node** head) {
    if(*head) {
        struct Node* node = *head;
        *head = (*head)->next;
        deallocate(node);
    }
}

struct Node* front(struct Node* head) {
    struct Node* front = NULL;
    if(head) {
        front = head;
    }
    return(front);
}

void traverse(struct Node* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int detectAndRemoveLoop(struct Node** head) {
    struct Node* head1 = *head;
    int updated = 0;
    struct Node* vec[10];
    memset(vec, 0, sizeof(vec));
    
    int i = 0;
    int j = 0;
    while(head1) {
        for(j = 0; j < i; j++) {
            if(vec[j] == head1) {
                updated = 1;
                break;
            }
        } 
        
        if(updated == 0) {
            vec[i] = head1;
            head1 = head1->next;
            i++;
        }
        else {
            head1 = *head;
            int k = 0;
            while(head1 && k != (i-1)) {
                head1 = head1->next;
                k++;
            }   

            head1->next = NULL;
            head1 = *head;
            break;
        }
    }
    return(updated);
}

/*

Input:
1 --> 2 --> 3
      ^     |
      |     v
      5 <-- 4

Output:
1 --> 2 --> 3 --> 4 --> 5 --> null

*/

int main(int argc, char **argv){
    
    struct Node* head = NULL;
    struct Node* curr = NULL;
    enqueue(&head, 1);
    curr = head;
    enqueue(&curr, 2);
    curr = head;
    enqueue(&curr, 3);
    curr = head;
    enqueue(&curr, 4);
    curr = head;
    enqueue(&curr, 5);
    head->next->next->next->next->next = head->next;
    //traverse(head);
    curr = head;
    int ret = detectAndRemoveLoop(&curr);
    printf("%d\n", ret);
    traverse(head);
    
    /*
    traverse(head);

    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    */
    return(0);
}
