/*
 *  https://leetcode.com/problems/binary-tree-pruning/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
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
    TreeNode* BFS(TreeNode* root){
        if(root) {
            while(true) {
                std::deque<struct TreeNode*> queue;
                queue.push_back(root);
                bool has_not_changed = true;
                while(not queue.empty()) {
                    int q_size = queue.size();
                    int s = 0;
                    while(s < q_size) {
                        auto q_front = queue.front();
                       // printf("[%d %d]", q_front->val, ((not q_front->left) and (not q_front->right)));

                        if((q_front->left) and not (q_front->left->val) and ((not q_front->left->left) and (not q_front->left->right))) {
                            delete q_front->left;
                            q_front->left = nullptr;
                            has_not_changed = false;
                        }
                        else if(q_front->left) {
                            queue.push_back(q_front->left);
                        }

                        if((q_front->right) and not (q_front->right->val) and ((not q_front->right->left) and (not q_front->right->right))) {
                            delete q_front->right;
                            q_front->right = nullptr;
                            has_not_changed = false;
                        }
                        else if(q_front->right) {
                            queue.push_back(q_front->right);
                        }
                        queue.pop_front();
                        s++;
                    }
                    printf("\n");
                }
                if(has_not_changed) break;
            }
        }
        return(root);
    }
    void traverse(TreeNode* root) {
        if(root){
            traverse(root->left);
            traverse(root->right);
            printf("%d ", root->val);
        }
    }
    TreeNode* pruneTree1(TreeNode* root) {
        //traverse(root); printf("\n");
        return(BFS(root));
    }
    
    bool hasOne(TreeNode* root){
        bool ret = false;
        if(root) {
            bool b1 = hasOne(root->left);
            bool b2 = hasOne(root->right);
            if(not b1) {
                delete root->left;
                root->left = NULL;
            }
            
            if(not b2) {
                delete root->right;
                root->right = NULL;
            }
            
            ret = (root->val or b1 or b2);
        }
        return(ret);
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        return(hasOne(root) ? root : NULL);
    }
    
};