/*
 * Problem: Depth First Search (DFS) and Breadth First Search (BFS)
 * (c) Mohammad Hasanzadeh Mofrad, 2019
 * (e) m.hasanzadeh.mofrad@gmail.com
 * Compile and run: g++ -o dfs_bfs dfs_bfs.cpp && ./dfs_bfs
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <time.h>

struct Node {
    Node() {value = 0; left = nullptr; right = nullptr;}
    Node(int v) {value = v; left = nullptr; right = nullptr;}
    int value;
    struct Node* left;
    struct Node* right;
};

void insert(struct Node** root, int v) {
    struct Node* temp = *root;
    struct Node* new_node = new Node(v);
    if(temp == NULL) {
        *root = new_node;
        //printf("If %d\n", temp->value);
        printf("Root\n");
    }
    else {
        //printf("Else %d\n", (*root)->value);
        while(1) {
            if(temp->left == nullptr) {
                printf("left %d\n", new_node->value);
                temp->left = new_node;
                break;
            }
            else if(temp->right == nullptr) {
                printf("Right %d\n", new_node->value);
                temp->right = new_node;
                break;
            }
            else {
                int r = rand() % 100;

                if(r < 50) {
                    temp = temp->left;
                    printf("left ");
                }
                else {
                    temp = temp->right;
                    printf("Right ");
                }
            }
        }
        
    }
}

void traverse_dfs(struct Node* root) {
    if(root == NULL) return;
    
    printf("%d ", root->value);
    if(root->left) {
        traverse_dfs(root->left);
    }
    if(root->right) {
        traverse_dfs(root->right);
    }
}

void traverse_bfs(struct Node* root) {
    if(root == NULL) return;
    
    printf("%d ", root->value);
    
    std::queue<struct Node*> queue;
    queue.push(root);
    
    int i = 0;
    while(queue.size()) {
        auto& q = queue.front();
        int j = i;
        if(q->left) {
            printf("%d ", q->left->value);
            queue.push(q->left);
        }
        if(q->right) {
            printf("%d ", q->right->value);
            queue.push(q->right);
        }
        queue.pop();
    }
}
 
int main(int argc, char** argv) {
    srand(time(NULL));
    printf("DFS\n");
    struct Node* root = NULL;
    insert(&root, 0);
    struct Node* head = root;
    for(int i = 1; i < 10; i++) {
        head = root;
        insert(&head, i);
    }
    printf("DFS: ");
    traverse_dfs(root);
    printf("\n");
    printf("BFS: ");
    traverse_bfs(root);
    printf("\n");
    
    return(0);
}