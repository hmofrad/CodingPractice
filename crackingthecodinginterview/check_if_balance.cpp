/*
 *  Problem: Implement a function to check if a binary tree is balanced. 
             A tree is balanced if the heights of the two subtrees of any node never differ by more than one. 
 *  Compile: g++ -o check_if_balance check_if_balance.cpp -g -Wall -Werror
 *  Execute: ./check_if_balance
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <iostream> 
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>

struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int data_): data(data_), left(NULL), right(NULL) {};
};

void insert(node*& head, int data)
{
    if(head == NULL)
        head = new node(data);
    else
    {
        if(data < head->data)
        {
            if(head->left == NULL)
                insert(head->left, data);
            else
            {
                head = head->left;
                insert(head, data);
            }
        }
        else
        {
            if(head->right == NULL)
                insert(head->right, data);
            else
            {
                head = head->right;
                insert(head, data);
            }
        }
    }
}

/* Postorder */
void traverse(node*& head)
{
    if(head == NULL)
        return;
    traverse(head->left);
    traverse(head->right);
    printf("%d\n", head->data);
}

int main(int argc, char **argv)
{
    node *list = NULL;
    node *head = NULL;
    insert(list, 10);
    head = list;
    
    for(uint32_t i = 5; i < 15; i++)
    {
        head = list;
        insert(head, i);
        printf("%d ", i);
    }
    printf("\n");
    head = list;
    
    traverse(head); 
}