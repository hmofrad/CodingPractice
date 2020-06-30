/*
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/
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
    int minDepth(TreeNode* root) {
        if(root == nullptr) { return 0; }
        
        if(root->left == nullptr and root->right == nullptr) { return 1; }
        
        int min_depth = INT_MAX;
        if(root->left) { min_depth = min(min_depth, minDepth(root->left)); }
        if(root->right) { min_depth = min(min_depth, minDepth(root->right)); }
        
        return min_depth+1;
    }
    
    
    void traverse(TreeNode* root, int depth, int& min_depth) {
        
        if(root == nullptr) {
            return;
        }
        //printf("%d\n", root->val);
        depth+=1;
        if(root->left) { traverse(root->left, depth, min_depth); }
        
        if(root->right) { traverse(root->right, depth, min_depth); }
        
        if(root->left == nullptr and root->right == nullptr) { min_depth = min(depth, min_depth); }
        
    }
    int minDepth0(TreeNode* root) {
        int d = INT_MAX;
        traverse(root, 0, d);
        return d == INT_MAX ? 0 : d;
    }
};