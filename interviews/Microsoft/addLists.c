/*
 *  Problem: https://www.geeksforgeeks.org/sum-of-two-linked-lists/
 *  Add two numbers represented by linked lists | Set 2
 *  Input:
 *        First List: 5->6->3  // represents number 563
 *        Second List: 8->4->2 //  represents number 842
 *  Output: Resultant list: 1->4->0->5  // represents number 1405
 *  Compile: g++ -o addLists addLists.c -std=c++11 -g -Wall -fsanitize=address && ./addLists
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* allocate() {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    memset(node, 0, sizeof(struct Node));
    return(node);
}

void deallocate(struct Node* node) {
    free(node);
}

void traverse(struct Node* node) {
    while(node) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Only works for the num1 and num2 are equal size */
void addLists(struct Node* num1, struct Node* num2, struct Node** res, int* carry) {
    if(num1 && num2) {
        if(*res == NULL) {
            *res = allocate();
        }
        else {
            (*res)->next = allocate();
        }
        
        
        addLists(num1->next, num2->next, &(*res)->next, carry);
        //int sum = (num1->data + num2->data) % 10;
        
        (*res)->data = ((num1->data + num2->data) % 10) + *carry;
        *carry = (num1->data + num2->data) / 10;
        printf("n1=%d n2=%d c=%d\n", num1->data, num2->data, *carry);
    }
    
    
    
}

void fixList(struct Node** res, int* carry) {
    if(*carry) {
        struct Node* last = NULL;
        while(*res) {
            int t = (*res)->data;
            (*res)->data = *carry;
            *carry = t;
            last = *res;
            *res = (*res)->next;
        }
        last->next = allocate();
        last->next->data = *carry;
    }
}


int main(int argc, char **argv){
    struct Node* num1 = allocate();
    num1->data = 5;
    num1->next = allocate();
    num1->next->data = 6;
    num1->next->next = allocate();
    num1->next->next->data = 3;
    traverse(num1);
    
    struct Node* num2 = allocate();
    num2->data = 8;
    num2->next = allocate();
    num2->next->data = 4;
    num2->next->next = allocate();
    num2->next->next->data = 2;
    traverse(num2);
    
    struct Node* res = NULL;// allocate();
    int c = 0;
    addLists(num1, num2, &res, &c);
    printf("1. %p\n", res);
    struct Node* res1 = res;
    fixList(&res1, &c);
    printf("2. %p\n", res);
    traverse(res);
    
    
    deallocate(res->next->next);
    deallocate(res->next);
    deallocate(res);
    
    deallocate(num1->next->next);
    deallocate(num1->next);
    deallocate(num1);

    deallocate(num2->next->next);
    deallocate(num2->next);
    deallocate(num2);
    
    return(0);
}
