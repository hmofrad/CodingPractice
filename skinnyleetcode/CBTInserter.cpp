/*
 *  https://leetcode.com/problems/complete-binary-tree-inserter/submissions/
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
class CBTInserter {
public:
    std::queue<TreeNode*> queue;
    TreeNode* head;
    CBTInserter(TreeNode* root) {
        std::queue<TreeNode*> temp;
        head=root;
        temp.push(head);
        while(not temp.empty()) {
            TreeNode* front = temp.front();
            temp.pop();
            if(not front->left or not front->right) queue.push(front);
            if(front->left) temp.push(front->left);
            if(front->right) temp.push(front->right);
        }
    }
    int insert(int v) {
        TreeNode* node  = new TreeNode(v);
        TreeNode* front = queue.front();
        
        if(not front->left) {front->left = node; queue.push(node);}
        else {front->right = node; queue.push(node); queue.pop();}
        return front->val;
    }
    
    int insert1(int v) {
        //TreeNode* parent = nullptr;
        //TreeNode* left = nullptr;
        
        queue.push(head);
        
        while(true) {
            //int size = queue.size();
            //int s = 0;
            //parent = queue.front();
            //while(s<size) {
            TreeNode* front = queue.front();
                queue.pop();
                if(front->right) {queue.push(front->left); queue.push(front->right);}
                else {
                    TreeNode* node = new TreeNode(v);
                    if(not front->left) front->left = node;
                    else front->right = node;
                    return front->val;
                }
                //if(front->left and front->right) {queue.push(front->left); queue.push(front->right);}
                //else if(not front->left) {front->left = node; return front->val;}
                //else {front->right = node; return front->val;}
            //    s++;
            //}
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */