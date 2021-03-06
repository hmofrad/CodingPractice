/*
 *  Problem: https://www.geeksforgeeks.org/connect-nodes-at-same-level/
 *  Write a function to connect all the adjacent nodes at the same level in a binary tree.
 *  Compile: gcc -o connectBST connectBST.c -g -Wall -fsanitize=address && ./connectBST    
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
    struct Node* nextRight;
};



struct Node* allocate(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    memset(node, 0, sizeof(struct Node));
    if(node == NULL) {
        printf("ERROR: Allocating data\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->nextRight = NULL;
    return(node);
}

void deallocate(struct Node* node) {
    free(node);
}

struct Queue {
    struct Node* bst_node;
    struct Queue* next;
};

struct Queue* allocate_q() {
    struct Queue* node = (struct Queue*) malloc(sizeof(struct Queue));
    memset(node, 0, sizeof(struct Queue));
    if(node == NULL) {
        printf("ERROR: Allocating data\n");
        exit(1);
    }
    node->bst_node = NULL;
    node->next = NULL;
    return(node);
}

void deallocate_q(struct Queue* node) {
    free(node);
}


void enqueue(struct Queue** head, struct Node* node) {
    if(*head == NULL) {
        *head = allocate_q();
        (*head)->bst_node = node;
    }
    else {
        while((*head)->next) {
            *head = (*head)->next;
        }
        (*head)->next = allocate_q();
        (*head)->next->bst_node = node;
    }
}

struct Node* peek(struct Queue* head) {
    struct Node* node = NULL;    
    if(head) {
        node = head->bst_node;
    }
    return(node);
}

void dequeue(struct Queue** head) {
    struct Queue* temp = NULL;    
    if(*head) {
        temp = (*head)->next;
        deallocate_q(*head);
        *head = temp;
    }
}



void traverse_q(struct Queue* head) {
   while(head) {
       printf("%d\n", head->bst_node->data);
       head = head->next;
   }
}

int size_q(struct Queue* head) {
    int sz = 0;
   while(head) {
       sz++;
       head = head->next;
   }
   return(sz);
}



void traverse(struct Node* root) {
    if(root) {
        printf("%d ", root->data);
        traverse(root->left);
        traverse(root->right);
    }
}

void traverse1(struct Node* root) {
    if(root) {
        printf("[%d ", root->data);
        if(root->nextRight) {
            printf("%d] ", root->nextRight->data);
        }
        else {
            printf("] ");
        }
        traverse1(root->left);
        traverse1(root->right);
    }
}


void BFS(struct Node* root) {
    struct Queue* q = NULL;
    struct Queue* h = NULL;
    int level = 0;
    if(root) {
        enqueue(&q, root);
        h = q;
        //i++;
        while(q) {
            printf("level=%d\n", level);
            int level_sz = size_q(q);
            
            while(level_sz--) {
                struct Node* n = peek(q);
                printf("level_sz=%d %d\n",level_sz, n->data);
                if(n->left) {
                    h = q;
                    enqueue(&h, n->left);
                }
                
                if(n->right) {
                    h = q;
                    enqueue(&h, n->right);
                }
                
                if(q->next && level_sz) {
                    n->nextRight = q->next->bst_node;
                }
                else {
                    n->nextRight = NULL;
                }
                dequeue(&q);
            }
            level++;
            
            
            //if(i == my_pow(2,k)) {
              //  k++;
            //}
            //n->nextRight = NULL;
            //i *= 2;

        }   
    }
    
    //free(q);
}



/*
Input:
        1
      /    \ 
    2       3 
  /    \      \
4       5      6

Output:
        1 -> null
      /    \ 
    2  ---> 3 --> null
  /    \      \
4  ---> 5  ---> 6  --> null
*/

int main(int argc, char **argv){
    struct Node* root = allocate(1);
    root->left = allocate(2);
    root->left->left = allocate(4);
    root->left->right = allocate(5);
    
    root->right = allocate(3);
    root->right->right = allocate(6);
    
    traverse(root);
    printf("\n");
    
    BFS(root);
    traverse1(root);
    printf("\n");
    
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    
    free(root->right->right);
    free(root->right);
    
    free(root);
    
    return(0);
}
