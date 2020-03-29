/*
 *  https://leetcode.com/problems/find-leaves-of-binary-tree/submissions/
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
    std::vector<std::vector<int>> pathes;
    std::vector<int> path;
    void delete_leaves(TreeNode* root, TreeNode* dad) {
        //if(root == nullptr and dad == nullptr) return;
        if(root) {
            if(not root->left and not root->right) {
                path.push_back(root->val);
                if(dad->left == root) dad->left = nullptr;
                else dad->right = nullptr;
                //delete(root);
                root = nullptr;
            }
            else {
                delete_leaves(root->left, root);
                delete_leaves(root->right, root);
            }
        }
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        int d = 0;
        while(root != nullptr) {
            if(root->left == nullptr and root->right == nullptr) {
                pathes.push_back({root->val});
                root = nullptr;
                break;
            }
            
            
            delete_leaves(root, root);
            pathes.push_back(path);
            path.clear();
        }
        
        /*            
        for(auto path: pathes) {
            for(auto p: path) {
                printf("%d ", p);
            }
            printf("\n");    
        }
        */

        return(pathes);
    }
};