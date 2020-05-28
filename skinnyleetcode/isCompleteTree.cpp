/*
 *	https://leetcode.com/problems/check-completeness-of-a-binary-tree/
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
    
    bool isCompleteTree(TreeNode* root) {
        if(root == nullptr) return false;
        std::queue<TreeNode*> queue;
        queue.push(root);
        bool firstnull = false;
        while(not queue.empty()) {
            TreeNode* front = queue.front(); queue.pop();
            if(front) {
                if(firstnull) return false;
                queue.push(front->left);
                queue.push(front->right);
            }
            else{ firstnull = true; }
        }
        return true;
    }
    int get_depth(TreeNode* root) {
        if(not root) return 0;
        return max(get_depth(root->left), get_depth(root->right)) + 1;
    }
    
    bool isCompleteTree1(TreeNode* root) {
        if(root == nullptr) return false;
        
        int depth = get_depth(root);
        //printf("d=%d\n", depth);
        
        
        std::queue<TreeNode*> queue;
        queue.push(root);
        int d = 0;
        while(not queue.empty()) {
            int nnodes = 1 << d; d++;
            int size = queue.size();
            int s = 0;
            while(s < size) {
                TreeNode* front = queue.front(); queue.pop();
                if(not front->left and front->right) return false;
                if(front->left and not front->right and s+1<size) return false;
                if(front->left) queue.push(front->left);
                if(front->right) queue.push(front->right);
                s++;
            }
            //printf("%d %d %d\n", size, nnodes, queue.empty());
            if(not queue.empty() and d+2 < depth and size != nnodes) return false;
        }
        return true;
    }
};