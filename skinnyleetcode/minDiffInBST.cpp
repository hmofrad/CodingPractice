/*
 *	https://leetcode.com/problems/minimum-distance-between-bst-nodes/submissions/
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
    void traverse(TreeNode* root, int& prev, int& min_d) {
        if(root) {
            //printf("%d %d %d\n", root->val, prev, min_d);
            traverse(root->left, prev, min_d);
            if(prev != -1) min_d = min(min_d, abs(root->val-prev));
            prev=root->val;
            traverse(root->right, prev, min_d);
        }
    }
    int minDiffInBST(TreeNode* root) {
        int min_d = INT_MAX;
        int prev = -1;
        traverse(root, prev, min_d);
            return min_d; 
    }
    
    std::vector<int> vec;
    void tovec(TreeNode* root) {
        if(root) {
            tovec(root->left);
            vec.push_back(root->val);
            tovec(root->right);
        }
    }
    int minDiffInBST1(TreeNode* root) {
        tovec(root);
        int min_d = INT_MAX;
        int size = vec.size();
        for(int i = 1; i < size; i++) {
            int d = vec[i]-vec[i-1];
            if(d < min_d) min_d = d;
        }
        return min_d;
    }
};