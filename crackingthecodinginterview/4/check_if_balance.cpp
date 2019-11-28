/*
 *  Cracking the coding interview: Problem 4.1: Implement a function to check if a binary tree is balanced. 
             A tree is balanced if the heights of the two subtrees of any node never differ by more than one. 
 *  Compile & run: g++ -o check_if_balance check_if_balance.cpp -g -Wall -Werror && ./check_if_balance
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <iostream> 
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int data_): data(data_), left(nullptr), right(nullptr) {};
};

/*
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

void traverse(node*& head) {
    if(head == NULL)
        return;
    traverse(head->left);
    traverse(head->right);
    printf("%d\n", head->data);
}

*/

/* Inorder */
void inorder(Node* head) {
    if(head == nullptr)
        return;

    inorder(head->left);
    printf("%d ", head->data);
    inorder(head->right);
    
}

/* Prerder */
void preorder(Node* head) {
    if(head == nullptr)
        return;

    printf("%d ", head->data);
    preorder(head->left);
    preorder(head->right);
    
}


/* Postorder */
void postorder(Node* head) {
    if(head == nullptr)
        return;
    
    postorder(head->left);
    postorder(head->right);
    printf("%d ", head->data);
}

int get_height(Node* root) {
    if(root == nullptr) 
        return(0);
    return(std::max(get_height(root->left), get_height(root->right)) + 1);
}

bool is_balanced(Node* root) {
    if(root == nullptr)
        return(true);
    int height_diff = get_height(root->left) - get_height(root->right);
    if(std::abs(height_diff) > 1) {
        return(false);
    }
    else {
        return(is_balanced(root->left) and is_balanced(root->right));
    }
}

int check_height(Node* root) {
    if(root == nullptr) 
        return(0);
    
    int left_height = check_height(root->left);
    if(left_height == -1) {
        return(-1);
    }
    
    int right_height = check_height(root->right);
    if(right_height == -1) {
        return(-1);
    }
    
    int height_diff = left_height - right_height;
    if(std::abs(height_diff) > 1) {
        return(-1);
    }
    else {
        return(std::max(left_height, right_height) + 1);
    }
}



int main(int argc, char** argv) {
    /*
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
    */
    
    Node* bt = new Node(0);
    bt->left = new Node(1);
    bt->right = new Node(2);
    bt->left->left = new Node(3);
    bt->left->right = new Node(4);
    bt->right->left = new Node(5);
    bt->right->right = new Node(6);
    /*
      0
    1    2
  3  4  5  6    

    */
    
    
    inorder(bt);  printf("\n");
    preorder(bt);  printf("\n");
    postorder(bt);  printf("\n");
    printf("%d\n", is_balanced(bt));
    printf("%d\n", check_height(bt));
    
    Node* bt1 = new Node(1);
    bt1->left = new Node(2);
    bt1->right = new Node(3);
    bt1->left->left = new Node(4);
    bt1->left->right = new Node(5);
    bt1->left->left->left = new Node(6);
    bt1->left->left->right = new Node(7);
    
    /*
      1
    2    3
  4  5
6   7  
    */
    
    
    inorder(bt1);  printf("\n");
    preorder(bt1);  printf("\n");
    postorder(bt1);  printf("\n");
    
    printf("%d\n", is_balanced(bt1));
    printf("%d\n", check_height(bt1));
    
}