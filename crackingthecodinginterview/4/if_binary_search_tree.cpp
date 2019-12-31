/*
 *  Cracking the coding interview: Problem 4.4: Check if a binary tree is a binary search tree
 *  Compile & run: g++ -o if_binary_search_tree if_binary_search_tree.cpp -g -Wall -std=c++11 -fsanitize=address  && ./if_binary_search_tree
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>

struct Node{
    Node(){};
    Node (int value_) : value(value_), left(nullptr), right(nullptr) {};
    int value;
    Node* left;
    Node* right;
};

struct ListNode{
    ListNode(){};
    ListNode (int value_) : value(value_), next(nullptr) {};
    int value;
    ListNode* next;
};

void traverse(struct Node* bst) {
    if(bst) {
        traverse(bst->left);
        printf("%d ", bst->value);
        traverse(bst->right);
    }
}


void check(struct Node* bst, std::vector<int>& values) {
    if(bst) {
        check(bst->left, values);
        values.push_back(bst->value);
        check(bst->right, values);
    }
}


/*
           8
    3            10
1       6              14
      4   7      13
*/

int main(int argc, char** argv) {
    std::vector<int> array = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    struct Node* bst = new Node(8);
    bst->left = new Node(3);
    bst->left->left = new Node(1);
    bst->left->right = new Node(6);
    bst->left->right->left = new Node(4);
    bst->left->right->right = new Node(7); 
   
    bst->right = new Node(10);
    bst->right->right = new Node(14);
    bst->right->right->left = new Node(13);
    
   
    traverse(bst); printf("\n");
    
    std::vector<int> values;
    check(bst, values);
    for(auto v: values) {
        printf("%d ", v);
    }
    printf("\n");
    for(uint32_t i = 0; i < values.size()-1; i++) {
        if(values[i] > values[i+1]){
            printf("Not a bst\n");
            break;
        }
    }
    
    
    delete bst->left->right->right; 
    delete bst->left->right->left;
    delete bst->left->right;
    delete bst->left->left;
    delete bst->left;
    
    delete bst->right->right->left;
    delete bst->right->right;
    delete bst->right;
    delete bst;
    
    return(0);
}