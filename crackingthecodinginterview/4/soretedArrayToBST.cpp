/*
 *  Cracking the coding interview: Problem 4.3: Convert a sorted array into a bst with minimal height 
 *  Compile & run: g++ -o soretedArrayToBST soretedArrayToBST.cpp -g -Wall -std=c++11 -fsanitize=address  && ./soretedArrayToBST
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

struct Node{
    Node(){};
    Node (int value_) : value(value_), left(nullptr), right(nullptr) {};
    int value;
    Node* left;
    Node* right;
};

void insert(struct Node** bst, int val) {
    printf("insert %d\n", val);
    struct Node* root = *bst;
    if(not root) {
        root = new Node(val);
        *bst = root;
    }
    else {
        while(true) {
            if(val <= root->value) {
                if(root->left) {
                    root = root->left;
                }
                else {
                    root->left = new Node(val);
                    break;
                }
            }
            else if(val > root->value) { 
                if(root->right) {
                    root = root->right;
                }
                else {
                    root->right = new Node(val);
                    break;
                }
            }
        }
    }
}

void traverse(struct Node* bst) {
    if(bst) {
        traverse(bst->left);
        printf("%d ", bst->value);
        traverse(bst->right);
    }
}

int main(int argc, char** argv) {
    std::vector<int> array = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    struct Node* bst = nullptr;
    
    int mid = array.size()/2;
    insert(&bst, array[mid]);
    for(int32_t i = mid-1; i >= 0; i--) {
        insert(&bst, array[i]);
    }
    
    for(uint32_t i = mid+1; i < array.size(); i++) {
        insert(&bst, array[i]);
    }
  
    
    
    traverse(bst); printf("\n");
    
    
    
    
    
    return(0);
}