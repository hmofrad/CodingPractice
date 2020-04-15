/*
 *  https://leetcode.com/problems/find-bottom-left-tree-value/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
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
    int BFS(TreeNode* root) {
        int value = -1;
        if(root) {
            std::deque<TreeNode*> queue;
            queue.push_back(root);
            while(not queue.empty()) {
                int size = queue.size();
                int s = 0;
                while(s < size) {
                    TreeNode* front = queue.front();
                    queue.pop_front();
                    
                    if(front->left) queue.push_back(front->left);
                    if(front->right) queue.push_back(front->right);
                    
                    if(s==0) {value = front->val;}
                    s++;
                }
            }
        }
        return value;
    }
    
    int max_depth;
    int get_depth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        return max(get_depth(root->left), get_depth(root->right))+1;
    }
    
    int DFS(TreeNode* root, int curr_depth) {
        if(root == nullptr) return -1;
        
        if(root->left == nullptr and root->right == nullptr and curr_depth == max_depth) {
            return root->val;
        }
        int leftMost = DFS(root->left, curr_depth+1);
        return  leftMost != -1 ? leftMost : DFS(root->right, curr_depth+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        max_depth = get_depth(root);
        printf("%d\n", max_depth);
        return DFS(root, 1);
        //return BFS(root);
    }
};