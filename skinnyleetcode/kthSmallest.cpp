    /*
 *  Problem: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 *  Compile & execute: g++ -o kthSmallest kthSmallest.cpp -std=c++11 && ./kthSmallest #-fsanitize=address 
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
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
#include <unordered_set>
#include <queue>
#include <cmath>
#include <stack>
//#include<bits/stdc++.h> 



struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(struct TreeNode* root) {
    if(not root) return;
    
    if(root->left) {
        traverse(root->left);
        //printf("%d\n", root->left->val);
    }
    printf("%d\n", root->val);
    if(root->right) {
        traverse(root->right);
        //printf("%d\n", root->right->val);
    }
}
/*
void traverse1(struct TreeNode* root, int k, int& i, int& v) {
    if(i == k) return;
    if(not root) return;
    
    
    if(root->left) {
        traverse1(root->left, k, i, v);
        //printf("%d\n", root->left->val);
    }
    i++;
    //printf("%d %d \n", root->val, i);
    if(i == k) {
        v = root->val;
        return;
    }
    
    if(root->right) {
        traverse1(root->right, k, i, v);
        //printf("%d\n", root->right->val);
    }
}

int kthSmallest(struct TreeNode* root, int k) {
    
    int i = 0;
    int kth = 0;
    traverse1(root, k, i, kth);
}
*/

int kthSmallest(struct TreeNode* root, int k) {
    int count = 0; 
    if(not root) return 0;
    std::stack<struct TreeNode*> stack1; 
    while(true) {
        
        if(root) {
            printf("%d\n", root->val);
            stack1.push(root);
            root = root->left;
        }
        else {
            if(stack1.empty()) {
                break;
            }
            root = stack1.top();
            stack1.pop();
            count++;
            if(count == k) {
                return(root->val);
            }
            printf("%d\n", root->val);
            root = root->right;
        }
    }
    return(0);    
}

int main(int argc, char **argv) {
    /*
    // root = [3,1,4,null,2]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);
    */
    //root = [5,3,6,2,4,null,null,1]
    struct TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(8);
    
    
    //traverse(root);
    int k = 7;
    printf("%d\n", kthSmallest(root, k));
    
    
    return(0);
}






