/*
 *  Problem: https://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
 *  Root to leaf path sum equal to a given number
 *  Compile: gcc -o pathSum pathSum.c -g -Wall -fsanitize=address && ./pathSum    
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

struct Queue{
    struct Node* node;
    int sum;
    struct Queue* next;
};

struct Queue* allocate_q(struct Node* t_node, int path_sum) {
    struct Queue* q_node = malloc(sizeof(struct Queue));
    q_node->node = t_node;
    q_node->sum = t_node->data + path_sum;
    q_node->next = NULL;
    return(q_node);
}

void deallocate_q(struct Queue* q_node) {
    free(q_node);
}

struct Node* front(struct Queue* head) {
    struct Node* t_node = NULL;
    if(head) {
        t_node = head->node;
    }
    return(t_node);
}

void enqueue(struct Queue** head, struct Node* t_node, int path_sum) {
    struct Queue* curr = *head;
    if(curr == NULL) {
        curr = allocate_q(t_node, path_sum);
        *head = curr;
    }
    else {
        while(curr->next) {
            curr = curr->next;
        }
        curr->next = allocate_q(t_node, path_sum);
    }
}


void dequeue(struct Queue** head) {
    if(*head) {
        struct Queue* temp = *head;
        *head = (*head)->next;
        deallocate_q(temp);
    }
}

int BFS(struct Node* root, int sum) {
    int ret = 0;
    struct Queue* q = NULL;
    if(root) {
        enqueue(&q, root, 0);
        //struct Queue* q = allocate_q(root);
        while(q) {
            struct Node* c = front(q);
            //printf("%d %d\n", c->data, q->sum);
            
            if(c->left) {
                enqueue(&q, c->left, q->sum);
                
            }

            if(c->right) {
                enqueue(&q, c->right, q->sum);
            }
            
            if((c->left == NULL) && (c->right == NULL)) {
                if(q->sum == sum) {
                    ret = 1;
                }
                //printf(" %d %d\n", c->data, q->sum);
            }
            
            dequeue(&q);
        }
    }
    return(ret);
}

/*
       10
    /     \
   8        2      
  /  \      /
3      5   2
*/


int main(int argc, char **argv){
   struct Node* root = allocate(10);
   root->left = allocate(8);
   root->left->left = allocate(3);
   root->left->right = allocate(5);
   root->right = allocate(2);
   root->right->left = allocate(2);
   
   traverse1(root);
   int sum = 23;
   int ret = BFS(root, sum);
   printf("? %d\n", ret);
   
   deallocate(root->left->left);
   deallocate(root->left->right);
   deallocate(root->left);
   deallocate(root->right->left);
   deallocate(root->right);
   deallocate(root);
    
    return(0);
}
