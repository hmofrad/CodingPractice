/*
 *  Problem: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/
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
    TreeNode* insert(std::vector<int> preorder) {
        TreeNode* root = NULL;
        TreeNode* node = NULL;
        for(int i = 0; i < preorder.size(); i++) {
            printf("%d %d\n", i, preorder[i] );
            node = new TreeNode(preorder[i]);
            if(root == NULL) {
                root = node;
            }
            else {
                TreeNode* cur = root;
                TreeNode* ptr = NULL;
                while(cur) {
                    ptr = cur;
                    if(node->val < cur->val) cur = cur->left;
                    else cur = cur->right;
                }
                
                if(node->val < ptr->val) {
                    ptr->left = node;
                }
                else {
                    ptr->right = node;
                }
            }
        }
        return(root);
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return(insert(preorder));
    }
};