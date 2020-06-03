/*
 *  https://leetcode.com/problems/binary-tree-maximum-path-sum/solution/
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
    /*
    std::map<TreeNode*, TreeNode*> parents;
    void populate_parents(TreeNode* root, TreeNode* parent) {
        if(root) {
            parents[root]=parent;
            populate_parents(root->left, root);
            populate_parents(root->right, root);
        }
    }
    std::unordered_set<TreeNode*> visited;
    */
    int max_sum = INT_MIN;
    int dfs(TreeNode* root) {
        if(root==nullptr) return 0;
        
        int left_gain = max(dfs(root->left), 0);
        int right_gain = max(dfs(root->right), 0);
        
        int gain = root->val + left_gain + right_gain;
        
        max_sum = max(max_sum, gain);
        
        return root->val + max(left_gain, right_gain);
    }

    int maxPathSum(TreeNode* root) {
        //root = new TreeNode(-3);
        //populate_parents(root, nullptr);
        //dfs(root);
        dfs(root);
        return max_sum;
    }
};