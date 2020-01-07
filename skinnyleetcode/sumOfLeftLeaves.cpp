/*
 *  Problem: https://leetcode.com/problems/sum-of-left-leaves/
 *  Compile: g++ -o sumOfLeftLeaves sumOfLeftLeaves.cpp -std=c++11  -g -Wall -fsanitize=address && ./sumOfLeftLeaves
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode* root, int* sum) {
    if(root == nullptr) {
        return;
    }
    
    //printf("%d ", root->val);
    if(root->left and (root->left->left == nullptr and root->left->right == nullptr)) {
        //printf("%d\n", root->left->val);
        *sum += root->left->val;
    }
    traverse(root->left, sum);
    traverse(root->right, sum);
}

int sumOfLeftLeaves(TreeNode* root) {
    int s = 0;
    traverse(root, &s);
    return(s);    
}


int sumOfLeftLeaves(TreeNode* root, bool flag=false) {
    if(root == nullptr) {
        return(0);
    }
    
    if((root->left == nullptr) && (root->right == nullptr) && flag) {
        return(root->val);
    }
    
    return(sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false));
}


int main(int argc, char **argv){
    struct TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    int s = sumOfLeftLeaves(root, false);
    printf("s=%d\n", s);
    //int sum = 0;
    //traverse(root, &sum);
    //printf(" %d\n", sum);
    
    delete(root->right->left);
    delete(root->right->right);
    delete(root->right);
    delete(root->left->left);
    delete(root->left);
    delete(root);
    return(0);
}






