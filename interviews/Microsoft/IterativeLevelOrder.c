/*
 *  Problem: https://www.geeksforgeeks.org/level-order-tree-traversal/
 *  Level Order Tree Traversal
 *  Compile: gcc -o IterativeLevelOrder IterativeLevelOrder.c -g -Wall -fsanitize=address && ./IterativeLevelOrder    
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

/*
int get_height(struct Node* root) {
    if(root == NULL) {
        return(0);
    }
    else {
        int left_height = get_height(root->left);
        int right_height = get_height(root->right);
        
        if(left_height > right_height) {
            return(left_height+1);
        }
        else {
            return(right_height+1);
        }
    }
}
*/

int get_height(struct Node* root) {
    if(root) {
        int left_height = get_height(root->left);
        int right_height = get_height(root->right);
        return((left_height > right_height) ? (left_height+1) : (right_height+1));
    }
    else {
        return(0);
    }
}

void printLevel(struct Node* root, int level) {
    if(root) {
        if(level == 1) {
            printf("%d\n", root->data);
        }
        else {
            printLevel(root->left, level-1);
            printLevel(root->right, level-1);
        }
    }
}


void print(struct Node* root) {
    int h = get_height(root);
    
    for(int i = 1; i <= h; i++) {
        printLevel(root, i);
    }
}



/*
       10
    /     \
   8        2      
  /  \      /
3      5   2
            \
             3
*/


int main(int argc, char **argv){
   struct Node* root = allocate(10);
   root->left = allocate(8);
   root->left->left = allocate(3);
   root->left->right = allocate(5);
   root->right = allocate(2);
   root->right->left = allocate(2);
   root->right->left->right = allocate(3);
   
   traverse1(root);
   
   int h = get_height(root);
   printf("Height=%d\n", h);
   
   print(root);
   
   deallocate(root->left->left);
   deallocate(root->left->right);
   deallocate(root->left);
   deallocate(root->right->left->right);
   deallocate(root->right->left);
   deallocate(root->right);
   deallocate(root);
    
    return(0);
}
