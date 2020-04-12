/*
 *  https://leetcode.com/problems/average-of-levels-in-binary-tree/solution/
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
    std::vector<double> bfs(TreeNode* root) {
        std::vector<double> avgs;
        if(root) {
            std::deque<TreeNode*> queue;
            queue.push_back(root);
            while(not queue.empty()) {
                double sum = 0;
                int size = queue.size();
                int sz = 0;
                while(sz < size) {
                    TreeNode* node = queue.front();
                    queue.pop_front();
                    if(node->left) queue.push_back(node->left);
                    if(node->right) queue.push_back(node->right);
                    sum += node->val;
                    sz++;
                }
                avgs.push_back((double)sum/size);
            }
        }
        
        return(avgs);

    }
    vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> avgs = bfs(root);
        return avgs;
    }
};