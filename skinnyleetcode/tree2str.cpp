/*
 *  Problem: https://leetcode.com/problems/construct-string-from-binary-tree/
 *  Compile: g++ -o tree2str tree2str.cpp -std=c++11 -g -Wall -fsanitize=address && ./tree2str
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

void traverse1(struct TreeNode* root, std::string& str) {
    if(root){
        
        //printf("%d", root->val);
        str += std::to_string(root->val);
        if(root->left or (not root->left and root->right)) {
            str += "(";
            //printf("(");
        }
        traverse1(root->left, str);
        if(root->left or (not root->left and root->right)) {
            str += ")";
            //printf(")");
        }
        if(root->right) {
            str += "(";
            //printf("(");
        }
        traverse1(root->right, str);
        if(root->right) {
            str += ")";
            //printf(")");
        }
    }
}


std::string tree2str(struct TreeNode* t) {
    std::string str;
    traverse1(t, str);
    printf("\n");
    return(str);     
}

/*

      1
    /   \
   2     3
    \      
     4     
   

*/


int main(int argc, char **argv){
    struct TreeNode* root = new TreeNode(-1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(3);
    //root->right->right = new TreeNode(6);
    
    //traverse(root); printf("\n");
    
    std::string str = tree2str(root);
    printf("%s\n", str.c_str());
    
    
    delete(root->left->right);
    delete(root->left);
    
    //delete(root->right->right);
    delete(root->right);
    
    delete(root);
    
    
    return(0);
}