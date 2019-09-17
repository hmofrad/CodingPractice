/*
 (c) Mohammad Hasanzadeh Mofrad
 (e) m.hasanzadeh.mofrad@gmail.com
 Compile and run:
     g++ -o queue queue.cpp && ./queue
*/

#include <stdio.h>

struct Node {
    Node* next = nullptr;
    int data;
    Node() {};
    Node(int d) {data = d;}
};

void Node::appendToTail(int d) {
        
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


int main(int argc, char**argv) {
    printf("Hello queue\n");
    
    Queue queue;
    
    for(int i = 0; i < 10; i++) {
        queue.appendToTail(i);
    }
    //queue.traverseQueue();
    
    
    return(0);
}