/*
 *	https://leetcode.com/problems/binary-tree-preorder-traversal/solution/
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
    std::vector<int> dfs(TreeNode* root) {
        if(root == nullptr) return std::vector<int>();
        std::vector<int> vec;
        std::stack<TreeNode*> stack;
        stack.push(root);
        while(not stack.empty()) {
            TreeNode* rear = stack.top(); stack.pop();
            if(rear->right) stack.push(rear->right);
            if(rear->left) stack.push(rear->left);
            vec.push_back(rear->val);
        }
        return vec;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        return dfs(root);
    }
    std::vector<int> bfs(TreeNode* root) {
        if(root == nullptr) return std::vector<int>();
        std::vector<int> vec;
        std::queue<TreeNode*> queue;
        queue.push(root);
        //printf("%p\n", root);
        while(not queue.empty()) {
            TreeNode* front = queue.front(); queue.pop();
            if(front->left and front->right) {queue.push(front->left); queue.push(front->right);}
            else if(front->left) queue.push(front->left);
            else if(front->right) queue.push(front->right);
            vec.push_back(front->val);
        }
        return vec;
    }
    vector<int> preorderTraversal2(TreeNode* root) {
        return bfs(root);
    }
    void preorder(TreeNode* root, std::vector<int>& vec) {
        if(root) {
            vec.push_back(root->val);
            preorder(root->left, vec);
            preorder(root->right, vec);
        }
    }
    vector<int> preorderTraversal1(TreeNode* root) {
        std::vector<int> vec;
        preorder(root, vec);
        return vec;
    }
};