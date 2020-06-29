/*
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/
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
    TreeNode* build(vector<int>& postorder, int& j, int left, int right, std::unordered_map<int, int>& map) {
        if(left >= right) { return nullptr; }
        
        int v = postorder[j--];
        
        TreeNode* root = new TreeNode(v);
        int i = map[v];
        root->right = build(postorder,j,i+1,right,map);        
        root->left = build(postorder,j,left,i,map);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int nnodes = inorder.size();
        std::unordered_map<int, int> map;
        int i = 0; for(int v: inorder) { map[v]=i++; }
        int j = nnodes-1;
        return build(postorder, j, 0, nnodes, map);
    }
};