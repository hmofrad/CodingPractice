/*
 *  https://leetcode.com/problems/distribute-coins-in-binary-tree/submissions/
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
    int carry = 0;
    int moves = 0;
    void inorder(TreeNode* root) {
        if(root) {
            inorder(root->left);
            
            if(root->val == 0) {
                if(carry) {
                    root->val = 1;
                    carry--;
                }
            }
            else if(root->val > 1) {
                carry += root->val - 1;
                root->val = 1;
                moves++;
            }         
            
            inorder(root->right);
            
            if(carry) {
                root->val += carry;
                carry = 0;
            }
        }
    }
    
    void inorder1(TreeNode* root) {
        if(root) {
            
            inorder1(root->right);
           // printf(">>%d\n", root->val);
            if(root->val == 0) {
                if(carry) {
                    root->val = 1;
                    carry--;
                }
            }
            else if(root->val > 1) {
                carry += root->val - 1;
                root->val = 1;
                moves++;
            }         
            
            inorder1(root->left);
            /*
            if(carry) {
                root->val += carry;
                carry = 0;
            }
            */
        }
    }
    
    void traverse(TreeNode* root) {
        if(root) {
            printf("%d ", root->val);
            traverse(root->left);
            traverse(root->right);
        }
    }
    int distributeCoins1(TreeNode* root) {
        //traverse(root);printf("\n");
        inorder(root);
        //traverse(root);printf("\n");
        inorder1(root);
        //traverse(root);printf("\n");
        return(moves);
    }
    
    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int L = dfs(root->left);
        int R = dfs(root->right);
        moves += abs(L) + abs(R);

        return root->val + L + R - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return(moves);
    }
    
};
