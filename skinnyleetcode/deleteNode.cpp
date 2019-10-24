    /*
 *  Problem: https://leetcode.com/problems/delete-node-in-a-linked-list/
 *  Compile: g++ -o deleteNode deleteNode.cpp -std=c++11 && ./deleteNode
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
#include <unordered_set>
#include <stack>
#include <numeric>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

void traverse(ListNode* head) {
    while(head) {
        printf("%d ", head->val);
        head = head->next;
    }   
    printf("\n");
}

/*
 void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* temp = node->next;
        //std::swap(node->next, node->next->next);
        node->next = node->next->next;
        
        delete temp;
    }
    */


void deleteNode(ListNode* head, int val) {
    ListNode* prev = head;
    while(head) {
        if(head->val == val) {
            if(head == prev) {
                head = head->next;
                delete prev;
                break;
            }
            else if(head->next) {
                prev->next = head->next;
                delete head;
                break;
            }
            else {
                prev->next = NULL;
                delete head;
                break;
            }
        }
        prev = head;
        head = head->next;
    }   

    
   // while(head->next) {
     //   if(head->
    //}

    
}

int main(int argc, char **argv){
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    printf("%p %p\n", head, head->next);
    traverse(head);
    int val = 5;
    deleteNode(head, val);
    printf("%p %p\n", head, head->next);
    traverse(head); 
    //printf("%s, %s ? %d\n", s.c_str(), t.c_str(), isAnagram(s, t));
    return(0);
}






