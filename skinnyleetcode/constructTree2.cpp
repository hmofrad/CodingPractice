/*
 *  https://leetcode.com/problems/maximum-binary-tree-ii/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructTree(TreeNode* root, TreeNode* parent, int val) {
        if(root == nullptr) return nullptr;
        
        if(root->val < val) {
            
            TreeNode* node = new TreeNode(val);
            if(parent == nullptr) {
                node->left = root;
                return(node);
            }
            else {
                if(parent->left == node) parent->left = node;
                if(parent->right == node) parent->right = node;
            }
            
            node->left = constructTree(root->left, node, root->val);
            node->right = constructTree(root->right, node, root->val);
        }
        
        root->left = constructTree(root->left, root, val);
        root->right = constructTree(root->right, root, val);
        return(root);
        
    }
    
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(not root) return new TreeNode(val);
        
        if(root->val < val) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return(node);
        }
        else {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
    }
    
    
    TreeNode* insertIntoMaxTree1(TreeNode* root, int val) {
        return constructTree(root, nullptr, val);
        
    }
};