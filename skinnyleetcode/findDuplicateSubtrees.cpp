/*
 * https://leetcode.com/problems/find-duplicate-subtrees/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
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
    std::string postorder(TreeNode* root, std::unordered_map<std::string, int>& map, std::vector<TreeNode*>& ans) {
        if(root == nullptr) return "+";
        std::string str = to_string(root->val) + ',' + postorder(root->left, map, ans) + ',' + postorder(root->right, map, ans);
        if(not str.empty()) {
            map[str]++;
            if(map[str]==2) ans.push_back(root);
        }
        return str;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::vector<TreeNode*> ans;
        std::unordered_map<std::string, int> map;
        postorder(root, map, ans);
        return ans;
    }
    
    
    
    void inorder(TreeNode* root, std::string& path) {
        if(root == nullptr) return;
        inorder(root->left, path);
        path += to_string(root->val) + '+';
        inorder(root->right, path);
    }
    vector<TreeNode*> findDuplicateSubtrees0(TreeNode* root) {
        if(root == nullptr) return vector<TreeNode*>();
        
        std::unordered_map<std::string, int> map;
        std::vector<TreeNode*> ans;
        std::queue<TreeNode*> queue; queue.push(root);
        while(not queue.empty()) {
            int s = queue.size();
            while(s) {
                TreeNode* front = queue.front(); queue.pop();
                if(front->left) { queue.push(front->left); }
                if(front->right) { queue.push(front->right); }
                s--;
                std::string path;
                inorder(front, path);
                //if(not path.empty()) 
                if(not path.empty()) { 
                    path.pop_back();
                    map[path]++;
                    if(map[path]==2) ans.push_back(front); 
                }
            }
        } 
        
        return ans;
    }
};