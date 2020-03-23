/*
 *  https://leetcode.com/problems/delete-leaves-with-a-given-value/submissions/
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
    void fixTree(TreeNode* root, TreeNode* parent, int direction, int target) {
        if(root) {
            //printf("1]%d\n", root->val);
            fixTree(root->left, root, 1, target);
            fixTree(root->right, root, 2, target);
            if((not root->left and not root->right) and (root->val == target)) {
                //printf("2]%d %d %p %p %d\n", root->val, direction, root->left, root->right, parent->val);
                if(direction == 1) {
                    delete parent->left;
                    parent->left = nullptr;
                    root = nullptr;
                }
                else if(direction == 2) {
                    delete parent->right;
                    parent->right = nullptr;
                    root = nullptr;
                }
                //else if(direction == 0) {
                  //  delete root;
                   // root = nullptr;
                //}
                //printf("3]%d %d %p %p %p\n", root->val, direction, root->left, root->right, parent);
            }
        }
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        fixTree(root, root, 0, target);
        if(root and not root->left and not root->right and root->val == target) {
            //delete root;
            root = nullptr;
        }
        return(root);
    }
};