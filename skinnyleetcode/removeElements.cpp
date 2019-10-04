/*
 *  Problem: https://leetcode.com/problems/remove-linked-list-elements/
 *  Compile: g++ -o removeElements removeElements.cpp -std=c++11 && ./removeElements
 *  Execute: ./removeElements
 *  (c) Mohammad Hasanzadeh Mofrad, 2018
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
      ListNode *next;
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
 
 void dequeue(struct ListNode **head){
	 while((*head) != nullptr) {
		 struct ListNode *tmp = (*head)->next;
		 delete *head;
		 *head = tmp;
	 }
 }
 
 void traverse(struct ListNode *head){
	 while(head) {
		 printf("%d ", head->val);
		 head = head->next;
	 }
	printf("\n");
 }
 
ListNode* removeElements(ListNode* head, int val) {
    ListNode* list = NULL;
    ListNode* curr = head;
    if(curr) {
        while(curr) {
            if(curr->val != val) {
                list = new struct ListNode(curr->val);
                curr = curr->next;
                break;
            }
            curr = curr->next;
        }
        
        while(curr) {
            
            bool tf = true;
            //while(head1) {
                if(curr->val == val) {
                    tf = false;
                   // break;
                }
                //head1 = head1->next;
            //}
            
            if(tf) {
                //head1 = list;
                ListNode* head1 = list;
                while(head1->next)
                    head1 = head1->next;
                head1->next = new struct ListNode(curr->val);
            }
            curr = curr->next;
        }
    }
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
	//printf("%d\n", list->val);
	head = list;
	traverse(head);
	head = list;
    ListNode* head1 = removeElements(head, 5);
    
	//dequeue(&head);
	//head = list;
	traverse(head1);
	//struct ListNode list(1);
	//list.next = new struct ListNode(1);
	//delete list.next;
	//struct ListNode list(0);
	//printf("%d %p\n", list.val, list.next);
	
	// = new struct Listnode(1);
    return(0);
}