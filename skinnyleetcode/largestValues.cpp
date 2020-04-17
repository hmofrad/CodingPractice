/*
 *  https://leetcode.com/problems/find-largest-value-in-each-tree-row/submissions/
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
    void BFS1(TreeNode* root, std::vector<int>& values, int depth) {
        if(root == nullptr) return;
        
        if(values.size() < depth) values.push_back(root->val);
        
        BFS1(root->left, values, depth+1);
        BFS1(root->right, values, depth+1);
        
        if(root->val > values[depth-1]) values[depth-1] = root->val;
        
    }
    std::vector<int> BFS(TreeNode* root) {
        std::vector<int> values;
        if(root) {
            std::deque<TreeNode*> queue;
            queue.push_back(root);
            while(not queue.empty()) {
                int val = 0;
                int size = queue.size();
                int s = 0;
                 while (s < size) {
                     TreeNode* front = queue.front();
                     queue.pop_front();
                     if(front->left) queue.push_back(front->left);
                     if(front->right) queue.push_back(front->right);
                     val = (s==0) ? front->val : max(val, front->val);    
                    s++;
                 }
                values.push_back(val);
            }
        }
        return values;
    }
    vector<int> largestValues(TreeNode* root) {
        //return BFS(root);
        std::vector<int> values;
        BFS1(root, values, 1);
        return values;
    }
};