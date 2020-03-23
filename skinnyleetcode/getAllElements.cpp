/*
 *  https://leetcode.com/problems/all-elements-in-two-binary-search-trees/submissions/
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
    
    void bst2vec(TreeNode* root, std::vector<int>& vec) {
        if(root) {
            bst2vec(root->left, vec);
            vec.push_back(root->val);
            bst2vec(root->right, vec);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::vector<int> vec1;
        bst2vec(root1, vec1);
        std::vector<int> vec2;
        bst2vec(root2, vec2);
        int i1= 0;
        int i2 = 0;
        std::vector<int> out;
        while(i1 < vec1.size() and i2 < vec2.size()) {
            if(vec1[i1] == vec2[i2]) {
                out.push_back(vec1[i1]);
                i1++;
                out.push_back(vec2[i2]);
                i2++;
            }
            else if (vec1[i1] < vec2[i2]) {
                out.push_back(vec1[i1]);
                i1++;
            }
            else {
                out.push_back(vec2[i2]);
                i2++;
            }
        }
        
        while(i1 < vec1.size()) {
            out.push_back(vec1[i1]);
            i1++;
        }
        
        while(i2 < vec2.size()) {
            out.push_back(vec2[i2]);
            i2++;
        }
        
        return(out);
    }
};