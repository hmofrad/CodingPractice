/*
 *  Problem: https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
 *  How to determine if a binary tree is height-balanced?
 *  Compile: gcc -o balancedTree balancedTree.c -g -Wall -fsanitize=address && ./balancedTree    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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


int height(struct Node* root) {
    if(root) {
        int l = height(root->left);
        int r = height(root->right);
        int m = (l > r) ? l : r;
        return(1 + m);
    }
    else {
        return(0);
    }
}

/*
int is_balanced(struct Node* root, int* height) {
    int h_l = 0;
    int h_r = 0;
    if(root) {
        *height = *height+1;
        h_l = is_balanced(root->left, height);
        h_r = is_balanced(root->left, height);
    }
    
    return((h_l == (h_r+1)) || (h_r == (h_l+1)))
}
*/

int abs(int a) {
    return((a < 0) ? -a : a);
}

int check_if_balanced(struct Node* root) {
    if(root == NULL) {
        return(1);
    }
    
    int l = height(root->left);
    int r = height(root->right);
    printf("%d %d\n", l, r);
    if((abs(l-r) <= 1) && (check_if_balanced(root->left)) && (check_if_balanced(root->right))) {
        return(1);
    }
        
    return(0);
}

/*

Height balanced:
    1
   /  \
  3    2
 /
4

Height Imbalanced:
     1
   /  \
  3    2
 /
4
  \
   5
*/


int main(int argc, char **argv){
   struct Node* root = allocate(1);
   root->left = allocate(3);
   root->left->left = allocate(4);
   root->right = allocate(2);
   root->right->right = allocate(5);
   //root->right->right->right = allocate(6);
   //root->right->right->right->right = allocate(7);
   
   int ret = check_if_balanced(root);
   printf("RET=%d\n", ret);
   
   deallocate(root->left->left);
   deallocate(root->left);
   //deallocate(root->right->right->right->right);
   //deallocate(root->right->right->right);
   deallocate(root->right->right);
   deallocate(root->right);
   deallocate(root);
    
    return(0);
}
