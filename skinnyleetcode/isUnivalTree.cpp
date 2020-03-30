/*
 *  https://leetcode.com/problems/univalued-binary-tree/solution/
 *  g++ -o numUniqueEmails numUniqueEmails.cpp && ./numUniqueEmails
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
    bool isUnivalTree1(TreeNode* root, int value) {
        if(not root) return true;

        return((root->val == value) and (isUnivalTree1(root->left, value) == true) and (isUnivalTree1(root->right, value) == true));

    }
    bool isUnivalTree(TreeNode* root) {
        return(root ? isUnivalTree1(root, root->val) : false);
    }
};