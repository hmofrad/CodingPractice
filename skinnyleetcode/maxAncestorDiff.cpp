/*
 *  https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
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
    //int maxdiff;
    int maxAncestorDiff(TreeNode* root, int mi = INT_MAX, int ma = INT_MIN, int maxdiff = 0) {
        if(root == nullptr) return maxdiff;
        
        mi = min(mi, root->val);
        ma = max(ma, root->val);
        
        maxdiff = max(abs(mi-ma), maxdiff);
        
        return( max(maxAncestorDiff(root->left, mi, ma, maxdiff), maxAncestorDiff(root->right, mi, ma, maxdiff)));
        

    }
};