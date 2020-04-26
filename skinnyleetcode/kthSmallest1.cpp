/*
 *  https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/
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
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> stack;
        stack.push(root);
        while(true) {
            while(root) {stack.push(root); root = root->left;}
            root = stack.top(); stack.pop();
            if(--k == 0) return root->val;
            root = root->right;
        }
        return -1;
    }
    
    
    void traverse11(TreeNode* root, std::vector<int>& vec) {
        if(root) {
            traverse11(root->left, vec);
            vec.push_back(root->val);
            traverse11(root->right, vec);
        }
    }
    int kthSmallest3(TreeNode* root, int k) {
        std::vector<int> vec;
        traverse11(root, vec);
        return vec[k-1];
    }
    
    
    void traverse(TreeNode* root, int k, int& k1, int& kthsmallest) {
        if(k==k1) return;
        if(root) {
            traverse(root->left, k, k1, kthsmallest);
            if(k==(++k1)) {kthsmallest=root->val; return;}
            traverse(root->right, k, k1, kthsmallest);
        }
        /*
        if(k == k1) return;
        if(root == nullptr) return;
        if(root->left) traverse(root->left, k, k1, kthsmallest);
        
        k1++;
        if(k == k1) {kthsmallest=root->val; return;}
        
        if(root->right) traverse(root->right, k, k1, kthsmallest);
        */
        /*
        
        */
    }
    int kthSmallest2(TreeNode* root, int k) {
        int k1 = 0;
        int kthsmallest = -1;
        traverse(root, k, k1, kthsmallest);
        return kthsmallest;
    }
    
    
    
    
    void traverse1(struct TreeNode* root, int k, int& i, int& v) {
    if(i == k) return;
    if(not root) return;
    
    
    if(root->left) {
        traverse1(root->left, k, i, v);
        //printf("%d\n", root->left->val);
    }
    i++;
    //printf("%d %d \n", root->val, i);
    if(i == k) {
        v = root->val;
        return;
    }
    
    if(root->right) {
        traverse1(root->right, k, i, v);
        //printf("%d\n", root->right->val);
    }
}
    
    
    int kthSmallest1(TreeNode* root, int k) {
    int i = 0;
    int kth = 0;
    traverse1(root, k, i, kth);
    
    return(kth);
    }
};