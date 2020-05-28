/*
 *	https://leetcode.com/problems/cousins-in-binary-tree/
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
    bool cousin = false;
    int depth_so_far = -1;
    bool dfs(TreeNode* root, int depth, int x, int y) {
        if(root) {
            if(depth_so_far != -1 and depth > depth_so_far) return false;
            if(root->val == x or root->val == y) {
                depth_so_far = (depth_so_far==-1) ? depth : depth_so_far;
                return depth_so_far == depth;
            }
            
            bool left = dfs(root->left, depth+1, x, y);
            bool right = dfs(root->right, depth+1, x, y);
            
            if(left and right and depth_so_far != depth+1) cousin = true;
            return left or right;
        }
        return false;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, 0, x, y);
        return cousin;
    }
    bool isCousins1(TreeNode* root, int x, int y) {
       std::queue<std::pair<TreeNode*, TreeNode*>> queue;
        queue.push({root, nullptr});
        while(not queue.empty()) {
            int s = queue.size();
            std::unordered_map<int, int> map;
            while(s) {
                auto front = queue.front(); queue.pop();
                if(front.first->left) queue.push({front.first->left, front.first});
                if(front.first->right) queue.push({front.first->right, front.first});
                if((front.first->val == x or front.first->val == y) and front.second) map[front.first->val]=front.second->val;
                s--;
            }
            if(not map.empty()) {
                return map.count(x) and map.count(y) ? map[x]!=map[y] : false;
            }
        }
        return false;
    }
};