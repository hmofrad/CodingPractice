/*
 * Cracking the coding interview: Problem 2.2: Extract the k last elements of a linked list
 * Compile and run:  g++ -o k_last_elements k_last_elements.cpp && ./k_last_elements
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


struct Node* k_last_elements(Node* head, int kth) {
    
    int n = 0;
    Node* head1 = head;
    Node* start = nullptr;
    while(head1) {
        //if(n == kth) {
          //  start = head1;
            //break;
        //}
        head1 = head1->next;
        n++;
    }
    printf("%d\n", n);
    if(kth > n) return nullptr;
    
    
    head1 = head;
    //n = 0;
    int m = 0;
    while((n - m) != kth) {
        //printf("%d %d\n", m, n - m);
        head1 = head1->next;
        m++;
    }
    start = head1;
    
    //head1 = head;
    //Node* out = start;
/*
    //int k = 0;
    while(start) {
        if(out) {
            out = out->next;
            out = start;
        }
        else { 
            out = start;
        }
        start = start->next;
    }
    */
    return(start);
}


int main(int argc, char** argv) {
    int kth = 3;
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next->next = new Node(8);
    Node* head1 = k_last_elements(head, kth);
    
    while(head1) {
        printf("%d ", head1->data);
        head1 = head1->next;
    }
    printf("\n");
    
    return(0);
}