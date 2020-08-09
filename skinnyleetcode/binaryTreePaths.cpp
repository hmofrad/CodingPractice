/*
 * https://leetcode.com/problems/binary-tree-paths/solution/
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
    void construct(TreeNode* root, std::string path, std::vector<std::string>& paths) {
        if(root == nullptr) { return; }
        path += to_string(root->val);
        if(root->left == nullptr and root->right == nullptr) { paths.push_back(path); return; }
        path += "->";
        construct(root->left, path, paths);
        construct(root->right, path, paths);
    }
    vector<string> binaryTreePaths0(TreeNode* root) {
        std::vector<std::string> paths;
        construct(root, std::string(), paths);
        return paths;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) { return std::vector<std::string>(); }
        std::vector<std::string> paths;
        std::stack<std::pair<TreeNode*, std::string>> stack;
        stack.push({root, ""});
        while(not stack.empty()) {
            TreeNode* node;
            std::string path;
            std::tie(node, path) = stack.top(); stack.pop();
            //std::pair<TreeNode*, std::string> pair = stack.top(); stack.pop();
            //TreeNode* node = pair.first;
            //std::string path = pair.second;
            path += to_string(node->val);
            if(node->left == nullptr and node->right == nullptr) { paths.push_back(path); }
            else { 
                path += "->";
                if(node->left)  { stack.push({node->left, path}); } 
                if(node->right) { stack.push({node->right, path}); }
            }
        }
        return paths;
    }
};