/*
 *  https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/submissions/
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
class FindElements {
public:
    TreeNode* root1;
    
    void fixTree(TreeNode* root, int x) {
        if(root == NULL) return;
        root->val = x;
        
        //if(root->left) root->left->val = 2*x+1;
        //if(root->right) root->right->val = 2*x+2;
        
        fixTree(root->left, 2*x+1);
        fixTree(root->right, 2*x+2);
    }
    /*
    void fixTree(TreeNode* root) {
        if(root) {
            int x = 0;
            //root->val = 0;
            std::deque<TreeNode*> queue;
            queue.push_back(root);
            while(not queue.empty()) {
                int size = queue.size();
                int s = 0;
                y = x*2;
                while(s < size) {
                    auto front_n = queue.front();
                    if(front_n->left) queue.push_back(front_n->left);
                    if(front_n->right) queue.push_back(front_n->right);
                    front_n->val = x;
                    queue.pop_front();
                    x++;
                    s++;
                }
            }
        }
    }
    */
    void traverse(TreeNode* root) {
        if(root) {
            traverse(root->left);
            printf("%d\n", root->val);
            traverse(root->right);
        }
    }
    
    FindElements(TreeNode* root) {
        root1 = root;
        fixTree(root1, 0);
        traverse(root1);
    }
    
    bool findMe(TreeNode* root, int target) {
        bool ret = false;
        if(root) {
            if(root->val == target) {
                ret = true;
            }
            else {
                ret = findMe(root->left, target) or findMe(root->right, target);
            }
        }
        return(ret);
    }
    
    bool find(int target) {
        return(findMe(root1, target));
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */