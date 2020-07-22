/*
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/
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
    void flatten(TreeNode* root) {
        if(root == nullptr) { return; }
        
        std::stack<TreeNode*> stack; stack.push(root);
        TreeNode* prev = nullptr; TreeNode* curr = nullptr;
        while(not stack.empty()) {
            curr = stack.top(); stack.pop();
            if(prev) {prev->right = curr; prev->left = nullptr; }
            if(curr->right) { stack.push(curr->right); }
            if(curr->left) { stack.push(curr->left); }
            prev = curr;
        }
        curr->right = nullptr; 
    }
    TreeNode* prev = nullptr;
    void flatten1(TreeNode* root) {
        if(root == nullptr) { return; }
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
    
    TreeNode* flatter(TreeNode* root) {
        if(root == nullptr) { return nullptr; }
        if(root->left == nullptr and root->right == nullptr) { return root; }
        TreeNode* left_tail = flatter(root->left);
        TreeNode* right_tail = flatter(root->right);
        if(left_tail) {
            left_tail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        return right_tail ? right_tail : left_tail;
    }

    void flatten0(TreeNode* root) {
        flatter(root);

    }
};