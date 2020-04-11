/*
 *  https://leetcode.com/problems/trim-a-binary-search-tree/
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
    TreeNode* root1;
    void vec2bst(std::vector<int> vec, int i) {
        if(i == vec.size()) return;
        if(not root1) {
            root1 = new TreeNode(vec[i]);
        }
        else {
            TreeNode* node = new TreeNode(vec[i]);
            node->left = root1;
            root1 = node;
        }
        vec2bst(vec, i+1);
    }
    
    void bst2vec(TreeNode* root, std::vector<int>& vec) {
        if(root) {
            bst2vec(root->left, vec);
            vec.push_back(root->val);
            bst2vec(root->right, vec);
        }
    }
    
    void traverse(TreeNode* root) {
        if(root) {
            traverse(root->left);
            printf("%d ", root->val);
            traverse(root->right);
        }
    }
    
    TreeNode* trimBST1(TreeNode* root, int L, int R) {
        std::vector<int> vec;
        bst2vec(root, vec);
        
        int start = 0;
        while(vec[start] < L) start++;
        
        int end = vec.size()-1;
        while(vec[end] > R) end--;
        //for(int v: vec) printf("%d ", v); printf("\n");
        
        //printf("%d %d\n", start, end);
        
        vec.erase(vec.begin(), vec.begin()+start);
        //for(int v: vec) printf("%d ", v); printf("\n");
        end -= start;
        //printf("%d\n", end);
        if(end != vec.size()-1)
        vec.erase(vec.end()-end, vec.end());
        
        for(int v: vec) printf("%d ", v); printf("\n");
        
        root1 = nullptr;
        vec2bst(vec, 0);
        traverse(root1); printf(">\n");
        return(root1);
    }
    
    TreeNode* trimBST2(TreeNode* root, int L, int R) {
        
        if (root == nullptr) return nullptr;
        
        if (root->val < L) return trimBST(root->right, L, R);
        if (root->val > R) return trimBST(root->left, L, R);
        
        
        
        root->left  = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        
        return root;
    }
    
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == nullptr) return root;
        
        if(root->val >= L and root->val <= R) {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
        }
        
        if(root->val < L ) return trimBST(root->right, L, R);
        if(root->val > R) return trimBST(root->left, L, R);
        return root;
    }
    
    

    
    
    
    
    
    
    
    
    
    
    
    
};