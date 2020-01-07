/*
 * Cracking the coding interview: Problem 2.7: Check if a linked list is palindrome
 * Compile and run:  g++ -o isPalindrome isPalindrome.cpp -g -Wall  -std=c++11 -fsanitize=address && ./isPalindrome
 * (c) Mohammad Hasanzadeh mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

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


bool iterate(Node* head, std::vector<int>& vec) {
    bool tf = false;
    if(head == nullptr) {
        if(vec.size() != 0){
            bool good = true;
            for(uint32_t i = 0; i < vec.size()/2; i++) {
                if(vec[i] != vec[(vec.size()-1)-i]) {
                    good = false;
                    break;
                }
            }
            if(good) {
                tf = true;
            }
        }
    }
    else {
        vec.push_back(head->value);
        tf = iterate(head->next, vec);
    }
    return(tf);
}

bool isPalindrome(Node* head) {
    std::vector<int> vec;
    return(iterate(head, vec));
}

int main(int argc, char** argv) {
    Node* list = new Node(1);
    list->next = new Node(2);
    list->next->next = new Node(3);
    list->next->next->next = new Node(4);
    list->next->next->next->next = new Node(3);
    list->next->next->next->next->next = new Node(2);
    list->next->next->next->next->next->next = new Node(1);
    
    print(list);
    
    bool isPa = isPalindrome(list);
    printf("? %d\n", isPa);
    
    delete_q(&list);
    
    return(0);
}