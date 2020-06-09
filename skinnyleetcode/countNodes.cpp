/*
 * https://leetcode.com/problems/count-complete-tree-nodes/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int get_height1(TreeNode* root, bool direction) {
        return root==nullptr ? 0 : direction ? get_height1(root->left, direction) + 1 : get_height1(root->right, direction) + 1;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int height_left = get_height1(root, true);
        int height_right = get_height1(root, false);
        
        return (height_left==height_right) ? (1<<height_left)-1 
                                           :  countNodes(root->left) + countNodes(root->right) + 1;
    }
    
    
    int get_height(TreeNode* root) {
        return root==nullptr ? -1 : get_height(root->left) + 1;
    }
    int countNodes2(TreeNode* root) {
        int h = get_height(root);
        
        
        
        return h<0 ? 0
                   : get_height(root->right) == h-1 ? (1<<h) + countNodes(root->right) 
                                                : (1<<h-1) + countNodes(root->left); 
                                                    
                                  
    }
    
    
    int traverse(TreeNode* root) {
        if(root == nullptr) return 0;
        return traverse(root->left) + traverse(root->right) + 1;
    }
    int countNodes1(TreeNode* root) {
        return traverse(root);
    }
};