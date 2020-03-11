/*
 *  Problem: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
 *  Compile: g++ -o getMinimumDifference getMinimumDifference.cpp -std=c++11 -g -Wall -fsanitize=address && ./getMinimumDifference
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <deque>
#include <limits.h>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void traverse(struct TreeNode* root) {
    if(root){
        traverse(root->left);
        printf("%d ", root->val);
        traverse(root->right);
    }
}

void bst2vec(struct TreeNode* root, std::vector<int>& vec) {
    if(root){
        bst2vec(root->left, vec);
        vec.push_back(root->val);
        bst2vec(root->right, vec);
    }
}



int getMinimumDifference(TreeNode* root) {
    
    std::vector<int> vec;
    bst2vec(root, vec);
    
    int diff = INT_MAX;
    for(uint32_t i = 1; i < vec.size(); i++) {
        int d = vec[i] - vec[i-1];
        d = (d < 0) ? -d : d;
        if(d < diff) diff = d;        
    }
    return(diff);    
}

/*

      4
    /   \
   1     5
    \     \ 
     2     6
   

*/


int main(int argc, char **argv){
    struct TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    traverse(root); printf("\n");
    
    int diff = getMinimumDifference(root);
    printf("[%d]\n", diff);
    
    
    delete(root->left->right);
    delete(root->left);
    
    delete(root->right->right);
    delete(root->right);
    
    delete(root);
    
    
    return(0);
}