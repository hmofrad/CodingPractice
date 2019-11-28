/*
 * Cracking the coding interview: Problem 2.1: Remove duplicates from a linked list
 * Compile and run: g++ -o remove_duplicates remove_duplicates.cpp && ./remove_duplicates
 * (c) Mohammad Hasanzadeh Mofrad, 2019
 * (e) m.hasanzadeh.mofrad@gmail.com
*/

#include <iostream> 
#include <stdlib.h>
#include <stdio.h>

/*
struct Node
{
    Node(int v, int p): value(v), position(p), next(NULL){};
    ~Node(){next = NULL;};
    int value;
    int position;
    Node *next;
};

void insert(Node*& head, int value)
{
    int p = 0;
    if(not head)
    {
        head = new Node(value, p);
    }
    else
    {
        p++;
        while(head->next)
        {
            head = head->next;
            p++;
        }
        head->next = new Node(value, p);
    }
}

void traverse(Node*& head)
{
    if(head)
    {
        while(head)
        {
            printf("[%d %d]", head->position, head->value);
            head = head->next;
        }
        printf("\n");
    }
}

void free(Node*& head)
{
    if(head)
    {
        while(head)
        {
            Node *next = head->next;
            delete head;
            head = next;
        }
    }
}

Node* unique(Node*& list_in)
{
    Node *list_out = NULL;
    Node *head_out = NULL;
    Node *head_in = list_in;
    bool uniq = true;
    //int p = 0;
    //Node *head_out = NULL;
    //traverse(in_list);
    
    if(head_in)
    {
        while(head_in)
        {
            //printf("%d ", head_in->position);
            uniq = true;
            if(not head_out)
            {
                //list_out = new Node(head_in->value, head_in->position);
                insert(list_out, head_in->value);
                head_out = list_out;
            }
            else
            {
                while(head_out)
                {
                    if(head_out->value == head_in->value)
                    {
                        uniq = false;
                        break;
                    }
                    head_out = head_out->next;
                    //printf("(%p) ", head_out);
                }
                //printf("(%p) ", head_out);
                if(uniq)
                {
                    //head_out->next = new Node(head_in->value, head_in->position);
                    head_out = list_out;
                    insert(head_out, head_in->value);
                }
                head_out = list_out;
            }
            head_in = head_in->next;
            //printf("\n");
        }
        
    }
    return (list_out);   
}
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