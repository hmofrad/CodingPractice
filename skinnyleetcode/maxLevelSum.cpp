/*
 *  https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/submissions/
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
    int bfs(TreeNode* root){
        int ans = 0;
        if(root) {
            int level = 1;
            int maximum = 0;
            std::deque<TreeNode*> queue;
            queue.push_back(root);
            while(not queue.empty()) {
                int size = queue.size();
                int s = 0;
                int temp = 0;
                while(s < size) {
                    auto node = queue.front();
                    if(node->left) queue.push_back(node->left);
                    if(node->right) queue.push_back(node->right);
                    temp += node->val;
                    queue.pop_front();
                    s++;
                }
                if(temp > maximum) {
                    maximum = temp;
                    ans = level;
                }
                level++;
            }
        }
        return(ans);
    }
    
    
    int maxLevelSum1(TreeNode* root) {
        return(bfs(root));    
    }
    
    
    int depth(TreeNode* root) {
        int d = 0;
        if(root) {
            return(max(depth(root->left), depth(root->right)) + 1);
        }
        return(d);
    }
    
    void traverse(TreeNode* root, int level, std::vector<int>& sums) {
        if(root) {
            traverse(root->left, level+1, sums);
            sums[level] += root->val;
            traverse(root->right, level+1, sums);
        }
    }
    
        int maxLevelSum(TreeNode* root) {
        //return(bfs(root));    
        //printf("depth=%d\n", depth(root));
        int d = depth(root);
        std::vector<int> sums(d);
        traverse(root, 0, sums);
        //for(auto s: sums) printf("%d\n", s);
        int max = 0;
        int dep = 0;
        for(int i = 0; i < d; i++) {
            if(sums[i] > max) {
                max = sums[i];
                dep = i+1;
            }
        }
        //printf("d=%d\n", dep);
        return(dep);
    }
    
};