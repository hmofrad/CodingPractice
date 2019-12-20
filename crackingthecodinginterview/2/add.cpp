/*
 * Cracking the coding interview: Problem 2.5: Add two linked list
 * Compile and run:  g++ -o add add.cpp -g -Wall  -std=c++11 -fsanitize=address && ./add
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

Node* add(Node* num1, Node* num2) {
    printf("num1 = ");
    print(num1);
    printf("num2 = ");
    print(num2);
    Node* num = nullptr;
    Node* head = nullptr;
    
    int s = 0;
    int c = 0;
    int r = 0;
    while(num1 or num2) {
        if(num1 and num2) {
            s = num1->value + num2->value + c;
            num1 = num1->next;
            num2 = num2->next;
        }
        else if(num1) {
            s = num1->value + c;
            num1 = num1->next;
        }
        else {
            s = num2->value + c;
            num2 = num2->next + c;
        }
        
        r = s%10;
        c = s/10;
        
        if(num == nullptr) {
            num = new Node(r);
            head = num;
        }
        else {
            num->next = new Node(r);
            num = num->next;
        }
    }
    if(c) {
        num->next = new Node(c);
        num = num->next;
    }
    
    num = head;
    return(num);
}

int main(int argc, char** argv) {
    Node* num1 = new Node(7);
    num1->next = new Node(1);
    num1->next->next = new Node(7);
    num1->next->next->next = new Node(9);
    
    Node* num2 = new Node(5);
    num2->next = new Node(9);
    num2->next->next = new Node(2);
    
    Node* num = add(num1, num2);
    printf("num = ");
    print(num);
    
    delete_q(&num1);
    delete_q(&num2);
    delete_q(&num);
    
    /*
    Node* head = num1;
    while(head) {
        Node* temp = head;
        head = head->next;
        delete(temp);
    }
    head = nullptr;
    
    head = num2;
    while(head) {
        Node* temp = head;
        head = head->next;
        delete(temp);
    }
    head = nullptr;
    */
    
    return(0);
}