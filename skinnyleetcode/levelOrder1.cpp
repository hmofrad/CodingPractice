/*
 *	https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    std::vector<std::vector<int>> tree;
    void recur(TreeNode* root, int level) {
        if(tree.size() == level) tree.push_back(std::vector<int>());
        tree[level].push_back(root->val);
        if(root->left) recur(root->left, level+1); 
        if(root->right) recur(root->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root != nullptr)  { recur(root, 0); }
        return tree;
    }
    
    vector<vector<int>> bfs(TreeNode* root) {
        std::vector<std::vector<int>> tree;
        if(root) {
            std::queue<TreeNode*> queue; queue.push(root);
            while(not queue.empty()) {
                std::vector<int> temp;
                int size = queue.size();
                while(size) {
                    TreeNode* front = queue.front(); queue.pop(); temp.push_back(front->val);
                    if(front->left) queue.push(front->left);
                    if(front->right) queue.push(front->right);
                    size--;
                }
                tree.push_back(temp);
            }
        }
        return tree;
    }
    vector<vector<int>> levelOrder1(TreeNode* root) {
        return bfs(root);
    }
};