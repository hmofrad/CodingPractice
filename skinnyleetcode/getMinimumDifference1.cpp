/*
 *	https://leetcode.com/problems/minimum-absolute-difference-in-bst/submissions/
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
    void traverse(TreeNode* root, int& val, int& min_diff) {
        if(root->left) traverse(root->left, val, min_diff);
            //printf("%d %d %d\n", val, root->val, (root->val-val));
        if(val>=0) min_diff = min(min_diff, (int)(root->val-val));
        //printf("%d %d\n", min_diff, val);
        val=root->val;
        if(root->right) traverse(root->right, val, min_diff);
    }
    
    void traverse1(TreeNode* root, int& val, int& min_diff) {
        if(root) {
            traverse1(root->left, val, min_diff);
            if(val>=0) min_diff = min(min_diff, (int)(root->val-val));
            val=root->val;
            traverse1(root->right, val, min_diff);
        }
    }
    
    int getMinimumDifference(TreeNode* root) {
        int min_diff = INT_MAX;
        int val = -1;
        traverse1(root, val, min_diff);
        return min_diff;
    }
    
    void bst2vec(struct TreeNode* root, std::vector<int>& vec) {
        if(root){
            bst2vec(root->left, vec);
            vec.push_back(root->val);
            bst2vec(root->right, vec);
        }
    }
    
    int getMinimumDifference1(TreeNode* root) {
        std::vector<int> vec;
        bst2vec(root, vec);

        int diff = INT_MAX;
        for(uint32_t i = 1; i < vec.size(); i++) {
            int d = vec[i] - vec[i-1];
            d = (d < 0) ? -d : d;
            if(d < diff) diff = d;        
        }
        return(diff);    
    }
};