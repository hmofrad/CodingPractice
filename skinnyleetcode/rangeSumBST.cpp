/*
 *  Problem: https://leetcode.com/problems/range-sum-of-bst/submissions/
 *  Compile: g++ -o getDecimalValue getDecimalValue.cpp -std=c++11 -g -Wall -fsanitize=address && ./getDecimalValue
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int s = 0;
        if(root) {
            if(root->val >= L and root->val <= R) s+= root->val;
            s += rangeSumBST(root->left, L, R);
            s += rangeSumBST(root->right, L, R);
        }
        return(s);
    }
};