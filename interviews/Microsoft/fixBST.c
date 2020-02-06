/*
 *  Problem: https://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst/
 *  Two nodes of a BST are swapped, correct the BST
 *  Compile: gcc -o fixBST fixBST.c -g -Wall -fsanitize=address && ./fixBST    
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

void traverse(struct Node* root) {
    if(root) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
        
    }
}


/*

Input Tree:
         10
        /  \
       5    8
      / \
     2   20
     
In the above tree, nodes 20 and 8 must be swapped to fix the tree.  
Following is the output tree
         10
        /  \
       5    20
      / \
     2   8
*/

void fix1(struct Node* root, int arr[], int* i) {
    if(root){
        //printf("i=%d %d\n", *i, root->data);
        fix1(root->left, arr, i);
        //if(root->left)
        arr[*i] = root->data;
        *i += 1;
        //printf("i==%d %d\n", *i-1, root->data );
        fix1(root->right, arr, i);
    }
}


void fix2(struct Node* root, int arr[], int* i) {
    if(root){
        //printf("i=%d %d\n", *i, root->data);
        fix2(root->left, arr, i);
        //if(root->left)
        root->data = arr[*i];
        *i += 1;
        //printf("i==%d %d\n", *i-1, root->data );
        fix2(root->right, arr, i);
    }
}



int main(int argc, char **argv){
   struct Node* root = allocate(10);
   root->left = allocate(5);
   root->left->left = allocate(2);
   root->left->right = allocate(20);
   root->right = allocate(8);
   
   traverse(root);
   printf("\n");
   int n = 5;
   int arr[n];
   memset(arr, n, sizeof(arr));
   int index = 0;
   fix1(root, arr, &index);
   
   for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
   }
   
   
   index = 0;
   fix2(root, arr, &index);
   /*
   for(int i = 0; i < n; i++) {
       printf("%d ", arr[i]);
   }
   printf("\n");
   */
   
   traverse(root);
   printf("\n");
   
   //int ret = check_if_balanced(root);
   //printf("RET=%d\n", ret);
   
   deallocate(root->left->left);
   deallocate(root->left->right);
   deallocate(root->left);
   deallocate(root->right);
   deallocate(root);
    
    return(0);
}
