/*
 *  Problem: https://www.geeksforgeeks.org/find-duplicate-rows-binary-matrix/
 *  Find duplicate rows in a binary matrix
 *  Compile: gcc -o duplicateRows duplicateRows.c -g -Wall -fsanitize=address && ./duplicateRows   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

void printDuplicates(int mat[][7], int m, int n) {
    for(int i = 0; i < m-1; i++) {
        for(int j = i+1; j < m; j++) {
            char yes = 1;
            for(int k = 0; k < n; k++) {
                if(mat[i][k] != mat[j][k]) {
                    yes = 0;
                }
            }
            if(yes) printf("%d == %d\n", i, j);
        }
    }
}

#define ALPHABET_SIZE 2

struct Trie{
    char leaf;
    struct Trie* children[ALPHABET_SIZE];  
};

struct Trie* create_new_trie_node() {
    struct Trie* trie = (struct Trie*) malloc(sizeof(struct Trie));
    trie->leaf = 0;
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        trie->children[i] = NULL;
    }
    return(trie);
}


char insert(struct Trie** head, int arr[], int m) {
    if(*head == NULL) {
        *head = create_new_trie_node();
    }
    struct Trie* current = *head;
    for(int i = 0; i < m; i++) {    
        if(current->children[arr[i]] == NULL) {
            current->children[arr[i]] = create_new_trie_node();
        }
        current = current->children[arr[i]];
    }

    if(current->leaf) return(0);
    
    return(current->leaf = 1);
}

void printDuplicates1(int mat[][7], int m, int n) {
    struct Trie* head = NULL;
    for(int i = 0; i < m; i++) {
        if(insert(&head, mat[i], n) == 0) {
            printf("%dth row is duplicate\n", i);
        }
        else {
            printf("%dth row is not duplicate\n", i);
        }
    }
}



int main(int argc, char** argv){
    int m = 6;
    int n = 7;
    int mat[6][7] = {{1, 1, 0, 1, 0, 1, 0},
                     {0, 0, 1, 0, 0, 1, 0},
                     {1, 0, 1, 1, 0, 0, 0},
                     {1, 1, 0, 1, 0, 1, 0},
                     {0, 0, 1, 0, 0, 1, 0},
                     {0, 0, 1, 0, 0, 1, 0}};
    
    int c = sizeof(mat[0])/sizeof(mat[0][0]) ;
    int r = sizeof(mat)/sizeof(mat[0]);
    //printf("row=%d col=%d\n", r, c);
    //printDuplicates(mat, r, c);    
    printDuplicates1(mat, r, c);    
    
    return(0);
}
