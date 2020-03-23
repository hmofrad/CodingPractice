/*
 *  https://leetcode.com/problems/merge-two-binary-trees/solution/
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
    void merge(TreeNode* t1, TreeNode* t2, TreeNode* p, bool tf) {
        //printf("0.%p %p\n", t1, t2);
        if(t1 and t2) {
            //printf("1.%d %d\n", t1->val, t2->val);
            t1->val += t2->val;
            merge(t1->left, t2->left, t1, true);
            merge(t1->right, t2->right, t1, false);
        }
        else if(t2) {
            //printf("2.%d \n", t2->val);
            if(tf) p->left = t2;
            else p->right = t2;
        }
        
    }
    
    void traverse(TreeNode* root) {
        if(root){
            printf("%d [%d %d] ", root->val, root->left != nullptr, root->right != nullptr);
            traverse(root->left);
            traverse(root->right);
        }
    }
    
    TreeNode* mergeTrees1(TreeNode* t1, TreeNode* t2) {
        TreeNode* t = nullptr;
        if(t1 and t2) {
            merge(t1->left, t2->left, t1, true);
           // printf("---");
            merge(t1->right, t2->right, t1, false);
            t1->val+=t2->val;
            t = t1;
        }
        else if (t1) {
            t = t1;
        }
        else {
            t = t2;
        }
        //traverse(t); printf("\n");
        return(t);
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr) return t2;
        if(t2 == nullptr) return t1;
        
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
    
    
};