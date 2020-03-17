/*
 *  Problem: https://leetcode.com/problems/insert-into-a-binary-search-tree/solution/
 *  Compile: g++ -o insertIntoBST insertIntoBST.cpp -std=c++11 -g -Wall -fsanitize=address && ./insertIntoBST
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <deque>

struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode* root) {
    if(root) {
        traverse(root->left);
        printf("%d[%d %d] ", root->val, root->left != NULL, root->right != NULL);
        traverse(root->right);
    }
}

TreeNode* insertIntoBST1(TreeNode* root, int val) {
    //TreeNode* node = NULL;
    if(root) {
        if(val > root->val) {
            root->right = insertIntoBST1(root->right, val);
        }
        else {
            root->left = insertIntoBST1(root->left, val);
        }
    }
    else {
        root = new TreeNode(val);
    }
    
    return(root);
}

void bfs(TreeNode* root) {
    std::deque<TreeNode*> list;
    if(root) {
        list.push_back(root);
        while(!list.empty()) {
            int size = list.size();
            int s = 0;
            while(s < size) {
                auto l = list.front();
                printf("%d ", l->val);
                if(l->left) list.push_back(l->left);
                if(l->right) list.push_back(l->right);
                list.pop_front();
                s++;
            }
            printf("\n");
        }
    }
}

    void bstToVec(TreeNode* root, std::vector<int>& vec) {
        if(root) {
            bstToVec(root->left, vec);
            vec.push_back(root->val);
            bstToVec(root->right, vec);
        }
    }
    
    int max_elem(std::vector<int> vec, int left, int right) {
        int v = vec[left];
        int idx = left;
        for(int i = left+1; i <= right; i++) {
            if(vec[i] > v) {
                v = vec[i];
                idx = i;
            }
        }
        return(idx);
    }
    
    TreeNode* vecToBst(std::vector<int> vec, int left, int right) {
        if(left > right) return(NULL);
        
        int i = max_elem(vec, left, right);
        TreeNode* root = new TreeNode(vec[i]);
        if(left == right) return(root);
        
        root->left = vecToBst(vec, left, i-1);
        root->right = vecToBst(vec, i+1, right);
        
        return(root);
        
        /*
        TreeNode* root = NULL;
        if(left <= right) {
            int i = max_elem(vec, left, right);
            printf("%d\n", i);
            TreeNode* root = new TreeNode(vec[i]);
            if(left != right) {
                root->left = vecToBst(vec, left, i-1);
                root->right = vecToBst(vec, i+1, right);
            }
        }    
        return(root);
        */
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        std::vector<int> vec;
        bstToVec(root, vec);
        
        /*
        for(auto v: vec) {
            printf("%d ", v);
        }
        printf("\n");
        */
        vec.push_back(0);
        for(int i = vec.size()-2; i >= 0; i--) {
            if(vec[i] >= val) {
                vec[i+1] = vec[i];
            }
            else {
                vec[i+1] = val;
                break;
            }
            if(i == 0) vec[i] = val;
        }
        
        
        for(auto v: vec) {
            printf("%d ", v);
        }
        printf("\n");
        
        //return(NULL);
        return(vecToBst(vec, 0, vec.size()-1));
    }



/*
        8
       / \
      3   9
     / \
    1   5
*/

int main(int argc, char **argv){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(9);
    
    //traverse(root);printf("\n");
    bfs(root);
    TreeNode* root1 = insertIntoBST(root, 6);
    //traverse(root1);printf("\n");
    bfs(root1);
    
    return(0);
}