/*
 *  Problem: https://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
 *  Clone a linked list with next and random pointer
 *  Compile: gcc -o cloneLinkedList cloneLinkedList.c -g -Wall -fsanitize=address && ./cloneLinkedList    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* next1;
};

struct Node* allocate(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    if(node == NULL) {
        printf("ERROR: Allocating data\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    node->next1 = NULL;
    return(node);
}

void deallocate(struct Node* node) {
    free(node);
}

void traverse(struct Node* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void traverse1(struct Node* head) {
    while(head) {
        printf("[%d ", head->data);
        if(head->next1) {
            printf("%d ]", head->next1->data);    
        }
        else {
            printf("]" );
        }
        head = head->next;
    }
    printf("\n");
}


struct Node* copy(struct Node* head) {
    struct Node* curr = head;
    struct Node* head1 = NULL;
    struct Node* curr1 = NULL;
    while(curr) {
        if(curr1 == NULL) {
            //curr1 = allocate(curr->data);
            head1 = curr;
            head1->next1 = curr->next1;
            curr1 = head1;
        }
        else {
            curr1->next = curr;
            curr1->next->next1 = curr1->next1;
            curr1 = curr1->next;
        }
        curr = curr->next;
    }
    
    return(head1);
}


/*
 --------> -------->
1 -> 2 -> 3 -> 4 -> 5 -> 6
  <-        <-               
     <--------------
*/

int main(int argc, char **argv){
    struct Node* head = allocate(1);
    head->next = allocate(2);
    head->next->next = allocate(3);
    head->next->next->next = allocate(4);
    head->next->next->next->next = allocate(5);
    head->next->next->next->next->next = allocate(6);
    
    head->next1 = head->next->next;
    head->next->next->next1 = head->next->next->next->next;
    head->next->next1 = head;
    head->next->next->next->next1 = head->next->next;
    head->next->next->next->next->next1 = head->next;
    
    
    
    
    struct Node* head1 = copy(head);
    traverse1(head1);
    
    free(head->next->next->next->next->next);
    free(head->next->next->next->next);
    free(head->next->next->next);
    free(head->next->next);
    free(head->next);
    free(head);
    
    return(0);
}
