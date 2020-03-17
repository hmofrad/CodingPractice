/*
 *  Problem: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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
    int sum(TreeNode* root) {
        int s = 0;
        if(root) {
            s += root->val;
            s += (sum(root->left) + sum(root->right));
            
        }
        return(s);
    }
    
    void bstToGreaterSumTree(TreeNode* root, int& sum) {
          if(root) {
              bstToGreaterSumTree(root->left, sum);
              //printf("%d %d >>", root->val, sum);
              int t = root->val;
              root->val =  sum;
              sum -= t;
              //printf("%d %d\n", root->val, sum);
              bstToGreaterSumTree(root->right, sum);
          }      
    }
    
    
    TreeNode* bstToGst(TreeNode* root) {
        int s = sum(root);
        //printf("SUM=%d\n", s);
        bstToGreaterSumTree(root, s);
        return(root);
    }
};