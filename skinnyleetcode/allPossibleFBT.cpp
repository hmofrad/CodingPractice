/*
 *  https://leetcode.com/problems/all-possible-full-binary-trees/
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
    unordered_map<int, std::vector<TreeNode*>> combs;
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N == 0 || N % 2 == 0) return {};
        return(all_combinations(1, N));
    }
    
    std::vector<TreeNode*> all_combinations(int start, int end) {
        if(start == end) {
            return {new TreeNode(0)};
        }
        if(combs.count(end-start)) {
            return(combs[end-start]);
        }
        
        std::vector<TreeNode*> out;
        
        for(int i = start+1; i <= end; i+=2) {
            std::vector<TreeNode*> left = all_combinations(start, i-1);
            std::vector<TreeNode*> right = all_combinations(i+1, end);
            for(auto l: left) {
                for(auto r: right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    out.push_back(root);
                }
            }
        }    
        combs[end-start] = out;
        return(out);
    }

};