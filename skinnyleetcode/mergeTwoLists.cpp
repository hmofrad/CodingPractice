/*
 *  Problem: Merge two sorted lists (https://leetcode.com/problems/merge-two-sorted-lists/description/)
 *  Compile: g++ -o mergeTwoLists mergeTwoLists.cpp && ./mergeTwoLists -g -Wall -Werror
 *  Execute: ./mergeTwoLists
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

#define NUM 10
struct ListNode
{
    int val; 
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {};
    //ListNode();
    //void populate(ListNode *list);
};



void populate(ListNode* head, int count, int start_val_)
{
    int start_val = start_val_;
    head->val = start_val;
    for(int i = 0; i < count - 1; i++)
    {
        start_val++;
        head->next = new ListNode(start_val); 
        head = head->next;
        
    }
}

void traverse(ListNode* head)
{
    while(head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int getSize(ListNode* head)
{
    int size = 0;
    while(head)
    {
        
        size++;
        head = head->next;
    }
    return(size);
}


void free(ListNode* head)
{
    ListNode *next;
    while(head)
    {
        next = head->next;
        delete head;
        head = next;
    }    
}

class MergeTwoSortedLists
{
    public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

ListNode* MergeTwoSortedLists::mergeTwoLists(ListNode* l1, ListNode* l2)
{
    int size1 = getSize(l1);
    int size2 = getSize(l2);
    
    ListNode* list = new ListNode(0);
    ListNode* head = list;
    
    int it1 = 0;
    int it2 = 0;
    
    while(it1 < size1 and it2 < size2)
    {
        if(l1->val < l2->val)
        {
            head->val = l1->val;
            if(l1->next)
            {
                head->next = new ListNode(0);
                head = head->next;
            }
            it1++;
            l1 = l1->next;
        }
        else if(l1->val < l2->val)
        {
            head->val = l2->val;
            if(l2->next)
            {
                head->next = new ListNode(0);
                head = head->next;
            }
            it2++;
            l2 = l2->next;
        }
        else if(l1->val == l2->val)
        {
            head->val = l1->val;
            head->next = new ListNode(0);
            head = head->next;
            it1++;
            head->val = l2->val;
            if(l2->next)
            {
                head->next = new ListNode(0);
                head = head->next;
            }
            it2++;
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    int it = 0;
    int size = 0;
    ListNode *l;
    if(it1 < size1)
    {
        it = it1;
        size = size1;
        l = l1;
    }
    else
    {
        it = it2;
        size = size2;
        l = l2;
    }
    
    while(it < size)
    {
        //printf("%d %d %d %p\n", it, l->val, head->val, l->next);
        head->val = l->val;
        if(l->next)
        {
            head->next = new ListNode(0);
            head = head->next;
        }
        l = l->next;
        it++;
    }
    //free(head);
    
    
    //head = list;
    //traverse(list);
    return(list);
}

int main(int argc, char **argv)
{
    
    
    MergeTwoSortedLists lists;
    
    ListNode *list1 = new ListNode(0);
    ListNode *head1 = list1;
    populate(head1, 10, 5);
    traverse(head1);

    ListNode *list2 = new ListNode(0);
    ListNode *head2 = list2;
    populate(head2, 10, 10);
    traverse(head2);    
    
    MergeTwoSortedLists merger;
    ListNode *list = merger.mergeTwoLists(list1, list2);
    traverse(list);
    
    
    free(head1);
    free(head2);
    //ListNode list2(5);
    //list1.next = &list2;
    //printf("Hello %d %d %p %p\n", list1.val, list2.val, &list2, list1.next);
    //ListNode list1(3);
    
    
    
    return(0);
}