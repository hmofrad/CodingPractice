/*
 *  Problem: partition
 *  Compile: g++ -o partition partition.cpp -std=c++11 && ./partition
 *  Execute: ./partition
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <string.h>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void traverse(ListNode* head) {
    if(head) {
        while(head) {
            //printf("[%d %p] ", head->val, head);
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    }
    
}

void insert(ListNode** head, int value) {
    if(*head) {
        while((*head)->next)
            *head = (*head)->next;
        (*head)->next = new ListNode(value);
    }
    else
        *head = new ListNode(value);
}



ListNode* remove_head(ListNode** head) {
    if((*head)->next) {
        ListNode* temp = *head;
        *head = (*head)->next;
        temp->next = NULL;
        delete temp;
    }
    else {
        delete *head;
        *head = NULL;
    }    
    return(*head);
}

void clear(ListNode** head) {
    ListNode** head1 = head;
    ListNode*  head2 = *head;
    int i = 0;
    while(*head1) {
        head2 = remove_head(head1);
        head1 = &head2;
    }
    *head = head2;
    //printf("%p %p %p\n", *head, *head1, head2);
}

ListNode* partition(ListNode* head, int x) {
    
    ListNode* list1 = head;
    ListNode* curr1 = head;
    ListNode* head1 = head;
    ListNode* last1 = NULL;
    int pos = 0;
    int skip = 0;
    int tf = true;
    if(head1) {
        while(head1) {
            if(pos >= x) {
                if(tf) {
                    last1 = head1;
                    tf = false;
                }
                curr1 = list1;
                printf("%d %d \n", head1->val, curr1->val);
                while(curr1 != last1) {
                    printf("   %d %d %d\n", curr1->val, x, skip);
                    //if(curr1->val > x) {
                    if(curr1->val > head1->val) {
                        int temp = curr1->val;
                        curr1->val = head1->val;
                        head1->val = temp;
                        curr1 = curr1->next;    
                        break;
                    }
                    else {
                        skip++;
                        curr1 = curr1->next;    
                    }
                }
                skip = 0;
                traverse(list1);
            }
            pos++;
            head1 = head1->next;
        }
        printf("\n");
        
        
        
    }
    return(list1);
}


int main(int argc, char** argv) {
    ListNode* list = NULL;
    ListNode* head = NULL;
    ListNode* curr = NULL;
    int x = 3;
    std::vector<int> v = {1, 4, 3, 2, 5, 2};
    int n = v.size();
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            insert(&head, v[i]);
            list = head;
        }
        else {
            head = list;
            insert(&head, v[i]);
        }
    }
    head = list;
    traverse(head);
    
    ListNode* list1 = partition(head, x);
    ListNode* head1 = list1;
    traverse(head1);
    clear(&head1);
    head = NULL;
    list = NULL;
    traverse(head1);
}