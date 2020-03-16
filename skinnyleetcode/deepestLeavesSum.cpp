/*
 *  Problem: https://leetcode.com/problems/deepest-leaves-sum/submissions/
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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
       if(root) {
           std::deque<TreeNode*> list;
           list.push_back(root);
           while(not list.empty()) {
               int size = list.size();
               int s = 0;
               sum = 0;
               while(s < size) {
                   auto& t = list.front();
                   if(t->left)
                        list.push_back(t->left);
                   if(t->right)
                        list.push_back(t->right);
                   sum += t->val;
                   list.pop_front();
                   s++;
               }
           }
       }
        return(sum);
    }
};