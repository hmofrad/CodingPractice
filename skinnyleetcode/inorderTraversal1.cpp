/*
 * https://leetcode.com/problems/binary-tree-inorder-traversal/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> vec;
        if(root == nullptr) return vec;
        std::stack<TreeNode*> stack;
        stack;
        while(root or not stack.empty()) {
            while(root) {
                stack.push(root);
                root=root->left;
            }
            root = stack.top(); stack.pop();
            vec.push_back(root->val);
            root=root->right;
        }
        return vec;
    }
    
    
    void inorder(TreeNode* root, std::vector<int>& vec) {
        if(root) {
            inorder(root->left, vec);
            vec.push_back(root->val);
            inorder(root->right, vec);
        }
    }
    vector<int> inorderTraversal1(TreeNode* root) {
        std::vector<int> vec;
        inorder(root, vec);
        return vec;
    }
};