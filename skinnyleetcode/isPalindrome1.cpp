/*
 *  Problem: https://leetcode.com/problems/palindrome-linked-list/
 *  Compile: g++ -o isPalindrome1 isPalindrome1.cpp -std=c++11 && ./isPalindrome1
 *  Execute: ./isPalindrome1
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

bool isPalindrome1(ListNode* head) {
    bool ret = true;
    ListNode* head1 = head;
    
    
    int n = 0;
    if(head1) {
        while(head1) {
            n++;
            head1 = head1->next; 
        }
        if(n <= 1) {
            //ret = true;
            return(ret);
        }
    }
    else {
        //ret = true;
        return(ret);
    }
    
    std::vector<int> left(n/2);
    
    head1 = head;
    int i = 0;
    int j = 0;
    while(head1) {
        i++;
        if(i <= n/2) {
            left[j] = head1->val;
            j++;
        }
        else {
            break;
        }
        head1 = head1->next;
    }
    
    if(n % 2) {
        head1 = head1->next;
    }
    i = 0;
    while(head1) {
        j = (n/2) - i - 1;
        if(head1->val != left[j]) {
            ret = false;
            break;
        }
       // printf("%d %d\n", head1->val, left[j]);
        head1 = head1->next;
        i++;
    }
    
    return(ret);
}



 

int main(int argc, char **argv)
{
	struct ListNode *list = nullptr;
	enqueue(&list, 0);
	struct ListNode *head = list;
    head = list;
    enqueue(&head, 1);
    head = list;
    enqueue(&head, 2);
    //head = list;
    //enqueue(&head, 3);
    head = list;
    enqueue(&head, 2);
    head = list;
    enqueue(&head, 1);
    head = list;
    enqueue(&head, 0);
    

    head = list;
	traverse(head);
    
    head = list;
    bool tf = isPalindrome1(head);
    printf("%d\n", tf);

    return(0);
}