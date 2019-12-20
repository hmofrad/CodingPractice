/*
 * Cracking the coding interview: Problem 2.4: Partition a linked list based on x
 * Compile and run:  g++ -o partition partition.cpp -g -Wall  -std=c++11 -fsanitize=address && ./partition
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

/*
void sort_list(struct Node** head, int x) {
    struct Node* head1 = *head;
    struct Node* head2;
    
    while(*head) {
        if((*head)->value > x) {
            struct Node* head2 = *head;
            int t = (*head)->value;
            *head = (*head)->next;

            while(*head) {
                if((*head)->value <= x) {
                    break;
                }
                *head = (*head)->next;
            }

            if(*head) {
                head2->value = (*head)->value;
                (*head)->value = t;
                *head = head2->next;
                continue;
            }
            else {
                break;
            }
        }
        *head = (*head)->next;
    }
    
    *head = head1;
    while(*head) {
        if((*head)->value == x) {
            head2 = *head;
        }
        *head = (*head)->next;
    }
    
    *head = head1;
    while((*head)->next) {
        if((*head)->next->value > x) {
            head2->value = (*head)->value;
            (*head)->value = x;
            break;
        }
        *head = (*head)->next;
    }
    
    *head = head1;
}

*/

void sort_list(struct Node** head, int x) {
    struct Node* before = nullptr;
    struct Node* before1 = nullptr;
    struct Node* after = nullptr;
    struct Node* after1 = nullptr;
    while(*head) {
        printf("%d\n", (*head)->value);
        if((*head)->value < x) {
            printf("???\n");
            if(before1) {
                before1->next = (*head);
                before1 = before1->next;
            }
            else {
                before = (*head);
                before1 = before;
            }
        }
        else {
            printf("!!!\n");
            if(after1) {
                after1->next = (*head);
                after1 = after1->next;
            }
            else {
                after = (*head);
                after1 = (*head);
            }
        }
        
        *head = (*head)->next;
    }
    
    before1->next = nullptr;
    after1->next = nullptr;
    
    if(before == nullptr) {
        *(head) = after;
    }
    
    struct Node* head1 = before;
    while(head1->next) {
        head1 = head1->next;
    }
    head1->next = after;
    (*head) = before;
}

int main(int argc, char** argv) {
    Node* head = new Node(10);
    head->next = new Node(13);
    head->next->next = new Node(43);
    head->next->next->next = new Node(22);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(45);
    head->next->next->next->next->next->next = new Node(76);
    head->next->next->next->next->next->next->next = new Node(17);
    head->next->next->next->next->next->next->next->next = new Node(88);
    
    Node* head1 = head;
    while(head1) {
        printf("%d ", head1->value);
        head1 = head1->next;
    }
    printf("\n");
    
    head1 = head;
    sort_list(&head, 22);
    
    head1 = head;
    while(head1) {
        printf("%d ", head1->value);
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
    head1 = nullptr;
    return(0);
}