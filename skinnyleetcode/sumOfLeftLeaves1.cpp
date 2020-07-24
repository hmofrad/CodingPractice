/*
 * https://leetcode.com/problems/sum-of-left-leaves/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
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
    /*
    int sumOfLeftLeaves(TreeNode* root, bool flag=false) {
        if(root == nullptr) {
            return(0);
        }

        if((root->left == nullptr) && (root->right == nullptr) && flag) {
            return(root->val);
        }

        return(sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false));
    }
    */
    
    void traverse(TreeNode* root, int* sum) {
        if(root == nullptr) {
            return;
        }

        //printf("%d ", root->val);
        if(root->left and (root->left->left == nullptr and root->left->right == nullptr)) {
            //printf("%d\n", root->left->val);
            *sum += root->left->val;
        }
        traverse(root->left, sum);
        traverse(root->right, sum);
    }
    
    
    int sumOfLeftLeaves(TreeNode* root) {
        int s = 0;
        traverse(root, &s);
        return(s); 
    }
    
    void traverse1(TreeNode* root, TreeNode* parent, int& sum) {
        if(root == nullptr) { return; }
        
        if(root->left == nullptr and root->right == nullptr and parent and parent->left == root) { sum+=root->val; }
        
        traverse1(root->left, root, sum);
        traverse1(root->right, root, sum);
        
    }
    int sumOfLeftLeaves1(TreeNode* root) {
        if(root==nullptr) return 0;
        //if(root->left == nullptr and root->right == nullptr) return root->val;
        int sum = 0;
        traverse1(root, nullptr, sum);
        return sum;
    }
    
    
};