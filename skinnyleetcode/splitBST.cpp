/*
 *	https://leetcode.com/problems/split-bst/solution/
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
    void traverse(TreeNode* root) {
        if(root) {
            traverse(root->left);
            printf("%d ", root->val);
            traverse(root->right);
        }
    }
    
    vector<TreeNode*> split(TreeNode* root, int V) {
        if(root == nullptr) return std::vector<TreeNode*>({nullptr, nullptr});
        else if(root->val <= V) {
           std::vector<TreeNode*> bns = split(root->right, V);
           root->right=bns[0];
           bns[0]=root;
           return bns;
        }
        else {
            std::vector<TreeNode*> bns = split(root->left, V);   
            root->left=bns[1];
            bns[1]=root;
            return bns;
        }
    }
    
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        //traverse(root); printf("\n");
        return split(root, V);
        //return roots;
    }
};