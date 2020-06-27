/*
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr or root == p or root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left == nullptr and right == nullptr) return nullptr;
        else if(left != nullptr and right != nullptr) return root;
        return left == nullptr ? right : left; 
        //if(left == nullptr) return right;
        //else if(right == nullptr) return left;
        //return root;
    }
    
    void populate(TreeNode* root, std::unordered_map<TreeNode*, TreeNode*>& map) {
        if(root==nullptr) return;
        if(root->left) map[root->left]=root;
        if(root->right) map[root->right]=root;
        populate(root->left, map);
        populate(root->right, map);
    }
    
    TreeNode* lowestCommonAncestor0(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        std::unordered_map<TreeNode*, TreeNode*> map; 
        map[root]=nullptr;
        populate(root, map);
        
        TreeNode* lca = nullptr;
        std::set<TreeNode*> set;
        while(p) { set.insert(p); p=map[p]; }
        while(set.count(q)==0) { set.insert(q); q=map[q]; }
        
        return q;
    }
};