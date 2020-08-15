/*
 * https://leetcode.com/problems/symmetric-tree/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
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
    bool isSymmetric1(TreeNode* root) {
        if(root == nullptr) { return true; }
        std::queue<TreeNode*> queue;
        queue.push(root);
        while(not queue.empty()) {
            int size = queue.size();
            std::vector<int> vec;
            for(int i = 0; i < size; i++) {
                TreeNode* front = queue.front(); queue.pop();
                if(front == nullptr) { vec.push_back(INT_MAX); continue; }
                else {
                    vec.push_back(front->val);
                    queue.push(front->left);
                    queue.push(front->right);
                }
            }
            for(int i = 0; i < size/2; i++) {
                if(vec[i] != vec[size-1-i]) { return false; }
            }
        }
        return true;
    }
    
    bool isSymmetric2(TreeNode* root) {
        if(root == nullptr) { return true; }
        std::queue<TreeNode*> queue;
        queue.push(root);
        queue.push(root);
        while(not queue.empty()) {
            TreeNode* t1 = queue.front(); queue.pop();
            TreeNode* t2 = queue.front(); queue.pop();
            if(t1 == nullptr and t2 == nullptr) { continue; }
            if(t1 == nullptr or t2 == nullptr) { return false; }
            if(t1->val != t2->val) { return false; }
            queue.push(t1->left);
            queue.push(t2->right);
            queue.push(t1->right);
            queue.push(t2->left);
        }
        return true;
    }
    
    bool validate(TreeNode* r1, TreeNode* r2) {
        if(r1==nullptr and r2==nullptr) { return true; }
        else if(r1== nullptr or r2 == nullptr) { return false; }
        return ((r1->val == r2->val) and validate(r1->left, r2->right) and validate(r1->right, r2->left));
        
    }
    bool isSymmetric(TreeNode* root) {
        return validate(root, root);
    }
    
    // Wrong 
    void validate0(TreeNode* root, std::vector<int>& vec) {
        if(root == nullptr) { return; }
        validate0(root->left, vec);
        vec.push_back(root->val);
        validate0(root->right, vec);
    }
    bool isSymmetric0(TreeNode* root) {
        std::vector<int> vec;
        validate0(root, vec);
        int size = vec.size();
        for(int i = 0; i < size/2; i++) {
            if(vec[i] != vec[size-1-i]) { return false; }
        }
        return true;
    }
};