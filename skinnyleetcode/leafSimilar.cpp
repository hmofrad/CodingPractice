/*
 *  https://leetcode.com/problems/leaf-similar-trees/solution/
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
    std::vector<int> leaves1;
    std::vector<int> leaves2;
    
    void extractLeaves(TreeNode* root, std::vector<int>& leaves) {
        if(root) {
            if(not root->left and not root->right) {
                leaves.push_back(root->val);
            }
            else {
                extractLeaves(root->left, leaves);
                extractLeaves(root->right, leaves);
            }
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        extractLeaves(root1, leaves1);
        extractLeaves(root2, leaves2);
        
        return(leaves1 == leaves2);
        
    }
};