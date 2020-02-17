/*
 *  Problem: https://www.geeksforgeeks.org/longest-common-substring-dp-29/
 *  Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
 *  Input : X = “GeeksforGeeks”, y = “GeeksQuiz”; Output : 5
 *  Compile: gcc -o longestSubstr longestSubstr.c -g -Wall -fsanitize=address && ./longestSubstr   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void find(char str1[], char str2[]) {
    int m = strlen(str1);
    int n = strlen(str2);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int k1 = i;
            int k2 = j;
            while((k1 < m) && (k2 < n)) {
                if(str1[k1] == str2[k2]) {
                    k1++;
                    k2++;
                }
                else {
                    break;
                }
            }
            if(k1-i) printf("i=%d j=%d len=%d\n", i, j, k1-i);
        }
    }
    
}

#define ALPHA_SIZE 26
struct Trie{
    char leaf;
    struct Trie* children[ALPHA_SIZE];
};

struct Trie* allocate() {
    struct Trie* node = (struct Trie*) malloc(sizeof(struct Trie));
    node->leaf = 0;
    for(int i = 0; i < ALPHA_SIZE; i++) {
        node->children[i] = NULL;
    }
    return(node);
}

void deallocate(struct Trie* node) {
    if(node) free(node);
}

void insert(struct Trie** root, int index) {
    if(*root == NULL) {
        *root = allocate();
        (*root)->children[index] = allocate();
        (*root)->children[index]->leaf = 1;
    }
    else {
        struct Trie* curr = *root;
        while(curr->leaf == 0) {
            int i = 0;
            for(i = 0; i < ALPHA_SIZE; i++) {
                if(curr->children[i]) {
                    break;
                }
            }
            curr = curr->children[i];
        }
        curr->leaf = 0;
        curr->children[index] = allocate();
        curr->children[index]->leaf = 1;
    }
}

struct Trie* build_trie(char str[]) {
    struct Trie* root = NULL;
    int m = strlen(str);
    for(int i = 0; i < m; i++) {
        insert(&root, str[i]-'A');
    }
    return(root);
}

void traverse_trie(struct Trie* root) {
    while(1) {
        int i = 0;
        for(i = 0; i < ALPHA_SIZE; i++) {
            if(root->children[i]) {
                printf("%c ", i+'A');
                break;
            }
        }
        if(root->children[i]->leaf == 0) {
            root = root->children[i];
        }
        else {
            break;
        }
    }
    printf("\n");
}

/*
void search1(char str[], int index, struct Trie* root) {
    int found = 0;

    return(found);
}

void search(char str[], struct Trie* root) {
    int m = strlen(str);
    for(int i = 0; i < m; i++) {
        int l = 0;
        if((l = search1(str, i, root)) != 0) {
            printf("str[%d]=%c --> %d\n", i, str[i], l);
        }
    }
}
*/

int main(int argc, char** argv){
    //char X[] = "GeekforGeeks";
    //char Y[] = "GeeksQuiz";
    char X[] = "GEEKFORGEEKS";
    char Y[] = "QUIZEGEEKSWEX";
    find(X, Y);
    
    struct Trie* root = build_trie(X);
    traverse_trie(root);
    //search(str1, root);
    return(0);
}
