/*
 *  https://leetcode.com/problems/increasing-order-search-tree/submissions/
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
    std::vector<int> tree_vec;
    void toVec(TreeNode* root) {
        if(root) {
            toVec(root->left);
            tree_vec.push_back(root->val);
            toVec(root->right);
        }
    }
    TreeNode* increasingBST1(TreeNode* root) {
        TreeNode* root1 = nullptr;
        TreeNode* curr = nullptr;
        toVec(root);
        for(auto v: tree_vec) {
            //printf("%d %d\n", v, curr == nullptr);
            TreeNode* node = new TreeNode(v);
            if(not root1) {
                root1 = node;
                curr = root1;
            }
            else {
                curr->right = node;
                curr = curr->right;
            }
        }
        return(root1);
    }
    
    TreeNode* curr = nullptr;
    void inorder(TreeNode* root) {
        if(root) {
            inorder(root->left);
            root->left = nullptr;
            curr->right = root;
            curr = root;
            inorder(root->right);
        }
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* root1 = new TreeNode(0);
        curr = root1;
        inorder(root);
        return(root1->right);
    }
    
    
};