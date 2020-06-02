/*
 *  https://leetcode.com/problems/binary-tree-coloring-game/submissions/
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
    void traverse(TreeNode* root, TreeNode* parent, std::unordered_map<TreeNode*, TreeNode*>& parents) {
        if(root) {
            parents[root]=parent;
            traverse(root->left, root, parents);
            traverse(root->right, root, parents);
        }
    }
    
    int inorder(TreeNode* root, int x) {
        if(root==nullptr or root->val == x) return 0;
        
        return inorder(root->left, x) + inorder(root->right, x) + 1;
    }
    int inorder(TreeNode* root) {
        if(root==nullptr) return 0;
        
        return inorder(root->left) + inorder(root->right) + 1;
    }
    
    void inorder1(TreeNode* root, int x, TreeNode** target) {
        if(root==nullptr) return;
        
        if(root->val == x) *target = root;
        
        inorder1(root->left, x, target), inorder1(root->right, x , target);
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        //std::unordered_map<TreeNode*, TreeNode*> parents(n);
        //traverse(root, nullptr, parents);
        
        //int nnodes_before_x = inorder(root, x);
        TreeNode* xt = nullptr; inorder1(root, x, &xt);
        //printf("%p\n", xt);
        int nnodes_after_x_left = inorder(xt->left);
        int nnodes_after_x_right = inorder(xt->right);
        int nnodes_after_x = nnodes_after_x_left + nnodes_after_x_right + 1;
        int nnodes_before_x = n-nnodes_after_x;
        
        return nnodes_before_x > nnodes_after_x ? true : max(nnodes_after_x_right, nnodes_after_x_left) > nnodes_before_x+min(nnodes_after_x_right, nnodes_after_x_left)+1 ? true : false ;
    }
};