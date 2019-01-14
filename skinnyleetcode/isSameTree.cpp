/*
 *  Problem: isSameTree
 *  Compile: g++ -o isSameTree isSameTree.cpp -std=c++11 && ./isSameTree
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

bool traverse2(TreeNode* root_p, TreeNode* root_q) {   
    //printf("[%d/%p,%d/%p]\n", root_p->val, root_p, root_q->val, root_q); 
    if(((root_p == NULL) and (root_q != NULL)) or ((root_p != NULL) and (root_q == NULL)))
        return(false);
    
    if((root_p == NULL) and (root_q == NULL))
        return(true); 
    else {
        if(root_p->val != root_q->val)
            return(false);
    }        
        
        
    //else {
    //    return (false);
    //}
    //printf("[%d %p] [%d %p]\n", root_p->val, root_p->left, root_q->val, root_q->left);
    bool theSame = traverse2(root_p->left, root_q->left);
    //path.push_back(root->val);
    //printf("!!!!\n");
    if(theSame)
        theSame = traverse2(root_p->right, root_q->right);
    //else
    return(theSame);
}

bool inorderTraversal2(TreeNode* root_p, TreeNode* root_q) {
    bool theSame = traverse2(root_p, root_q);
    return(theSame);
}

void traverse(TreeNode* root, std::vector<int> &path) {    
    if(root == NULL)
        return;       
    traverse(root->left, path);
    path.push_back(root->val);
    //printf("%d\n", root->val);
    traverse(root->right, path);
}

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> path;
    traverse(root, path);
    return(path);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    bool theSame = traverse2(p, q);
    
    
    /*
    std::vector<int> path_p = inorderTraversal(p);
    std::vector<int> path_q = inorderTraversal(q);
    int m = path_p.size();
    for(int i = 0; i < m; i++) {
        if(path_p[i] != path_q[i]) {
            same = false;
            break;
        }
    }
    */
    return(theSame);
}

int main(int argc, char** argv) {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(1);
    //p->right->left = new TreeNode(3);
    
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(1);
    q->right = new TreeNode(2);
    //q->left->left = new TreeNode(3);
    
    printf("Same? %d\n", isSameTree(p, q));
    return(0);
}