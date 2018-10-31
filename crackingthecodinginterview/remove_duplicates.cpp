/*
 *  Problem:  Write code to remove duplicates from an unsorted linked list (inefficient solution)
 *  Compile: g++ -o remove_duplicates remove_duplicates.cpp -g -Wall -Werror
 *  Execute: ./remove_duplicates
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream> 
#include <stdlib.h>
#include <stdio.h>
#

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
 
int main(int argc, char **argv)
{
    Node* list1 = NULL;
    Node* head1 = NULL;
    insert(head1, 1);
    list1 = head1;
    for(int i = 5; i < 15; i++)
    {
        
        insert(head1, (rand() % 5));
        head1 = list1;        
    }
    head1 = list1;
    traverse(head1);
    head1 = list1;
    
    Node *list = unique(head1);
    Node* head = list;
    traverse(head);
    
    head = list;
    free(head);
    list = NULL;
    
    head1 = list1;
    free(head1);
    list1 = NULL;
    
    //assert(list1 == head1);
    
    
    
    
    
    
    return(0);
}