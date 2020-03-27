/*
 *  https://leetcode.com/problems/search-in-a-binary-search-tree/solution/
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
        TreeNode* root1 = nullptr;
    void search(TreeNode* root, int val) {
        if(root) {
            search(root->left, val);
            if(root->val == val) {
                root1=root;
                return;
            }
            search(root->right, val);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr or root->val == val) return(root);
        
        return((val < root->val) ? searchBST(root->left, val) : searchBST(root->right, val));
        
        //search(root, val);
        //return(root1);
    }
};