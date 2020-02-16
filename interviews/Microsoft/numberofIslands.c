/*
 *  Problem: https://www.geeksforgeeks.org/find-number-of-islands/
 *  Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island. 
 *  For example, the below matrix contains 5 islands
 *  Compile: gcc -o numberofIslands numberofIslands.c -g -Wall -fsanitize=address && ./numberofIslands   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node{
    int data;
    struct Node* prev;
};

struct Node* allocate(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    return(node);
}

void deallocate(struct Node* node) {
    if(node) free(node);
}

void push(struct Node** top, int data) {
    if(*top == NULL) {
        *top = allocate(data);
    }
    else {
        struct Node* node = allocate(data);
        node->prev = *top;
        *top = node;
    }
}

void pop(struct Node** top) {
    if(*top) {
        struct Node* node = *top;
        *top = (*top)->prev;
        deallocate(node);
    }
}

struct Node* peek(struct Node* top) {
    return((top) ? top : NULL);
}

void print(int mat[6][6], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {   
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void DFS(int mat[6][6], int m, int n) {
    struct Node* s = NULL;
    
    int visited[m];
    memset(visited, 0, sizeof(visited));
    /*
    print(mat, m, n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {   
            if(mat[i][j] && (i > j)) {
                mat[i][j] = 0;
                mat[j][i] = 1;
            }
            if(mat[i][j] && i == j) {
                mat[i][j] = 0;
            }
        }
    }
    */

    print(mat, m, n);
    
    
    for(int i = 0; i < m; i++) {
        if(mat[i][i] && visited[i] == 0) {
            visited[i] = 1;
            push(&s, i);
        }
        for(int j = 0; j < n; j++) {    
            if(mat[i][j]) {
                if(visited[j] == 0) {
                    visited[j] = 1;
                    push(&s, j);
                }
            }
        }
        while(s) {
            printf("%d ", (peek(s))->data);
            int k = (peek(s))->data;
            pop(&s);
            for(int j = 0; j < n; j++) {    
                if(mat[k][j]) {
                    if(visited[j] == 0) {
                        visited[j] = 1;
                        push(&s, j);
                    }
                }
            }
        }
        printf("\n");
        //exit(0);
    }
}




int main(int argc, char** argv){
    int m = 6;
    int n = 6;
    int mat[6][6] = {{1, 1, 0, 0, 0, 0},
                     {0, 1, 0, 0, 1, 0},
                     {1, 0, 0, 1, 1, 0},
                     {0, 0, 0, 0, 0, 0},
                     {1, 0, 1, 0, 1, 0},
                     {0, 0, 0, 0, 0, 1}};
    
    int c = sizeof(mat[0])/sizeof(mat[0][0]) ;
    int r = sizeof(mat)/sizeof(mat[0]);
    printf("#rows=%d #cols=%d\n", r, c);
    DFS(mat, m, n);
       
    
    return(0);
}
