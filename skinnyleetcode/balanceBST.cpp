/*
 *  https://leetcode.com/problems/balance-a-binary-search-tree/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
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
    std::vector<int> vec;
    void tree2vec(TreeNode* root) {
        if(root) {
            tree2vec(root->left);
            vec.push_back(root->val);
            tree2vec(root->right);
        }
    }
    
    TreeNode* vec2bst(int start, int end) {
        if(start>end) return(NULL);
        
        int mid = (start+end)/2;
        
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = vec2bst(start, mid-1);
        root->right = vec2bst(mid+1, end);
        return(root);
            
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        tree2vec(root);
        return(vec2bst(0, vec.size()-1));
    }
};