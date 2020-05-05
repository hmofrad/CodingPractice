/*
 *	https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/
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
    
    TreeNode* convert(std::vector<int>& nums, int left, int right) {
        if(left>right) return nullptr;
        
        int mid = (left+right)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = convert(nums, left, mid-1);
        root->right=convert(nums, mid+1, right);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums, 0, nums.size()-1);
    }
    
    
    /*
    void vec2bst(TreeNode* curr, vector<int>& nums, int index) {
        printf("%d\n", index);
        if(index<0 or index >= nums.size()) return;
        
        if(root==nullptr) root=curr;
        vec2bst(curr->left, nums, index-1); 
        //vec2bst(curr->right, nums, index+1);
    }
    */
    TreeNode* sortedArrayToBST1(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        //TreeNode* root = nullptr;
        
        int size = nums.size();
        int mid = size/2;
        TreeNode* root = new TreeNode(nums[mid]); 
        TreeNode* currL = root;
        TreeNode* currR = root;
        int left=mid-1;
        int right=mid+1;
        while(left>=0) {
            if (left >= 0) {currL->left = new TreeNode(nums[left]); currL = currL->left; left--;}
            if (right < size) {currR->right = new TreeNode(nums[right]); currR = currR->right; right++;}
        }
        return root;
    }
};
















