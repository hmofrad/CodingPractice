/*
 *	https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    int max_depth = 0;
    std::vector<std::vector<int>> ans;
    void dfs(struct TreeNode* root, int depth) {
        if(root == nullptr) {max_depth = max(depth, max_depth); return;} 
        
         if(depth == ans.size()) ans.push_back(std::vector<int>());
         
         dfs(root->left, depth+1);
         dfs(root->right, depth+1);
         ans[depth].push_back(root->val);
    }
    std::vector<std::vector<int>> levelOrderBottom(struct TreeNode* root) {
        dfs(root, 0);
       // printf("%d\n", max_depth);
        std:reverse(ans.begin(), ans.end());
        return ans;
    }
    
    
    
    std::vector<std::vector<int>> rbfs(struct TreeNode* root) {
        std::vector<std::vector<int>> vec;
        std::deque<struct TreeNode*> q;
        if(root) {
            q.push_back(root);
            while(!q.empty()) {
                std::vector<int> t;
                int sz = q.size();
                int s = 0;
                while(s < sz) {
                    auto& f = q.front();
                    if(f->left) {
                        q.push_back(f->left);
                    }
                    if(f->right) {
                        q.push_back(f->right);
                    }
                    t.push_back(f->val);
                    q.pop_front();
                    s++;
                }
                vec.push_back(t);
            }
        }

        for(uint32_t i = 0; i < vec.size()/2; i++) {
            std::swap(vec[i], vec[vec.size()-i-1]);
        }


        return(vec);
    }

    std::vector<std::vector<int>> levelOrderBottom1(struct TreeNode* root) {
        std::vector<std::vector<int>> out = rbfs(root);
        return(out);    
    }

};