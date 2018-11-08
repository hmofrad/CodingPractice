/*
 *  Problem: Reverse Nodes in k-Group (https://leetcode.com/problems/reverse-nodes-in-k-group/)
 *  Compile: g++ -o reverseKGroup reverseKGroup.cpp && ./reverseKGroup
 *  Execute: ./reverseKGroup
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insert(ListNode*& curr, int val)
{
    if(curr == NULL)
        curr = new ListNode(val); 
    else
    {
        curr->next = new ListNode(val); 
        curr = curr->next;
    }
}

void add(ListNode*& head, int val)
{
    if(head == NULL)
        insert(head, val);
    else
    {        
        while(head->next)
        {
            head = head->next;
        }
        insert(head->next, val);
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

int sizeOf(ListNode* head)
{
    int size = 0;
    while(head)
    {
        size++;
        head = head->next;
    }
    return(size);
}

void reverse(ListNode* curr, ListNode*& list, ListNode*& ptr, int k)
{
    if(k > 1)
    {
        reverse(curr->next, list, ptr, k - 1);
    }
    else
    {
        if(curr->next)
            ptr = curr->next;
        else
            ptr = NULL;
    }
    
    if(k == 1)
    {
        add(list, curr->val);
    }
    else
    {
        ListNode* head = list;
        add(head, curr->val);
    }
}

ListNode *reverseKGroup(ListNode* head, int k)
{
    ListNode *list = head;
    ListNode *curr = head;
    ListNode *list_out = NULL;
    ListNode *head_out = NULL;
    ListNode *ptr = NULL;
    int size = sizeOf(head);
    int ngroups = size / k;
    int leftovers = size - (ngroups * k);
    printf("size=%d, k=%d, ngroups=%d, leftovers=%d\n", size, k, ngroups, leftovers);
    if(size > 0 and leftovers == size)
    {
        add(list_out, head->val);
        //head_out = list_out;
        head = head->next;
        while(head)
        {
            head_out = list_out;
            add(head_out, head->val);
            head = head->next;
        }
    }
    
    
    int i = 0;
    for(uint32_t i = 0; i < ngroups; i++)
    {
        if(i == 0)
        {
            reverse(curr, list_out, ptr, k);
            head_out = list_out;
        }
        else
        {
            head_out = list_out;
            curr = ptr;
            reverse(curr, head_out, ptr, k);
        }
    }
    while(ptr)
    {
        add(head_out, ptr->val);
        ptr = ptr->next;
    }

    //head_out = list_out;
    //traverse(head_out);
    return(list_out);
    
}

int main(int argc, char **argv)
{    
    ListNode *list = NULL;
    ListNode *head = NULL;
    add(list, 0);
    
    for(uint32_t i = 1; i < 9; i++)
    {
        head = list;
        add(head, i);
    }
    
    head = list;
    //traverse(head);
    ListNode *list1 = reverseKGroup(head, 10);
    traverse(list1);
        
    
    return(0);
}