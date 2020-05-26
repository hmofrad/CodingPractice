/*
 *	https://leetcode.com/problems/binary-tree-right-side-view/submissions/
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
    void dfs(TreeNode* root, int depth, std::vector<int>& righties) {
        if(root) {
            if(righties.size() < depth) righties.push_back(root->val);
            dfs(root->right, depth+1, righties);
            dfs(root->left, depth+1, righties);
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> righties;
        dfs(root, 1, righties);
        return righties;
    }
    
    vector<int> bfs(TreeNode* root) {
        vector<int> ans;
        if(root) {
            std::queue<TreeNode*> queue;
            queue.push(root);
            while(not queue.empty()) {
                int size = queue.size();
                while(size) {
                    TreeNode* front = queue.front(); queue.pop();
                    if(front->left) queue.push(front->left);
                    if(front->right) queue.push(front->right);
                    size--;
                    if(size==0) { ans.push_back(front->val); }
                }
            }
        }
        return ans;
    }
    vector<int> rightSideView1(TreeNode* root) {
        return bfs(root);
    }
};