/*
 *  Problem: https://www.geeksforgeeks.org/print-nodes-at-k-distance-from-root/
 *  Given a root of a tree, and an integer k. Print all the nodes which are at k distance from root.
 *  Compile: gcc -o rootDistance rootDistance.c -g -Wall -fsanitize=address && ./rootDistance    
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


struct Queue {
    struct Node* tree_node;
    struct Queue* next;
};


struct Queue* allocate_q(struct Node* tree_node) {
    struct Queue* node = malloc(sizeof(struct Queue));
    node->tree_node = tree_node;
    node->next = NULL;
    return(node);
}

void deallocate_q(struct Queue* node) {
    free(node);
}

struct Node* front(struct Queue* head) {
    struct Node* node = NULL;
    if(head) {
        node = head->tree_node;
    }
    return(node);
}

void enqueue(struct Queue** head, struct Node* tree_node) {
    struct Queue* curr = *head;
    if(curr == NULL) {
        *head = allocate_q(tree_node);
    }
    else {
        while(curr->next) {
            curr = curr->next;
        }
        curr->next = allocate_q(tree_node);
    }
    
}

void dequeue(struct Queue** head) {
    if(*head) {
        struct Queue* temp = *head;
        *head = (*head)->next;
        deallocate_q(temp);
    }
}

int queue_size(struct Queue* head) {
    int size = 0;
    while(head) {
        head = head->next;
        size++;
    }
    return(size);
}

void BFS(struct Node* root, int d) {
    struct Queue* q = NULL;
    int k = 0;
    if(root) {
        enqueue(&q, root);
        while(q) {
            int level = queue_size(q);
            while(level--) {
                struct Node* c = q->tree_node;
                if(k == d)
                    printf("[%d %d] ", c->data, k);
                
                if(c->left) {
                    enqueue(&q, c->left);
                }
                if(c->right) {
                    enqueue(&q, c->right);
                }
                dequeue(&q);
            }
            k++;
            printf("\n");
        }
    }
}

void printDistance(struct Node* root, int d) {
    if(root) {
        if(d == 0) {
            printf("%d\n", root->data);
        }
        else {
            printDistance(root->left, d-1);
            printDistance(root->right, d-1);
        }
    }
    
}


/*
            1
          /   \
        2      3
      /  \    /
    4     5  8 
*/


int main(int argc, char **argv){
   struct Node* root = allocate(1);
   root->left = allocate(2);
   root->left->left = allocate(4);
   root->left->right = allocate(5);
   root->right = allocate(3);
   root->right->left = allocate(8);
   
   traverse1(root);
   int d = 2;
   BFS(root, d);
   
   printDistance(root, d);
   
   
   deallocate(root->left->left);
   deallocate(root->left->right);
   deallocate(root->left);
   deallocate(root->right->left);
   deallocate(root->right);
   deallocate(root);
    
    return(0);
}
