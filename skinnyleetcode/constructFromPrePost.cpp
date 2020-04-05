/*
 *  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/submissions/
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.empty()) return nullptr;
        
        TreeNode* root = new TreeNode(pre[0]);
        int N = pre.size();
        if(N == 1) return(root);
        
        int L = 0;
        for(int i = 0; i < N; i++) {
            if(pre[1] == post[i]) {L = i+1; break;}
        }
        
        std::vector<int> pre_l;
        for(int i = 1; i < L+1; i++) pre_l.push_back(pre[i]);
        std::vector<int> post_l;
        for(int i = 0; i < L; i++) post_l.push_back(post[i]);
        root->left = constructFromPrePost(pre_l, post_l);
        
        std::vector<int> pre_r;
        for(int i = L+1; i < N; i++) pre_r.push_back(pre[i]);
        std::vector<int> post_r;
        for(int i = L; i < N-1; i++) post_r.push_back(post[i]);
        root->right = constructFromPrePost(pre_r, post_r);
        
        return root;
    }
};

// Inorder: left, root, right
// Preorder: root, left, right
// Postorder: left, right, root