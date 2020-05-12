/*
 *	https://leetcode.com/problems/convert-bst-to-greater-tree/submissions/
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
    void convert(TreeNode* root, int& left_sum, int& right_sum) {
        if(root) {
            right_sum+=root->val;
            convert(root->left, left_sum, right_sum);
            left_sum+=root->val;
            convert(root->right, left_sum, right_sum);
            root->val+=left_sum+right_sum;
        }
    }
    TreeNode* convertBST1(TreeNode* root) {
        int left_sum = 0;
        int right_sum = 0;
        convert(root, left_sum, right_sum);
        return root;
    }
    int sum = 0;
    TreeNode* convertBST2(TreeNode* root) {
        if(root) {
            convertBST(root->right);
            sum+=root->val;
            root->val=sum;
            convertBST(root->left);
        }
        return root;
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;
        std::stack<TreeNode*> stack;
        //stack.push(root);
        while(not stack.empty() or node) {
            while(node) {stack.push(node); node = node->right;}
            node=stack.top(); stack.pop();
            sum+=node->val;
            node->val=sum;
            node=node->left;
            //printf("%d %d\n", sum, node->val);
        }
        return root;
    }
};
    