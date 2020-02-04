/*
 *  Problem: https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
 *  Lowest Common Ancestor in a Binary Tree: Given a binary tree (not a binary search tree) and two values say n1 and n2, 
 *  write a program to find the least common ancestor.
 *  Compile: gcc -o LCA_BT LCA_BT.c -g -Wall -fsanitize=address && ./LCA_BT    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Stack {
    struct Node* tree_node;
    struct Stack* next;
};

struct Node* allocate(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    memset(node, 0, sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void deallocate(struct Node* node) {
    free(node);
}

struct Stack* allocate_s(struct Node* root) {
    struct Stack* node = (struct Stack*) malloc(sizeof(struct Stack));
    memset(node, 0, sizeof(struct Stack));
    node->tree_node = root;
    node->next = NULL;
    return(node);
}

void deallocate_s(struct Stack* node) {
    free(node);
}

struct Node* peek(struct Stack* top) {
    struct Node* node = NULL;
    if(top) {
        node = top->tree_node;
    }
    return(node);
}

void push(struct Stack** top, struct Node* root) {
    if(*top) {
        struct Stack* node = allocate_s(root);
        node->next = *top;
        *top = node;
    }
    else {
        *top = allocate_s(root);
    }
}

void pop(struct Stack** top) {
    if(*top) {
        struct Stack* temp = *top;
        *top = (*top)->next;
        deallocate_s(temp);
    }
}

void traverse(struct Node* root) {
    if(root) {
        printf("%d ", root->data);
        traverse(root->left);
        traverse(root->right);
    }
}

void DFS(struct Node* root) {
    if(root) {
        struct Stack* s = NULL;
        push(&s, root);
        while(s) {
            struct Node* n = peek(s);
            printf("%d\n", n->data);   
            pop(&s);
            if(n->right) {
                push(&s, n->right);
            }
            if(n->left) {
                push(&s, n->left);
            }
        }
    }
}

void DFS_Search(struct Node* root, struct Node* n1, int vec[]) {
    int i = 0;
    if(root) {
        struct Stack* s = NULL;
        push(&s, root);
        while(s) {
            struct Node* n = peek(s);
            vec[i] = n->data;
            i++;
            if(n->data == n1->data) {
                break;
            }
            pop(&s);
            if(n->right) {
                push(&s, n->right);
            }
            if(n->left) {
                push(&s, n->left);
            }
        }
    }
}



int LCA(struct Node* root, int n, struct Node* n1, struct Node* n2) {
    int lca = -1;
    int n1_vec[n];
    int n2_vec[n];
    memset(n1_vec, 0, sizeof(n1_vec));
    memset(n2_vec, 0, sizeof(n2_vec));
    
    DFS_Search(root, n1, n1_vec);
    DFS_Search(root, n2, n2_vec);
    
    for(int i = 0; i < n; i++) {
        printf("%d ", n1_vec[i]);
    }
    printf("\n");
    
    for(int i = 0; i < n; i++) {
        printf("%d ", n2_vec[i]);
    }
    printf("\n");
    
    int i1 = 0;
    int i2 = 0;
    while((i1 < n) && (i2 < n)) {
        if((n1_vec[i1] == n2_vec[i1]) && ((n1_vec[i1] != n1->data) && (n2_vec[i2] != n2->data))) {
            i1++;
            i2++;
        }
        else {
            if(i1 > 0) {
                i1--;
                i2--;
            }
            break;
        }
    }
    lca = n1_vec[i1];
    
    return(lca);
}

/*
         1
     /        \
    2          3
 /     \     /    \
4       5   6       7
*/


int main(int argc, char **argv){
    struct Node* root = allocate(1);
    root->left = allocate(2);
    root->left->left = allocate(4);
    root->left->right = allocate(5);
    root->right = allocate(3);
    root->right->left = allocate(6);
    root->right->right = allocate(7);
    
    //traverse(root);
    //printf("\n");
    
    //DFS(root);
    
    int n = 7;
    int lca = LCA(root, n, root->left->left, root->right->right);
    printf("%d\n", lca);
    
    
    free(root->left->right);
    free(root->left->left);
    free(root->left);
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root);
    
    return(0);
}
