/*
 *  Problem: https://leetcode.com/problems/cousins-in-binary-tree/
 *  Compile: g++ -o isCousins isCousins.cpp -std=c++11 -g -Wall -fsanitize=address && ./isCousins
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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int depth(struct TreeNode* root, int x) {
    int d = 0;
    std::deque<struct TreeNode*> q;
    if(root) q.push_back(root);
    bool matched = false;
    while(!q.empty() and !matched) {
        int sz = q.size();
        int s = 0;
        d++;
        while(s != sz) {
            struct TreeNode* c = q.front();
            if(c->val == x) {
                matched = true;
                break;
            }
            if(c->left) {
                q.push_back(c->left);
            }
            if(c->right) {
                q.push_back(c->right);
            }
            q.pop_front();
            s++;
        }
    }
    return(d);
}

int parent(struct TreeNode* root, int x) {
    int p = -1;
    std::deque<struct TreeNode*> q;
    if(root) q.push_back(root);

    while(!q.empty()) {
        struct TreeNode* c = q.front();
        if(c->left and c->left->val == x) {
            p = c->val;
            break;
        }
        if(c->left) {
            q.push_back(c->left);
        }
        
        if(c->right and c->right->val == x) {
            p = c->val;
            break;
        }
        if(c->right) {
            q.push_back(c->right);
        }
        q.pop_front();
    }
    return(p);
}


void traverse(struct TreeNode* root) {
    if(root) {
        traverse(root->left);
        printf("%d ", root->val);
        traverse(root->right);
    }
}

bool isCousins(struct TreeNode* root, int x, int y) {
    printf("%d %d\n", x, y);
    
    int d_x = depth(root, x);
    int d_y = depth(root, y);
    
    printf("%d %d\n", d_x, d_y);
    
    int p_x = parent(root, x);
    int p_y = parent(root, y);
    
    printf("%d %d\n", p_x, p_y);
    
    return((d_x == d_y) and (p_x != p_y));    
}

/*
     1
    /   \
   2     3
    \     \ 
     4     5
*/

/*

      1
    /   \
   2     3
    \     \ 
     4     5
   

*/


int main(int argc, char **argv){
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);
    
    traverse(root); printf("\n");
    int d = depth(root, 5);
    printf("Depth=%d\n", d);
    
    
    int x = 5;
    int y = 4;
    bool is = isCousins(root, x, y);
    printf("isCousins(%d %d)=%d\n", x, y, is);
    
    delete(root->left->right);
    delete(root->left);
    
    delete(root->right->right);
    delete(root->right);
    
    delete(root);
    
    
    return(0);
}