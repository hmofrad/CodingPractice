/*
 *  https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/submissions/
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
    int binToInt(std::vector<int> bits){
        int v = 0;
        int m = bits.size();
        for(int i = 0; i < m; i++) {
            v += bits[i] * pow(2, m-1-i);
        }
        return(v);
    }
    
    std::vector<std::vector<int>> pathes; 
    void traverse(TreeNode* root, std::vector<int> path) {
        if(root) {
            path.push_back(root->val);
            if(not root->left and not root->right) {
                pathes.push_back(path);
            }
            else { 
                traverse(root->left, path);
                traverse(root->right, path);
            }
        }
    }
    
    int sumRootToLeaf1(TreeNode* root) {
        std::vector<int> p;
        traverse(root, p);
        
        int s = 0;
        for(std::vector<int> path: pathes) {
            s += binToInt(path);
        }
        return(s);
    }
    int sum = 0;
    void traverse1(TreeNode* root, int num) {
        if(root) {
            if(not root->left and not root->right) {
                sum += num*2+root->val;
            }
            else { 
                traverse1(root->left, num*2+root->val);
                traverse1(root->right, num*2+root->val);
            }
        }
    }
    
    
    int sumRootToLeaf(TreeNode* root) {
        traverse1(root, 0);
        return(sum);
    }
    
};