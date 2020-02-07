/*
 *  Problem: https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/
 *  Convert a given tree to its Sum Tree
 *  Compile: gcc -o convertTree convertTree.c -g -Wall -fsanitize=address && ./convertTree    
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

void traverse1(struct Node* root) {
   traverse(root);
   printf("\n");
}


int convert(struct Node* root) {
    if(root) {
        int me = root->data;
        root->data = convert(root->left) + convert(root->right);
        return(me + root->data);
    }
    else {
        return(0);
    }
}

/*
Input:
                  10
               /      \
             -2        6
           /   \      /  \ 
         8     -4    7    5
 
Output:
             20(4-2+12+6)
               /      \
         4(8-4)      12(7+5)
           /   \      /  \ 
         0      0    0    0 
*/


int main(int argc, char **argv){
   struct Node* root = allocate(10);
   root->left = allocate(-2);
   root->left->left = allocate(8);
   root->left->right = allocate(-4);
   root->right = allocate(6);
   root->right->left = allocate(7);
   root->right->right = allocate(5);
   
   traverse1(root);
   convert(root);
   traverse1(root);
   
   
   deallocate(root->left->left);
   deallocate(root->left->right);
   deallocate(root->left);
   deallocate(root->right->left);
   deallocate(root->right->right);
   deallocate(root->right);
   deallocate(root);
    
    return(0);
}
