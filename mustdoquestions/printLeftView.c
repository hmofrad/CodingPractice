/*
 *  Problem: https://www.geeksforgeeks.org/print-left-view-binary-tree/
 *  Print Left View of a Binary Tree
 *  Compile: gcc -o printLeftView printLeftView.c -g -Wall -fsanitize=address && ./printLeftView   
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

struct Queue_Node {
    struct Node* tree_node;
    struct Queue_Node* next;
};

void enqueue(struct Queue_Node** head, struct Node* tree_node) {
    if(!*head) {
        *head = (struct Queue_Node*) malloc(sizeof(struct Queue_Node));
        (*head)->tree_node = tree_node;
        (*head)->next = NULL;
    }
    else {
        struct Queue_Node* curr = *head;
        while(curr->next) curr = curr->next;
        curr->next = (struct Queue_Node*) malloc(sizeof(struct Queue_Node));
        curr->next->tree_node = tree_node;
        curr->next->next = NULL;    
    }
}

void dequeue(struct Queue_Node** head) {
    if(*head) {
        struct Queue_Node* node = *head;
        *head = (*head)->next;
        free(node);
    }
}

int size(struct Queue_Node* head) {
    int sz = 0;
    while(head) {
        sz++;
        head = head->next;
    }
    return(sz);
}


void BFS(struct Node* root) {
    if(root) {
        struct Queue_Node* q = NULL;
        enqueue(&q, root);
        while(q) {
            int level = size(q);
            int m = level;
            while(level) {
                if(level == m)
                    printf("%d ", q->tree_node->data);
                level--;
                if(q->tree_node->left) {
                    enqueue(&q, q->tree_node->left);
                }
                if(q->tree_node->right) {
                    enqueue(&q, q->tree_node->right);
                }
                dequeue(&q);
            }
            
        }
        printf("\n");
    }
}

struct Stack_Node {
    struct Node* tree_node;
    struct Stack_Node* prev;
};

void push(struct Stack_Node** top, struct Node* tree_node) {
    if(!*top) {
        *top = (struct Stack_Node*) malloc(sizeof(struct Stack_Node));
        (*top)->tree_node = tree_node;
        (*top)->prev = NULL;
    }
    else {
        struct Stack_Node* node = (struct Stack_Node*) malloc(sizeof(struct Stack_Node));
        node->tree_node = tree_node;
        node->prev = *top;
        *top = node;
    }
}

void pop(struct Stack_Node** top) {
    if(*top) {
        struct Stack_Node* node = *top;
        *top = (*top)->prev;
        free(node);
    }
}


/*
   4
  / \
 5    2
     /  \
    3    1
   /  \
  6    7
*/


void DFS(struct Node* root) {
    printf("DFS\n");
    if(root) {
        struct Stack_Node* s = NULL;
        struct Node* c = root;
        while((c != NULL) || (s != NULL)) {
            while(c != NULL) {
                push(&s, c);
                c = c->left;
            }
            
            c = s->tree_node;
            pop(&s);
            printf("%d ", c->data);
            c = c->right;
        }
        printf("\n");
    }
}


void traverse(struct Node* root) {
    if(root) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

int main(int argc, char** argv){
    struct Node* root = (struct Node*) malloc(sizeof(struct Node));
    root->data = 4;
    
    root->left = (struct Node*) malloc(sizeof(struct Node));
    root->left->data = 5;
    root->left->left = NULL;
    root->left->right = NULL;
    
    root->right = (struct Node*) malloc(sizeof(struct Node));
    root->right->data = 2;
    
    root->right->right = (struct Node*) malloc(sizeof(struct Node));
    root->right->right->data = 1;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    
    root->right->left = (struct Node*) malloc(sizeof(struct Node));
    root->right->left->data = 3;
    
    root->right->left->left = (struct Node*) malloc(sizeof(struct Node));
    root->right->left->left->data = 6;
    root->right->left->left->left = NULL;
    root->right->left->left->right = NULL;
    root->right->left->right = (struct Node*) malloc(sizeof(struct Node));
    root->right->left->right->data = 7;
    root->right->left->right->left = NULL;
    root->right->left->right->right = NULL;
    
    
    traverse(root); printf("\n");
    BFS(root);
    DFS(root);
    
    free(root->right->left->right);
    free(root->right->left->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    
    free(root->left);
    
    free(root);
    
    return(0);
}
