/*
 *  Problem: isSymetric
 *  Compile & Execute: g++ -o isSymetric isSymetric.cpp -std=c++11 && ./isSymetric
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

// Inorder(left, root, right)
// Got to the Leftmose node and then traverse up

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
bool traverse2(TreeNode* root_p, TreeNode* root_q) {   
    if(((root_p == NULL) and (root_q != NULL)) or ((root_p != NULL) and (root_q == NULL)))
        return(false);
    
    if((root_p == NULL) and (root_q == NULL))
        return(true); 
    else {
        if(root_p->val != root_q->val)
            return(false);
    }        

    bool theSame = traverse2(root_p->left, root_q->left);
    
    if(theSame)
        theSame = traverse2(root_p->right, root_q->right);

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
    
    
    
    std::vector<int> path_p = inorderTraversal(p);
    std::vector<int> path_q = inorderTraversal(q);
    int m = path_p.size();
    for(int i = 0; i < m; i++) {
        if(path_p[i] != path_q[i]) {
            same = false;
            break;
        }
    }
    
    return(theSame);
}
*/

bool traverse2(TreeNode* p, TreeNode* q) {
    if(p and q) {
        bool same = traverse2(p->left, q->right);
        if(p->val != q->val)
            return(false);
        if(same)
            same = traverse2(p->right, q->left);
        return(same);
    }
    else {
        if(!p and !q)
            return(true);
        else
            return(false);
    }
}


void traverse1(TreeNode* root, std::vector<int> &path) {    
    if(root == NULL)
        return;       
    //move.push_back(0);
    traverse1(root->right, path);
    
    path.push_back(root->val);
    //move.push_back(1);
    traverse1(root->left, path);
    
}

std::vector<int> inorderTraversal1(TreeNode* root) {
    std::vector<int> path;
    traverse1(root, path);
    return(path);
}


void traverse(TreeNode* root, std::vector<int> &path) {    
    if(root == NULL)
        return;       
    //move.push_back(0);
    traverse(root->left, path);
    path.push_back(root->val);
    //move.push_back(1);
    traverse(root->right, path);
}

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> path;
    //std::vector<int> move;
    traverse(root, path);
    return(path);
}


bool isSymmetric(TreeNode* root) {
    bool symmetric = traverse2(root->left, root->right);
    
    /*
    std::vector<int> path_l = inorderTraversal(root->left);
    int m_l = path_l.size();
    for(int i = 0; i < m_l; i++) {
        printf("%d ", path_l[i]);
    }
    printf("\n");
    
    std::vector<int> path_r = inorderTraversal1(root->right);
    int m_r = path_r.size();
    for(int i = 0; i < m_r; i++) {
        printf("%d ", path_r[i]);
    }
    printf("\n");
    */
    
    return(symmetric);
}


int main(int argc, char** argv) {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(2);
    p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(4);
    p->right->left = new TreeNode(4);
    p->right->right = new TreeNode(3);
    
    printf("isSymmetric? %d\n", isSymmetric(p));
    return(0);
}