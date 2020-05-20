/*
 *	https://leetcode.com/problems/construct-string-from-binary-tree/submissions/	
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
    
    std::string tree2str(struct TreeNode* t) {
        if(t==nullptr) return std::string();
        if(t->left == nullptr and t->right == nullptr) return to_string(t->val);
        if(t->right==nullptr) return to_string(t->val) + "(" + tree2str(t->left) +")";
        return to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right)+")";
    }
    void traverse1(struct TreeNode* root, std::string& str) {
        if(root){

            str += to_string(root->val);
        if(root->left or (not root->left and root->right)) {
            str += "(";
            //printf("(");
        }
        traverse1(root->left, str);
        if(root->left or (not root->left and root->right)) {
            str += ")";
            //printf(")");
        }
        if(root->right) {
            str += "(";
            //printf("(");
        }
        traverse1(root->right, str);
        if(root->right) {
            str += ")";
            //printf(")");
        }
        }
    }


    std::string tree2str1(struct TreeNode* t) {
        std::string str;
        traverse1(t, str);
        printf("\n");
        return(str);     
    }
};