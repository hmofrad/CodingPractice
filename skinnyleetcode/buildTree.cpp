/*
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/
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
    TreeNode* build(vector<int>& preorder, int& j, std::unordered_map<int, int>& map, int left, int right) {
        if(left == right) { return nullptr; }
        
        int v = preorder[j++];
        TreeNode* root = new TreeNode(v);
        int i = map[v];
        
        root->left = build(preorder, j, map, left, i);
        root->right = build(preorder, j, map, i+1, right);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int nnodes = preorder.size();
        std::unordered_map<int, int> map;
        int i = 0;
        for(int v: inorder) { map[v]=i++; }
        int j = 0;
        return build(preorder, j, map, 0, nnodes);
    }
};