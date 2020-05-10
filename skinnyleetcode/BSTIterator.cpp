/*
 *	https://leetcode.com/problems/binary-search-tree-iterator/submissions/
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

class BSTIterator {
public:
    std::stack<TreeNode*> stack;
    BSTIterator(TreeNode* root) {
        leftMostInorder(root);
    }
    void leftMostInorder(TreeNode* root) {
        while(root) {stack.push(root); root=root->left;}
    }
    /** @return the next smallest number */
    int next() {
        TreeNode* top = stack.top(); stack.pop();
        if(top->right) leftMostInorder(top->right);
        return top->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return not stack.empty();
    }
};


class BSTIterator1 {
public:
    std::vector<int> vec;
    int index;
    int size;
    void toVec(TreeNode* root) {
        if(root) {
            toVec(root->left);
            vec.push_back(root->val);
            toVec(root->right);
        }
    }
    BSTIterator1(TreeNode* root) {
        toVec(root);
        index = 0;
        size = vec.size();
    }
    
    /** @return the next smallest number */
    int next() {
        int value = hasNext() ? vec[index] : -1;
        index++;
        return value;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index < size;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */