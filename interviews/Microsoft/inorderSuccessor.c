/*
 *  Problem: https://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/
 *  Inorder Successor in Binary Search Tree
 *  Compile: gcc -o inorderSuccessor inorderSuccessor.c -g -Wall -fsanitize=address && ./inorderSuccessor   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void traverse(struct Node* root) {
    if(root) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

int get_min(struct Node* root) {
    int min = 0;
    if(root) {
        while(root->left) {
            root = root->left;
        }
        min = root->data; 
    }
    return(min);
}

/*
int successor1(struct Node* root, struct Node* node, int i) {
    
    if(root) {
        if(root->data == node->data) {
            if(root->right) return(successor1(root->right->data, node, 1);
            else return(-1);
        }
        else {
            return(successor1(root->left, node, i));
            return(successor1(root->right, node, i));
        }
    }
    else {
        return(-1);
    }
}
*/


int successor(struct Node* root, struct Node* node) {
    if(node->right) return(get_min(node->right));
    
    struct Node* succ = NULL;
    while(root) {
        if(node->data < root->data) {
            succ = root;
            root = root->left;
        }
        else if(node->data > root->data) {
            root = root->right;
        }
        else {
            break;
        }            
    }
    return(succ->data);
}


int main(int argc, char** argv){
    struct Node* root = (struct Node*) malloc(sizeof(struct Node));
    root->data = 20;
    root->right = (struct Node*) malloc(sizeof(struct Node));
    root->right->data = 22;
    root->right->left = NULL;
    root->right->right = NULL;
    root->left = (struct Node*) malloc(sizeof(struct Node));
    root->left->data = 8;
    root->left->left = (struct Node*) malloc(sizeof(struct Node));
    root->left->left->data = 4;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = (struct Node*) malloc(sizeof(struct Node));
    root->left->right->data = 12;
    root->left->right->left = (struct Node*) malloc(sizeof(struct Node));
    root->left->right->left->data = 10;
    root->left->right->left->left = NULL;
    root->left->right->left->right = NULL;
    root->left->right->right = (struct Node*) malloc(sizeof(struct Node));
    root->left->right->right->data = 14;
    root->left->right->right->left = NULL;
    root->left->right->right->right = NULL;
    
    traverse(root); printf("\n");
    printf("%d\n", get_min(root));
    printf("%d\n", successor(root, root->left->right->right));
    free(root->left->right->right);
    free(root->left->right->left);
    free(root->left->right);
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);
    
    return(0);
}
