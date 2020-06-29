/*
 * https://leetcode.com/problems/same-tree/submissions/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr and q==nullptr) return true;
        if((p and not q) or (not p and q)) return false;
        return (p->val == q->val) & 
               (isSameTree(p->left, q->left)) &                
               (isSameTree(p->right, q->right));
    }
    
    bool isSameTree0(TreeNode* p, TreeNode* q) {
       if((p and not q) or not p and q) return false;
        if(p and q) {
            if(p->val != q->val) return false;
            return isSameTree(p->left, q->left) and isSameTree(p->right, q->right); 
        }
        return true;
    }
};