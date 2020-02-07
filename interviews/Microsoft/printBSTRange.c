/*
 *  Problem: https://www.geeksforgeeks.org/print-bst-keys-in-the-given-range/
 *  Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. 
 *  Print all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2 and x is a key of given BST. 
 *  Print all the keys in increasing order.
 *  Compile: gcc -o printBSTRange printBSTRange.c -g -Wall -fsanitize=address && ./printBSTRange    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* allocate(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void deallocate(struct Node* node) {
    free(node);
}

void traverse(struct Node* root) {
    if(root) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
        
    }
}

void print_range(struct Node* root, int k1, int k2) {
    if(root) {
        print_range(root->left, k1, k2);
        if((root->data >= k1) && (root->data <= k2)) {
            printf("%d ", root->data);
        }
        print_range(root->right, k1, k2);
    }
}


int main(int argc, char **argv){
   struct Node* root = allocate(20);
   root->left = allocate(8);
   root->left->left = allocate(4);
   root->left->right = allocate(12);
   root->right = allocate(22);
   
   traverse(root);
   printf("\n");
   
   print_range(root, 10,30);
   printf("\n");
   
   deallocate(root->left->left);
   deallocate(root->left->right);
   deallocate(root->left);
   deallocate(root->right);
   deallocate(root);
    
    return(0);
}
