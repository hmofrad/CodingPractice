/*
 *  Problem: https://leetcode.com/problems/maximum-binary-tree/solution/
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
    TreeNode* insert(vector<int>& nums, int left, int right) {
        if(left > right) return(NULL);
        
        int max_val = nums[left];
        int max_idx = left;
        for(int i = left+1; i <= right; i++) {
            if(nums[i] > max_val) {
                max_val = nums[i];
                max_idx = i;
            }
        }
        
        if(left == right) return(new TreeNode(nums[max_idx]));
        
        TreeNode* root = new TreeNode(nums[max_idx]);
        root->left = insert(nums, left, max_idx-1);
        root->right = insert(nums, max_idx+1, right);
        return(root);
    }
    
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return(insert(nums, 0, nums.size()-1));
    }
};