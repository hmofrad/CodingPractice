/*
 *  Problem: https://www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/
 *  Find the largest BST subtree in a given Binary Tree
 *  Compile: gcc -o largestBST largestBST.c -g -Wall -fsanitize=address && ./largestBST   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* allocate(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void deallocate(struct Node* node) {
    if(node) free(node);
}



struct Node* create_tree() {
    struct Node* root = allocate(50);
    root->left = allocate(30);
    root->left->left = allocate(5);
    root->left->right = allocate(20);
    
    root->right = allocate(60);
    root->right->left = allocate(45);
    root->right->right = allocate(70);
    root->right->right->left = allocate(65);
    root->right->right->right = allocate(80);
    return(root);
}

void delete_tree(struct Node** root) {
    free((*root)->right->right->right);
    free((*root)->right->right->left);
    free((*root)->right->right);
    free((*root)->right->left);
    free((*root)->right);
    
    free((*root)->left->right);
    free((*root)->left->left);
    free((*root)->left);
    
    free(*root);
}

void traverse(struct Node* root) {
    if(root){
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

int isBST(struct Node* root, int min, int max) {
    //int ret = 0;
    if(root) {
        if((root->data < min) || (root->data > max)) {
            return(0);
        }
        else {
            return((isBST(root->left, min, root->data-1)) && 
                   (isBST(root->right, root->data+1, max)));
        }
    }
    else {
        return(1);
    }
}

int maxi(int a, int b) {
    return((a > b) ? a : b);
}

int get_height(struct Node* root) {
    if(root) {
        return(maxi(get_height(root->left), get_height(root->right))+1);
    }
    else {
        return(0);
    }
}

int get_size(struct Node* root) {
    if(root) {
        return(get_size(root->left)+get_size(root->right)+1);
    }
    else {
        return(0);
    }
}


int check(struct Node* root) {
    int ret = 0;
    int min = INT_MIN;
    int max = INT_MAX;
    
    if(root) {
        ret = isBST(root->right, min, max);
    }
    
    printf("height=%d size=%d\n", get_height(root), get_size(root));
    return(ret);
}



/*

Input: 
       50
     /    \
  30       60
 /  \     /  \ 
5   20   45    70
              /  \
            65    80
Output: 5
The following subtree is the maximum size BST subtree 
      60
     /  \ 
   45    70
        /  \
      65    80
*/

int main(int argc, char** argv){
    struct Node* root = create_tree();
    traverse(root); printf("\n");
    int is = check(root);
    printf("%d\n", is);
    delete_tree(&root);
    return(0);
}
