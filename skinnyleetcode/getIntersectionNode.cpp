/*
 *  Problem: https://leetcode.com/problems/intersection-of-two-linked-lists/
 *  Compile: g++ -o getIntersectionNode getIntersectionNode.cpp -std=c++11 && ./getIntersectionNode
 *  Execute: ./getIntersectionNode
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
 
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* list = NULL;
    ListNode* headA1 = headA;
    ListNode* headB1 = headB;
    ListNode*  ptrA = NULL;
    ListNode*  ptrB = NULL;
    int len = 0;
    ListNode*  ptrA1;
    ListNode*  ptrB1;
    int len1 = 0;
    bool br = false;
    while(headA1) {
        //printf("%d\n", headA1->val);
        headB1 = headB;
        while(headB1) {   
            if(headB1->val == headA1->val) {
                len1 = 1;
                //printf("\n%d %d %d\n", headB1->val, headA1->val,len1);
                
                ptrA1 = headA1;
                ptrB1 = headB1;
                ListNode* headB2 = headB1->next;
                ListNode* headA2 = headA1->next;                    
                while(headB2 and headA2) { 
                    if(headB2->val == headA2->val) { 
                        len1++;
                        //printf("%d %d %d\n", headB2->val, headA2->val,len1);                    
                        
                        headB2 = headB2->next; 
                        headA2 = headA2->next; 
                    }
                    else {
                        
                        //br = true;
                        break;
                    }
                }
                if(len1 > len) {
                    //printf("UPDATE\n");
                    len = len1;
                    ptrA = ptrA1;
                    ptrB = ptrB1;
                }
            }
            headB1 = headB1->next; 
        }

        headA1 = headA1->next;
    }
    
    //while(headA and headB) {
    //    if(headA->val == headB->val
    //}
    
    //printf("<%d\n", len);
    ListNode* cur = NULL;
    while(len > 0) {
        if(list) {
            cur->next = new struct ListNode(ptrA->val);
            cur = cur->next;
        }
        else {
            list = new struct ListNode(ptrA->val);
            list->next = NULL;
            cur = list;
        }
        ptrA = ptrA->next;
        len--;
    }
    //printf("%d>\n", len);
    
    return(list);
}



 

int main(int argc, char **argv){
	struct ListNode* list = nullptr;
	enqueue(&list, 4);
	struct ListNode* head = list;
    head = list;
    enqueue(&head, 1);
    head = list;
    enqueue(&head, 8);
    head = list;
    enqueue(&head, 4);
    head = list;
    enqueue(&head, 5);

	head = list;
	traverse(head);
    
    struct ListNode* list1 = nullptr;
	enqueue(&list1, 5);
	struct ListNode* head1 = list1;
    head1 = list1;
    enqueue(&head1, 0);
    head1 = list1;
    enqueue(&head1, 1);
    head1 = list1;
    enqueue(&head1, 8);
    head1 = list1;
    enqueue(&head1, 4);
    head1 = list1;
    enqueue(&head1, 5);
    
    head1 = list1;
	traverse(head1);
    
    head = list;
    head1 = list1;
    ListNode* head2 = getIntersectionNode(head, head1);

	traverse(head2);
    return(0);
}