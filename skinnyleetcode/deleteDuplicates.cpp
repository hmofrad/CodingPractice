/*
 *  Problem: deleteDuplicates
 *  Compile: g++ -o deleteDuplicates deleteDuplicates.cpp -std=c++11 && ./deleteDuplicates
 *  Execute: ./deleteDuplicates
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


ListNode* deleteDuplicates(ListNode* head) {
    ListNode* list = NULL;
    ListNode* curr = head;
    ListNode* head1 = NULL;
    //traverse(list);
    int j = 0;
    if(curr) {
        //insert(&list, curr->val);
        list = new ListNode(curr->val);
        curr = curr->next;
        while(curr) {
            bool tf = true;
            int v = curr->val;
            head1 = list;    
            while(head1) {
                if(head1->val == v) {
                    tf = false;
                    break;
                }
                head1 = head1->next;
            }
            if(tf) {
                head1 = list;   
                //insert(&head1, curr->val);
                while(head1->next) {
                    head1 = head1->next;
                }
                head1->next = new ListNode(v);
            }
            curr = curr->next; 
        }
    }
    //else {
        
    //}
    return(list);
    //traverse(list);  
    
    
    //exit(0);
    /*
    int i = 0;
    if(curr) {
        while(curr->next) {
            //ListNode* head1 = list;
            //head1 = list;
            //traverse(head1);
            //printf("[%d %p] ? [%d %p]\n", curr->val, curr, curr->next->val, curr->next);
            if(curr->val == curr->next->val) {
                if(list == curr) {
                    list = curr->next;
                    
                }
                else {
                    head1 = list;
                    while(head1->next != curr)
                        head1 = head1->next;
                    head1->next = curr->next;
                }
                    
                
                //if(list->next == curr) {
                //    list->next = curr->next;
                //}
                ListNode* temp = curr;
                curr = curr->next;
                temp->next = NULL;
                delete temp;
            }
            else
                curr = curr->next;
            //i++;
            //if(i == 5)
            //    exit(0);
        }
    }
    return(list);
    */
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



int main(int argc, char** argv) {
    ListNode* list = NULL;
    ListNode* head = NULL;
    ListNode* curr = NULL;
    
    for(int i = 0; i < 4; i++) {
        if(i == 0) {
            insert(&head, i);
            list = head;
            insert(&head, i);
            head = list;
            insert(&head, i);
            head = list;
        }
        else {
            head = list;
            insert(&head, i);
            head = list;
            insert(&head, i);            
        }
    }
    head = list;
    insert(&head, 3);   
    head = list;
    traverse(head);
    ListNode* list1 = deleteDuplicates(head);
    ListNode* head1 = list1;
    traverse(head1);
    printf("%p %p\n", head, head1);
    clear(&head1);
    head = NULL;
    list = NULL;
    //printf("%p %p\n", head, head1);
    //printf("%p\n", head1);
    traverse(head1);
}