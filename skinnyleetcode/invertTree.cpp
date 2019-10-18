    /*
 *  Problem: https://leetcode.com/problems/invert-binary-tree/
 *  Compile: g++ -o invertTree invertTree.cpp -std=c++11 && ./invertTree
 *  Execute: ./invertTree
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


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



void traverseTree(TreeNode* root, std::queue<TreeNode*>& qu) {
    if(not root) return;
    printf("%d ", root->val);
    
    
    if(root->left) {
        qu.push(root->left);
    }
    if(root->right) {
        qu.push(root->right);
    }
    
    while(!qu.empty()) {
        TreeNode* leaf = qu.front();
        qu.pop();
        traverseTree(leaf, qu);
    }
}

/*

void traverseTree1(TreeNode* root, TreeNode* rooti, std::deque<TreeNode*>& dqu, std::vector<bool>& dir) {
    if(not root) return;
    printf("%d ", root->val);
    
    
    
    
    //if(root->left) {
        dqu.push_back(root->right);
        dir.push_back(0);
    //}
    //if(root->right) {
        dqu.push_back(root->left);
        dir.push_back(1);
    //}
    

    
    while(!dqu.empty()) {
        TreeNode* leaf = dqu.back();
        bool direction = dir.back();
        printf("%d %d\n", leaf->val, direction);
        if(direction) {
            rooti->right = new TreeNode(leaf->val);
            rooti = rooti->right;
            //printf("right\n ");
        }
        else {
            rooti->left = new TreeNode(leaf->val);
            rooti = rooti->left;
            
        }
        dqu.pop_back();
        dir.pop_back();
        traverseTree1(leaf, rooti, dqu, dir);
    }
}
    
    
    
    TreeNode* rooti = new TreeNode(root->val);    
    std::deque<TreeNode*> dqu;
    std::vector<bool> dir;
    //std::vector<TreeNode*> vec;
    //std::queue<TreeNode*> vec;
    traverseTree1(root, rooti, dqu, dir);
    return rooti;
    

*/
/*
TreeNode*  invertTree(TreeNode* root) {
    
    if(not root) return root;
    
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    TreeNode* n1 = invertTree(root->left);
    TreeNode* n2 = invertTree(root->right);
    return root;

    
}
*/
/*
TreeNode*  invertTree(TreeNode* root) {
    if(not root) return root;
    
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        TreeNode* temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;
        
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return(root);
}
*/



TreeNode*  invertTree(TreeNode* root) {
    if(not root) return root;
    
    //std::queue<TreeNode*> q;
    /*
    if(root->right) {
        q.push(root->right);
    }
    if(root->left) {
        q.push(root->left);
    }
    */
    std::swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    /*
    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        invertTree(curr);
    }
    */
    return(root);
}



int main(int argc, char **argv){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    std::queue<TreeNode*> qu;
    traverseTree(root, qu);
    printf("\n");
    
    TreeNode* root1 = invertTree(root);
    printf("\n");
    std::queue<TreeNode*> qu1;
    traverseTree(root1, qu1);
    printf("\n");
    
    return(0);
}