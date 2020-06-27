/*
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mi = min(p->val, q->val);
        int ma = max(p->val, q->val);
        while(root->val < mi or root->val > ma) {
            if(root->val < mi) root = root->right;
            else root = root->left;
        }
        return root;
    }
    TreeNode* lowestCommonAncestor0(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = nullptr;
        if(p->val > root->val and q->val > root->val) { node = lowestCommonAncestor(root->right, p, q); }
        else if(p->val < root->val and q->val < root->val) { node = lowestCommonAncestor(root->left, p, q); }
        else { node = root; }
        return node;
    }
};