/*
 *	https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/submissions/
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
    int zigzag(TreeNode* root, bool direction) {
        if(not root) return 0;
        
        if(direction and root->right) return zigzag(root->right, false) + 1;
        
        if(not direction and root->left) return zigzag(root->left, true) + 1;
        
        return 0;
    }
    int longest_dist = 0;
    void traverse1(TreeNode* root) {
        if(root) {
            traverse1(root->left);
            longest_dist = max({longest_dist, zigzag(root, true), zigzag(root, false)});
            traverse1(root->right);
            //longest_dist = max(longest_dist, zigzag(root->right, true));
        }
    }
    
    
    int longestZigZag1(TreeNode* root) {
        traverse1(root);
        return longest_dist;
    }
    
    
    int max_dist = 0;
    void traverse(TreeNode* root, int dist, bool direction) {
        if(root) {
            if(direction) { traverse(root->left, dist+1, false); traverse(root->right, 1, true); }
            else { traverse(root->right, dist+1, true); traverse(root->left, 1, false); }
            max_dist = max(max_dist, dist);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        if(root == nullptr) return -1;
        traverse(root->right, 1, true);
        traverse(root->left, 1, false);
        return max_dist;
    }
    
};