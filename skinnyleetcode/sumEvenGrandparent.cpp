/*
 *  Problem: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/submissions/
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
    int getHeight(TreeNode* root) {
        if(root) {
            return(1+max(getHeight(root->left), getHeight(root->right)));
        }
        else {
            return(0);
        }
    }
    
    int whereIsMyGrandpa(TreeNode* root, int my_dad, int my_pa) {
        int s = 0;
        if(root) {
            if((my_dad == -1) and (my_pa == -1)) {
                my_dad = root->val;
            }
            else if(my_pa == -1) {
                my_pa = my_dad;
                my_dad = root->val;
            }
            else {
                if(not (my_pa%2)) {
                    s += root->val;
                }
                my_pa = my_dad;
                my_dad = root->val;
            }
            s+=whereIsMyGrandpa(root->left, my_dad, my_pa);
            s+=whereIsMyGrandpa(root->right, my_dad, my_pa);
        }
        return(s);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        //printf("Height = %d\n", getHeight(root));
        int s = whereIsMyGrandpa(root, -1, -1);
        return(s);
    }
};