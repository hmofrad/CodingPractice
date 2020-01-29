/*
 *  Problem: https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
 *  A binary search tree (BST) is a node based binary tree data structure which has the following properties
 *  Compile: gcc -o checkIfBST checkIfBST.c -g -Wall -fsanitize=address && ./checkIfBST
 *  
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* allocate(int data) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return(temp);
}

void deallocate(struct Node* node) {
    free(node);
    node = NULL;
}


void traverse(struct Node* root) {
    if(root) {
        printf("%d ", root->data);
        traverse(root->left);
        traverse(root->right);
    }
}

int traverse1(struct Node* root, int min, int max) {
    if(root == NULL) {
        return(1);
    }
    
    if((root->data < min) || (root->data > max)) {
        return(0);
    }
    return(traverse1(root->left, min, root->data-1) &&
           traverse1(root->right,root->data+1, max));
}

void check(struct Node* root) {
    int min = INT_MIN;
    int max = INT_MAX;

    //min = (root->data < min) ? root->data : min;
    int ret = traverse1(root, min, max);
    printf("ret = %d\n", ret);
}

/*

       3
   2      5
1    4

*/

int main(int argc, char **argv){
    struct Node* root = allocate(5);
    root->left = allocate(2);
    root->left->left = allocate(1);
    root->left->right = allocate(4);
    root->right = allocate(6);
    
    check(root);
    //traverse(root);
    //printf("\n");
    
    deallocate(root->left->left);
    deallocate(root->left->right);
    deallocate(root->left);
    deallocate(root->right);
    deallocate(root);
    
    return(0);
}
