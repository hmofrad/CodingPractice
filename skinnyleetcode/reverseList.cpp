/*
 *  Problem: https://leetcode.com/problems/reverse-linked-list/
 *  Compile: g++ -o reverseList reverseList.cpp -std=c++11 && ./reverseList
 *  Execute: ./reverseList
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
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


//  Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode* next;
      ListNode(int x) : val(x), next(NULL) {}
	  //void enqueue(struct ListNode *head,  int value);
	  //void dequeue();
	  //void traverse();
 };
 
 void enqueue(struct ListNode **head, int value){
	//printf("val=%d\n", value);
	if(*head == nullptr) {
		
		*head = new struct ListNode(value);
		//printf("> %p\n", *head);		
	}
	else {
		while((*head)->next != nullptr) {
			*head = (*head)->next;		
		}
		(*head)->next = new struct ListNode(value);
		//printf("> %p\n", *head);	
	}
	
	//head = new struct ListNode(value);
 }
 
 void dequeue(struct ListNode** head){
	 while((*head) != nullptr) {
		 struct ListNode* tmp = (*head)->next;
		 delete *head;
		 *head = tmp;
	 }
 }
 
 void traverse(struct ListNode* head){
	 while(head) {
		 printf("%d ", head->val);
		 head = head->next;
	 }
	printf("\n");
 }
 
 
/* 
ListNode* reverseList(ListNode* head) {
    ListNode* list = NULL;
    ListNode* curr = NULL;
    
    while(head) {
        if(list == NULL) {
            list = new ListNode(head->val);
            list->next = NULL;
            curr = list;
        }
        else {
            curr->next = new ListNode(head->val);
            curr = curr->next;
            curr->next = NULL;
        }
        head = head->next;    
    }
    
    return(list);
}
*/

void traverse1(ListNode* head, ListNode** head1, ListNode** curr) {
    if(head) {
        traverse1(head->next, head1, curr);
        
        if(*head1 == NULL) {
            *head1 = new ListNode(head->val);
            (*head1)->next = NULL;
            *curr = *head1;
        }
        else {
            (*curr)->next = new ListNode(head->val);
            *curr = (*curr)->next;
            (*curr)->next = NULL;
        }
        
        
       // printf("%d ", head->val);
    }
}

ListNode* reverseList(ListNode* head) {
    ListNode* list = NULL;
    ListNode* curr = NULL;
    traverse1(head, &list, &curr);
    //printf("\n");
    return(list);
}



 

int main(int argc, char **argv)
{
	struct ListNode *list = nullptr;
	enqueue(&list, 0);
	struct ListNode *head = list;
	
	for(int i = 1; i < 10; i++) {
		head = list;
		enqueue(&head, i);
        head = list;
        enqueue(&head, i);
	}
	
	head = list;
	traverse(head);
	head = list;
    ListNode* head1 = reverseList(head);

	traverse(head1);
    return(0);
}