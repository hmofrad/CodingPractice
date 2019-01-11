/*
 *  Problem: inorderTraversal
 *  Compile: g++ -o inorderTraversal inorderTraversal.cpp -std=c++11 && ./inorderTraversal
 *  Execute: ./merge2
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <string.h>

// Inorder(left, root, right)
// Got to the Leftmose node and then traverse up

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode* root, std::vector<int> &path) {    
    if(root == NULL)
        return;       
    traverse(root->left, path);
    path.push_back(root->val);
    printf("%d\n", root->val);
    traverse(root->right, path);
}

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> path;
    traverse(root, path);
    return(path);
}


int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    TreeNode* root1 = root;
    std::vector<int> path = inorderTraversal(root1);
    for(int i: path)
        printf("%d ", i);
    printf("\n");
    
    
    return(0);
}