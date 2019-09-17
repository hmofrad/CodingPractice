/*
 (c) Mohammad Hasanzadeh Mofrad
 (e) m.hasanzadeh.mofrad@gmail.com
 Compile and run:
     g++ -o queue queue.cpp && ./queue
*/

#include <stdio.h>

struct Node {
    public:
        Node() {};
        Node(int d) {data = d;}
        
        Node* next = nullptr;
        int data = 0;
        
        //void appendToTail(Node** head, int d);
        
        
};

//void Node::
void appendToTail(Node** head, int d) {        
    //Node* end = new Node(d);
    //printf("0000 %p %p %d\n",head, *head, (*head)->data);
    //
    
    if((*head) == nullptr) {
        //printf("xxxx\n");
        (*head) = new Node(d);
        //printf("111\n");
    }
    
    
    else {

        //Node* h = (*head); 
        //int i = 0;
        while((*head)->next != nullptr) {
            //i++;
            //printf("%d\n", i);
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
    //Node* head = head;
    
    //if(head == nullptr) {
      //  printf("%d\n", head->data);
    //}
    //else {
    if(head != nullptr) {
        while(head->next != nullptr) {
            printf("%d ", head->data);
            head = head->next; 
        }
        printf("\n");
    }
    //}
}

int main(int argc, char**argv) {
    printf("Hello queue\n");
    
    Node* head = nullptr;
    //traverseQueue(head);
    appendToTail(&head, 0);
    Node* head_ = head;
    //head->appendToTail(&head_, 1);
    
    
    for(int i = 1; i < 10; i++) {
        head_ = head;
        appendToTail(&head_, i);
        head_ = head;
        traverseQueue(head);
    }
    head_ = head;
    traverseQueue(head);
    head_ = head;
    for(int i = 0; i < 10; i++) {
        deleteFromHead(&head);
    //head_ = head;
        traverseQueue(head);
    }
    
    
    return(0);
}

/*
class Queue {
    public:
        Node** head = nullptr;
        Queue(){};
    
        Node* next = nullptr;
        int data;
        Node() {};
        Node(int d) {
            data = d;
        }
    
     
    void appendToTail(int d) {
        
        //Node* end = new Node(d);
        printf("0000 %p\n",head );
        //
        if(head == nullptr) {
            printf("xxxx\n");
            Node* h = new Node(d);
            *head = h;
            printf("111\n");
        }
        else {
            printf("xxxxddd\n");
            Node* h = (*head); 
            int i = 0;
            while(h->next != nullptr) {
                i++;
                printf("%d\n", i);
                h = h->next;
            }
            h->next = new Node(d);  
        }
    }
    
    void traverseQueue() {
        Node* head = head;
        
        if(head == nullptr) {
            printf("%d\n", head->data);
        }
        else {
            while(head->next != nullptr) {
                printf("%d ", head->data);
                head = head->next; 
            }
            printf("\n");
        }
    }
    
};
*/

