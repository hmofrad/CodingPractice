/*
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/solution/
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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        if(root == nullptr) return ans;
        std::queue<TreeNode*> q;
        q.push(root);
        int i = 0;
        while(not q.empty()) {
            std::vector<int> t;
            int s = q.size();
            while(s) {
                TreeNode* front = q.front(); 
                q.pop();
                t.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                s--;
            }
            if(i%2) { std::reverse(t.begin(), t.end()); }
            ans.push_back(t);
            i++;
        }
        return ans;
    }
};