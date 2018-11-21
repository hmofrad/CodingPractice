/*
 *  Problem: Merge k sorted lists (https://leetcode.com/problems/merge-k-sorted-lists/description/)
 *  Compile: g++ -o mergeKLists mergeKLists.cpp && ./mergeKLists -g -Wall -Werror
 *  Execute: ./mergeKLists
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

const int NUM = 10;
//#define NUM 10
struct ListNode
{
    int val; 
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {};
};

void insert(ListNode*& curr, int val_)
{
    if(curr == NULL)
        curr = new ListNode(val_); 
    else
    {
        curr->next = new ListNode(val_); 
        curr = curr->next;
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
        ListNode* mergeKLists(std::vector<ListNode*>& lists);
};


ListNode* Solution::mergeKLists(std::vector<ListNode*>& lists)
{
    ListNode* list = NULL;
    ListNode* curr = NULL;
    
    int numberOfLists = lists.size();
    std::vector<ListNode*> currs(numberOfLists);
    for(int i = 0; i < numberOfLists; i++)
    {
        currs[i] = lists[i];
    }
    
    bool init = true;
    while(numberOfLists)
    {
        for(int i = 0; i < numberOfLists - 1; i++)
        {
            for(int j = i + 1; j < numberOfLists; j++)
            {
                if(currs[i] and currs[j])
                {
                    if(currs[i]->val < currs[j]->val)
                    {
                        if(not curr)
                        {
                            insert(list, currs[i]->val);
                            curr = list;
                            currs[i] = currs[i]->next;
                        }
                        else
                        {
                            insert(curr, currs[i]->val);
                            currs[i] = currs[i]->next;
                        }
                    }
                    else if(currs[i]->val > currs[j]->val)
                    {
                        if(not curr)
                        {
                            insert(list, currs[j]->val);
                            curr = list;
                            currs[j] = currs[j]->next;
                        }   
                        else
                        {
                            insert(curr, currs[j]->val);
                            currs[j] = currs[j]->next;
                        }
                    }
                    else                       
                    {
                        if(not curr)
                        {
                            insert(list, currs[i]->val);
                            curr = list;
                            currs[i] = currs[i]->next;
                            insert(curr, currs[j]->val);
                            currs[j] = currs[j]->next;
                        }   
                        else
                        {
                            insert(curr, currs[i]->val);
                            currs[i] = currs[i]->next;
                            insert(curr, currs[j]->val);
                            currs[j] = currs[j]->next;
                        }
                    }
                }
                else if((not currs[i] and currs[j]) or (currs[i] and not currs[j]))
                {
                    numberOfLists --;
                    break;
                }
                else if(not (currs[i] and currs[j]))
                {
                    numberOfLists -= 2;
                    break;
                }
            }
        }
        
        
    }
    
    /*
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
    */
    return(list);
}



int main(int argc, char **argv)
{    
    ListNode *list1 = NULL;
    ListNode* curr1 = NULL; // Technocally it should be current
    insert(curr1, 1);
    list1 = curr1;
    for(int i = 1; i < NUM; i++)
        insert(curr1, i);
    curr1 = list1;
    traverse(curr1);

    ListNode *list2 = NULL;
    ListNode* curr2 = NULL;
    insert(curr2, 5);
    list2 = curr2;
    for(int i = 6; i < NUM + 5; i++)
        insert(curr2, i);
    curr2 = list2;
    traverse(curr2);
    
    ListNode *list3 = NULL;
    ListNode* curr3 = NULL;
    insert(curr3, 10);
    list3 = curr3;
    for(int i = 11; i < NUM + 10; i++)
        insert(curr3, i);
    curr3 = list3;
    traverse(curr3);
    
    std::vector<ListNode*>lists(3);
    lists[0] = list1;
    lists[1] = list2;
    lists[2] = list3;
    
    Solution merger;
    ListNode *list = merger.mergeKLists(lists);
    traverse(list);
    
    free(curr1);
    free(curr2);
    return(0);
}