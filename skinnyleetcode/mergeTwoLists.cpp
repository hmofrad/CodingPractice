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
};

void insert(ListNode*& head, int val_)
{
    if(head == NULL)
        head = new ListNode(val_); 
    else
    {
        head->next = new ListNode(val_); 
        head = head->next;
    }
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

void traverse(ListNode* head)
{
    while(head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

class Solution
{
    public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode* list = NULL;
    ListNode* head = NULL;
    if(l1 or l2)
        insert(list, 0);
    head = list;
    
    while(l1 and l2)
    {
        if(l1->val < l2->val)
        {
            head->val = l1->val;
            if(l1->next or l2)
                insert(head, 0);
            l1 = l1->next;
        }
        else if(l1->val > l2->val)
        {
            head->val = l2->val;
            if(l1 or l2->next)
                insert(head, 0);
            l2 = l2->next;
            
        }
        else// if(l1->val == l2->val)
        {
            head->val = l1->val;
            insert(head, 0);
            head->val = l2->val;
            if(l1->next or l2->next)
                insert(head, 0);
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    traverse(list);

    ListNode *l;
    if(l1)
        l = l1;
    else
        l = l2;
    
    while(l)
    {
        head->val = l->val;
        if(l->next)
            insert(head, 0);
        l = l->next;
    }
    
    return(list);
}

int main(int argc, char **argv)
{    
    ListNode *list1 = NULL;
    ListNode* head1 = NULL; // Technocally it should be current
    insert(head1, 2);
    list1 = head1;
    //insert(head1, 2);
    //insert(head1, 4);
    //for(int i = 1; i < NUM; i++)
    //    insert(head1, i);
    head1 = list1;
    traverse(head1);

    ListNode *list2 = NULL;
    ListNode* head2 = NULL;
    insert(head2, 1);
    list2 = head2;
    //insert(head2, 3);
    //insert(head2, 4);
    //for(int i = 6; i < NUM + 5; i++)
    //    insert(head2, i);

    head2 = list2;
    //traverse(head2);
    
    Solution merger;
    ListNode *list = merger.mergeTwoLists(list1, list2);
    traverse(list);
    
    free(head1);
    free(head2);
    return(0);
}