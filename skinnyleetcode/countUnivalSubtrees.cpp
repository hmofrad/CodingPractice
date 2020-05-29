/*
 *	https://leetcode.com/problems/count-univalue-subtrees/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
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
    int count = 0;
    bool uniValue(TreeNode* root, int prev) {
        if(root == nullptr)  {return true;}
      
        if(uniValue(root->left, root->val) == false | uniValue(root->right, root->val) == false) return false;
        count++;
        return root->val == prev;
    }
    int countUnivalSubtrees(TreeNode* root) {
        if(root == nullptr) return 0;
        //root->left->val=5;
        uniValue(root, 0);
        return count;
    }
};