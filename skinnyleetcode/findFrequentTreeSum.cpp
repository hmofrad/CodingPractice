/*
 *  https://leetcode.com/problems/most-frequent-subtree-sum/submissions/
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
    std::unordered_map<int, int> sums;
    int getSum(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int sum = root->val + getSum(root->left) + getSum(root->right);
        sums[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        getSum(root);
        int most_frequent_key = 0;
        int most_frequent_value = 0;
        for(auto sum: sums) {
            if(sum.second > most_frequent_value) {
                most_frequent_key = sum.first;
                most_frequent_value = sum.second;
            }
        }
        
        std::vector<int> sums1;
        for(auto sum: sums) {
            if(sum.second == most_frequent_value) {
                sums1.push_back(sum.first);
            }
        }
        return sums1;
    }
};