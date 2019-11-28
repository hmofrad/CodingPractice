/*
 (c) Mohammad Hasanzadeh Mofrad
 (e) m.hasanzadeh.mofrad@gmail.com
 Compile and run:
     g++ -o remove_duplicates1 remove_duplicates1.cpp && ./remove_duplicates1
*/

#include <stdio.h>

struct Node {
    public:
        Node() {};
        Node(int d) {data = d;}
        Node* next = nullptr;
        int data = 0;
};


void appendToTail(Node** head, int d) {        
    if((*head) == nullptr) {
        (*head) = new Node(d);
    }
    else {
        while((*head)->next != nullptr) {
            (*head) = (*head)->next;
        }
        (*head)->next = new Node(d);  
    }
}


void deleteFromHead(Node** head) {  
    if((*head) != nullptr) {
        if((*head)->next == nullptr) {
            delete (*head);
            (*head) = nullptr;
        }
        else {
            Node* node = (*head)->next;
            delete (*head);
            (*head) = node;
        }
    }
}  

void traverseQueue(Node* head) {
    if(head != nullptr) {
        while(head->next != nullptr) {
            printf("%d ", head->data);
            head = head->next; 
        }
        printf("\n");
    }
}

void removeDuplicates(Node** head) {
    if(head != nullptr) {
        Node* headi = (*head);
        //Node* headk = (*head);
        while(headi->next != nullptr) {
            Node* headj = headi->next;
            Node* headk = headi;
            //printf("%d: ", headi->data);
            while(headj->next != nullptr) {
              //  printf("%d ", headj->data);
                if(headi->data == headj->data) {
                    Node *node = headj->next;
                    delete headj;
                    headk->next = node;
                    headj = node;
                     
                    //printf("%d %d\n", headi->data, headj->data);
                }
                else {
                    headk = headj;
                    headj = headj->next;
                }
            }
            //printf("\n");
            traverseQueue((*head));
            headi = headi->next;
        }
       // (*head) = headk;
    }
}

int main(int argc, char**argv) {
    Node* head = nullptr;
    appendToTail(&head, 0);
    Node* head_ = head;
    for(int i = 1; i < 10; i++) {
        head_ = head;
        appendToTail(&head_, i);
        appendToTail(&head_, i);
        //head_ = head;
        //traverseQueue(head);
    }
    for(int i = 1; i < 10; i++) {
        appendToTail(&head_, i);
    }
    
    traverseQueue(head);
    head_ = head;
    removeDuplicates(&head_);
    head = head_;
    printf("XXX\n");
    //head = head_;
    traverseQueue(head);
    
    head_ = head;
    appendToTail(&head_, 10);
    appendToTail(&head_, 10);
    appendToTail(&head_, 10);
    head_ = head;
    traverseQueue(head_);
    printf("YYY\n");
    for(int i = 0; i < 10; i++) {
        deleteFromHead(&head);
        //traverseQueue(head);
    }
    head = nullptr;
    head_ = nullptr;    
    return(0);
}