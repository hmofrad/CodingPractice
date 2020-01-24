/*
 *  Problem: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
 *  Compile: g++ -o flatten flatten.cpp -std=c++11 -g -Wall -fsanitize=address && ./flatten
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

class Node {
public:
    Node(int val_) : val(val_), prev(nullptr), next(nullptr), child(nullptr) {};
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

void traverse1(Node* head) {
    while(head) {
        printf("%d\n", head->val);
        if(head->child) {
            traverse1(head->child);
        }
        head = head->next;
    }
}

void traverse2(Node* head) {
    while(head) {
        printf("%d\n", head->val);
        head = head->next;
    }
}

Node* flatter(Node* head, Node* next) {
    while(head->next) {
        if(head->child) {
            head->next->prev = flatter(head->child, head->next);
            head->next->prev->next = head->next;
            head->next = head->child;
            head->next->prev = head;
            head->child = nullptr;
        }
        head = head->next;
    } 
    
    if(head and head->child) {
        (void)flatter(head->child, head->next);
        head->next = head->child;
        head->next->prev = head;
        head->child = nullptr;                
    }
    
    return(head);
}

Node* flatten(Node* head) {
    if(head == nullptr) {
        return(nullptr);
    }
    
    if(head->child == nullptr && head->next == nullptr){
        return head;
    }
    
    (void)flatter(head, nullptr);
    
    return(head);    
}

/*
01 <--> 02 <--> 03 <--> 04 <--> 05 --> null
                |
                |
                07 <--> 08 <--> 09 --> null
                         |
                         | 
                        11 <--> 12 --> null 
*/

int main(int argc, char **argv){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->child = new Node(7);
    head->next->next->child->prev = head->next->next;
    head->next->next->child->next = new Node(8);
    head->next->next->child->next->next = new Node(9);
    head->next->next->child->next->next->prev = head->next->next->child->next;
    head->next->next->child->next->child = new Node(11);
    head->next->next->child->next->child->prev = head->next->next->child->next;
    head->next->next->child->next->child->next = new Node(12);
    head->next->next->child->next->child->next->prev = head->next->next->child->next->child;
    
    
    
    
    
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->child = new Node(55);
    head->next->next->next->next->child->prev = head->next->next->next->next;
    traverse1(head);
    printf("\n");
    Node* head1 = flatten(head);
    printf("\n");
    traverse2(head1);
    
    return(0);
}






