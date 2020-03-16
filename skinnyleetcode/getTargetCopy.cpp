/*
 *  Problem:https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
/*
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ret = NULL;
        if(original) {
            if(original == target) {
                ret = cloned;
                return ret;                
            }
            ret = getTargetCopy(original->left, cloned->left, target);
            if(ret) return(ret);
            ret = getTargetCopy(original->right, cloned->right, target);                
            if(ret) return(ret);
        }
        return ret;
    }
};