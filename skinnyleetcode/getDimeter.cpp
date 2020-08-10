/*
 * https://leetcode.com/problems/diameter-of-binary-tree/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int diameter = 0;
    int getDimeter(TreeNode* root, int d) {
        if(root == nullptr) { return 0; }
        int l = 0, r = 0;
        if(root->left) { l = getDimeter(root->left, d) + 1; }
        if(root->right) { r = getDimeter(root->right, d) + 1; }
        diameter = max(diameter, l+r);
        return max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        getDimeter(root, d);
        return diameter;
    }
};

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
class Solution0 {
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