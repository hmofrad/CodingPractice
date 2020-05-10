/*
 *	https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
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
    bool find(TreeNode* root, int k, std::unordered_set<int>& set) {
        if(root == nullptr) return false;
        if(not set.insert(k-(root->val)).second) return true;
        else set.insert(root->val);
        
        return find(root->left, k, set) or find(root->right, k, set);
    }
    
    bool findTarget(TreeNode* root, int k) {
        std::unordered_set<int> set;
        return find(root, k, set);
    }
    bool findTarget2(TreeNode* root, int k) {
        std::vector<int> vec;
        bstToVec(root, vec);
        bool found = false;
        std::sort(vec.begin(), vec.end());
        int size = vec.size();
        int left = 0;
        int right = size-1;
        while(left<right) {
            if(vec[left]+vec[right]==k) {found = true; break;}
            else if(vec[left]+vec[right]<k) left++;
            else right--;
        }
        return found;
    }
    void bstToVec(TreeNode* root, std::vector<int>& vec) {
        if(root) {
            bstToVec(root->left, vec);
            vec.push_back(root->val);
            bstToVec(root->right, vec);
        }
    }
    bool findTarget1(TreeNode* root, int k) {
        std::vector<int> vec;
        bstToVec(root, vec);
        bool found = false;
        int size = vec.size();
        for(int i = 0; i < size-1; i++) {
            for(int j = i+1; j < size; j++) {
                if(vec[i]+vec[j]==k) {found = true; break;}
            }
            if(found) break;
        }
        return found;
    }
};