/*
 *  Problem: addTwoNumbers
 *  Compile: gcc -o addTwoNumbers addTwoNumbers.c -g -Wall -Werror 
 *  Run ./addTwoNumbers
 *  (c) Mohammad H-Mofrad
 *  (e) mohammad.hmofrad@pitt.edu
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *l1_head = l1;
    struct ListNode *l2_head = l2;
    while(l1_head)
    {
        printf("%d ", l1_head->val);
        l1_head = l1_head->next;
    }
    printf("\n");
    
    while(l2_head)
    {
        printf("%d ", l2_head->val);
        l2_head = l2_head->next;
    }
    printf("\n");

    l1_head = l1;
    l2_head = l2;    
    struct ListNode *l = NULL;
    struct ListNode *l_head = NULL;
    
    char first = 0;
    char carriage = 1;
    while(l1_head && l2_head)
    {
        if(!first)
        {
            l = malloc(sizeof(struct ListNode));
            memset(l, 0, sizeof(struct ListNode));
            l_head = l;
            first = 1;
        }
        else
        {
            l->next = malloc(sizeof(struct ListNode));
            l = l->next;
            memset(l, 0, sizeof(struct ListNode));
        }
        
        if(!carriage)
        {
            l->val = 1;
            carriage = 1;
        }
        l->val += l1_head->val + l2_head->val;
        
        
        if(l->val > 9)
        {
            l->val = 10 - l->val;
            carriage = 0;
        }
        printf("%d ", l->val);
        l1_head = l1_head->next;
        l2_head = l2_head->next;
    }
    printf("\n");
    // if cariage then ....
    
    return(l_head);
}


int main(int argc, char *argv[]) {
    /* 243 */
    struct ListNode *l1 = malloc(sizeof(struct ListNode));
    memset(l1, 0, sizeof(struct ListNode));
    struct ListNode *l1_head = l1;
    l1->val = 3;
    
    l1->next = malloc(sizeof(struct ListNode));
    l1 = l1->next;
    memset(l1, 0, sizeof(struct ListNode));
    l1->val = 4;
    
    l1->next = malloc(sizeof(struct ListNode));
    l1 = l1->next;
    memset(l1, 0, sizeof(struct ListNode));
    l1->val = 2;
    
    /* 564 */
    struct ListNode *l2 = malloc(sizeof(struct ListNode));
    memset(l2, 0, sizeof(struct ListNode));
    struct ListNode *l2_head = l2;
    l2->val = 4;
    
    l2->next = malloc(sizeof(struct ListNode));
    l2 = l2->next;
    memset(l2, 0, sizeof(struct ListNode));
    l2->val = 6;
    
    l2->next = malloc(sizeof(struct ListNode));
    l2 = l2->next;
    memset(l2, 0, sizeof(struct ListNode));
    l2->val = 5;
    
    struct ListNode *l = addTwoNumbers(l1_head, l2_head);
    struct ListNode *l_head = l;
    while(l_head)
    {
        printf("%d ", l_head->val);
        l_head = l_head->next;
    }
    printf("\n");
    
    //free();
    
    return(0);
}