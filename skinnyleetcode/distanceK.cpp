/*
 *	https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/
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
    std::stack<TreeNode*> stack;
    void dfs2(TreeNode* root, TreeNode* target, int K) {
        if(root == nullptr) return;
        
        if(root==target) {
            TreeNode* node = nullptr;
            printf("%d %d\n", K, stack.size());
            while(not stack.empty() and K) { node = stack.top(); stack.pop(); K--; }
            if(K==0 and node) { ans.push_back(node->val); }
            printf("%d %p %d\n", K, node, node->val);
            return;
        }
        
        stack.push(root);
        if(root->left and root->left != target) { dfs2(root->left, target, K), dfs2(root->right, target, K); }
        else { dfs2(root->right, target, K), dfs2(root->left, target, K); }
        
    }
    
        
    void dfs1(TreeNode* root, int K, int D) {
        if(root == nullptr) return;
        
        if(K==D) {ans.push_back(root->val); return; }
        
        dfs1(root->left, K, D+1), dfs1(root->right, K, D+1);
    }
    
    
    
    std::vector<int> ans;
    std::unordered_map<TreeNode*, TreeNode*> dads;
    std::unordered_set<TreeNode*> visited;
    void whose_my_dad(TreeNode* root) {
        if(root == nullptr) return;
        
        if(root->left) {
            dads[root->left]=root;
            whose_my_dad(root->left);
        }
        if(root->right) {
            dads[root->right]=root;
            whose_my_dad(root->right);
        }
    }
    
    void dfs(TreeNode* root, int K) {
        if(not visited.insert(root).second) return;
        
        if(K==0) { ans.push_back(root->val); return; }
        
        if(root->left) dfs(root->left, K-1);
        if(root->right) dfs(root->right, K-1);
        
        TreeNode* papa = dads[root];
        if(papa) dfs(papa, K-1);
        
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root == nullptr) return std::vector<int>();
        
        whose_my_dad(root);
        dfs(target, K);
        //dfs1(target, K, 0);
        
        //dfs(root, target, K);
        
        return ans;
    }
};