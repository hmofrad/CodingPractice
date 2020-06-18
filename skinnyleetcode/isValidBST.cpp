/*
 * https://leetcode.com/problems/validate-binary-search-tree/submissions/
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
    bool traverse(TreeNode* root, TreeNode*& prev) {
        if(root == nullptr) return true;
        bool ret = true;
        ret &= traverse(root->left, prev);
        if(ret == false or (prev and prev->val>=root->val)) return false;
        prev = root;
        return traverse(root->right, prev);
        
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return traverse(root, prev);
    }
    
    bool validate(TreeNode* root, long mi, long ma) {
        if(root == nullptr) return true;
        
        if((long)root->val<=mi or (long)root->val>=ma) return false;
        
        return validate(root->left, mi, root->val) and validate(root->right, root->val, ma);
    }
    bool isValidBST1(TreeNode* root) {
        long mi = LONG_MIN;
        long ma = LONG_MAX;
        return validate(root, mi, ma);
    }
};