/*
 * Cracking the coding interview: Problem 2.3: delete a linked list element in the middle
 * Compile and run:  g++ -o delete_element delete_element.cpp -g -Wall  -std=c++11 -fsanitize=address && ./delete_element
 * (c) Mohammad Hasanzadeh mofrad, 2019
 * (e) m.hasanzadeh.mofrad@gmail.com
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    public:
        Node() {};
        Node(int d) {data = d;}
        Node* next = nullptr;
        int data = 0;
};

void delete_element(struct Node** curr) {
    printf("1.delete %d\n", (*curr)->data);
    Node* temp = (*curr)->next;
    (*curr)->data = (*curr)->next->data;
    (*curr)->next = (*curr)->next->next;
    //printf("2.delete %d\n", (*curr)->data);
    //*curr = (*curr)->next;
    //printf("3.delete %d\n", (*curr)->data);
    delete temp;
}

int main(int argc, char** argv) {
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next->next = new Node(8);
    
    Node* head1 = head;
    while(head1) {
        printf("%d ", head1->data);
        head1 = head1->next;
    }
    printf("\n");
    
    Node* curr = head->next->next->next->next;
    delete_element(&curr);
    
    head1 = head;
    while(head1) {
        printf("%d ", head1->data);
        head1 = head1->next;
    }
    printf("\n");
    
    head1 = head;
    while(head1) {
        Node* head2 = head1;
        head1 = head1->next;
        delete(head2);
    }
    head = nullptr;
    return(0);
}