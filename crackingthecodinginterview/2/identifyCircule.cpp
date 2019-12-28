/*
 * Cracking the coding interview: Problem 2.6: Identify the circular point of a circular linked list
 * Compile and run:  g++ -o identifyCircule identifyCircule.cpp -g -Wall  -std=c++11 -fsanitize=address && ./identifyCircule
 * (c) Mohammad Hasanzadeh mofrad, 2019
 * (e) m.hasanzadeh.mofrad@gmail.com
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    public:
        Node() {};
        Node(int v) {value = v;}
        Node* next = nullptr;
        int value = 0;
};

void delete_q(Node** head) {
    while(*head) {
        Node* temp = *head;
        *head = (*head)->next;
        delete(temp);
    }
    *head = nullptr;
}

void print(Node* head) {
    while(head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}


Node* find(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while(fast and fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            break;
        }
    }
    
    if((not fast) or (not fast->next)) {
        return(nullptr);
    }
    
    slow = head;
    
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return(fast);
}


int main(int argc, char** argv) {
    Node* list = new Node(1);
    list->next = new Node(2);
    list->next->next = new Node(3);
    list->next->next->next = new Node(4);
    list->next->next->next->next = new Node(5);
    list->next->next->next->next->next = new Node(6);
    list->next->next->next->next->next->next = list->next->next->next;
    
    Node* index = find(list);
    printf("%d\n", index->value);
    
    
    
    delete_q(&list);
    
    
    return(0);
}