/*
 *  https://leetcode.com/problems/two-sum-bsts/submissions/
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
    std::unordered_map<int, bool> my_map;
    void toMap(TreeNode* root, int target) {
        if(root) {
            toMap(root->left, target);
            my_map[target-root->val] = true;
            toMap(root->right, target);
        }
    }
    
    bool fromMap(TreeNode* root) {
        if(not root) return false;
        
        if(my_map.find(root->val) != my_map.end()) return true;
        else return(fromMap(root->left) or fromMap(root->right));
    } 
    
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        toMap(root1, target);
        return fromMap(root2);
    }
    
    
    void toVec(TreeNode* root, std::vector<int>& vec) {
        if(root) {
            toVec(root->left, vec);
            vec.push_back(root->val);
            toVec(root->right, vec);
        }
    }
    bool twoSumBSTs1(TreeNode* root1, TreeNode* root2, int target) {
        std::vector<int> arr1;
        toVec(root1, arr1);
        std::vector<int> arr2;
        toVec(root2, arr2);
        
        bool ret = false;
        int m1 = arr1.size();
        int m2 = arr2.size();
        for(int i = 0; i < m1; i++) {
            for(int j = 0; j < m2; j++) {
                if(arr1[i] + arr2[j] == target) {ret = true; break;}
                else if(arr1[i] + arr2[j] > target) break;
            }
        }
        
        return(ret);
    }
};