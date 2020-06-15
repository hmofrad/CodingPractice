/*
 * https://leetcode.com/problems/diameter-of-binary-tree/submissions/
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
    int mx = 0;
    int traverse(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = traverse(root->left);
        int right = traverse(root->right);
        mx = max(mx, left+right);
        return max(left, right) +1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return mx;
    }
};