/*
 *  Problem: https://www.geeksforgeeks.org/flattening-a-linked-list/
 *  Flattening a Linked List
 *  Given a linked list where every node represents a linked list and contains two pointers of its type:
 *  (i) Pointer to next node in the main list (we call it ‘right’ pointer in below code)
 *  (ii) Pointer to a linked list where this node is head (we call it ‘down’ pointer in below code).
 *  All linked lists are sorted. See the following example
 *
 *     5 -> 10 -> 19 -> 28
 *     |    |     |     |
 *     V    V     V     V
 *     7    20    22    35
 *     |          |     |
 *     V          V     V
 *     8          50    40
 *     |                |
 *     V                V
 *     30               45
 *  Write a function flatten() to flatten the lists into a single linked list. 
 *  The flattened linked list should also be sorted. 
 *  For example, for the above input list, output list should be 5->7->8->10->19->20->22->28->30->35->40->45->50.
 *  Compile: gcc -o flattingLinkedList flattingLinkedList.c -g -Wall -fsanitize=address && ./flattingLinkedList   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* right;
    struct Node* down;
};

struct Node* allocate(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->right = NULL;
    node->down = NULL;
    return(node);
}

void deallocate(struct Node* node) {
    if(node) free(node);
}

void enqueue_r(struct Node** head, int data) {
    struct Node* curr = *head;
    if(!curr) {
        *head = allocate(data);
    }
    else {
        while(curr->right) {
            curr = curr->right;
        }
        curr->right = allocate(data);
    }
}

void enqueue_d(struct Node** head, int data) {
    struct Node* curr = *head;
    if(!curr) {
        *head = allocate(data);
    }
    else {
        while(curr->down) {
            curr = curr->down;
        }
        curr->down = allocate(data);
    }
}

void dequeue_r(struct Node** head) {
    if(*head) {
        struct Node* node = *head;
        *head = (*head)->right;
        deallocate(node);
    }
}

void dequeue_d(struct Node** head) {
    if(*head) {
        struct Node* node = *head;
        *head = (*head)->down;
        deallocate(node);
    }
}

void create_list(struct Node** head) {
    enqueue_r(head, 5);
    enqueue_d(head, 7);
    enqueue_d(head, 8);
    enqueue_d(head, 30);
    
    enqueue_r(head, 10);
    enqueue_d(&(*head)->right, 20);
    
    enqueue_r(head, 19);
    enqueue_d(&(*head)->right->right, 22);
    enqueue_d(&(*head)->right->right, 50);
    
    enqueue_r(head, 28);
    enqueue_d(&(*head)->right->right->right, 35);
    enqueue_d(&(*head)->right->right->right, 40);
    enqueue_d(&(*head)->right->right->right, 45);
    
}

void traverse(struct Node* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->right;
    }
    printf("\n");
}

void traverse_list(struct Node* head) {
    while(head) {
        printf("%d[", head->data);
        if(head->down) {
            struct Node* head_d = head->down;
            while(head_d) {
                printf("%d ", head_d->data);
                head_d = head_d->down;
            }
            printf("] ");
        }
        head = head->right;
    }
    printf("\n");
}

void delete_list(struct Node** head) {
    while(*head) {
        while((*head)->down) {
            dequeue_d(&(*head)->down);
        }
        dequeue_r(head);
    }
}


void flatten_list(struct Node** head) {
    struct Node* curr_r = *head;
    while(curr_r) {
        printf("%d ", curr_r->data);
        if(curr_r->down) {
            struct Node* curr_d = curr_r->down;
            while(curr_d->down) {
                curr_d->right = curr_d->down;
                curr_d->down = NULL;
                curr_d = curr_d->right;
            }
            curr_d->right = curr_r->right;
            curr_r->right = curr_r->down;
            curr_r->down = NULL;
        }
        curr_r = curr_r->right;
        printf("\n");
    }
}

int main(int argc, char **argv){
    struct Node* head = NULL;
    create_list(&head);
    traverse_list(head);
    flatten_list(&head);
    traverse(head);
    delete_list(&head);
    return(0);
}
