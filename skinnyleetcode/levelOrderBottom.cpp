/*
 *  Problem: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 *  Compile: g++ -o levelOrderBottom levelOrderBottom.cpp -std=c++11 -g -Wall -fsanitize=address && ./levelOrderBottom
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(std::vector<int> nums) {
    for(auto n: nums) {
        printf("%d ", n);
    }
    printf("\n");
}

void traverse(struct TreeNode* root) {
    if(root) {
        traverse(root->left);
        printf("%d ", root->val);
        traverse(root->right);
    }
}

std::vector<std::vector<int>> bfs1(struct TreeNode* root) {
    std::vector<std::vector<int>> vec;
    std::deque<struct TreeNode*> q;
    if(root) {
        q.push_back(root);
        while(!q.empty()) {
            std::vector<int> t;
            int sz = q.size();
            int s = 0;
            while(s < sz) {
                auto& f = q.front();
                if(f->left) {
                    q.push_back(f->left);
                }
                if(f->right) {
                    q.push_back(f->right);
                }
                t.push_back(f->val);
                q.pop_front();
                s++;
            }
            vec.push_back(t);
        }
    }


    return(vec);
}

void bfs2(struct TreeNode* root, std::vector<std::vector<int>>& vec, uint32_t d) {
    if(root) {
        //printf("%d ", root->val);
        if(d >= vec.size()) {
            vec.push_back(std::vector<int>());
        }
        vec[d].push_back(root->val);
        bfs2(root->left, vec, d+1);
        bfs2(root->right, vec, d+1);
    }
}

std::vector<std::vector<int>> levelOrderBottom(struct TreeNode* root) {
    //std::vector<std::vector<int>> vec = bfs1(root);
    
    std::vector<std::vector<int>> vec;
    bfs2(root, vec, 0);
    
    for(uint32_t i = 0; i < vec.size()/2; i++) {
        std::swap(vec[i], vec[vec.size()-i-1]);
    }
    
   for(auto v: vec) {
        for(auto w: v) {
            printf("%d ", w);
        }
        printf("\n");
    }
   
    return(vec);    
}



/*
    3
   / \
  9  20
    /  \
   15   7
   
*/


int main(int argc, char** argv){
    
    struct TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    //traverse(root); printf("\n");
    
    std::vector<std::vector<int>> out = levelOrderBottom(root);
    
    
    
    delete(root->right->right);
    delete(root->right->left);
    delete(root->right);
    delete(root->left);
    delete(root);
    
    
    return(0);
}