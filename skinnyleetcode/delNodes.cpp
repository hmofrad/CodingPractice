/*
 *  https://leetcode.com/problems/delete-nodes-and-return-forest/submissions/
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
    
    std::vector<TreeNode*> forests;
    std::unordered_set<int> nums;
    bool lookup_node(TreeNode* root) {
        if(not root) return false;
        
        if(nums.find(root->val) != nums.end()) return true;
        else return false;
            
    }
    
    void afforestation1(TreeNode* root) {
        if(root) {
            if(lookup_node(root->left)) {
                root->left = nullptr;
            }
            else {
                afforestation1(root->left);
            }
            if(lookup_node(root->right)) {
                root->right = nullptr;
            }
            else {
                afforestation1(root->right);
            }
            
        }
    }
    
    void afforestation(TreeNode* root) {
        if(root) {
            if(lookup_node(root)) {
                if(root->left) forests.push_back(root->left);
                if(root->right) forests.push_back(root->right);
                root = nullptr;
            }
            else {
                afforestation(root->left);
                afforestation(root->right);
            }
            
        }
    }
    vector<TreeNode*> delNodes1(TreeNode* root, vector<int>& to_delete) {
        
        //for(int n: to_delete) {
          //  nums.insert(n] = true;
        //}
        
        
        
        afforestation(root);
        if(root and not lookup_node(root)) {
            afforestation1(root);
            forests.push_back(root);
        } 
        
        return(forests);
    }
    
    TreeNode* afforestation2(TreeNode* root, bool isRoot) {
        if(not root) return nullptr;
        
        if(nums.count(root->val)) {
            //isRoot = false;
            afforestation2(root->left, true);
            afforestation2(root->right, true);
            return(nullptr);
        }
        else {
            root->left = afforestation2(root->left, false);
            root->right = afforestation2(root->right, false);
        }
        
        
        if(isRoot) forests.push_back(root);
        
        return(root);
    }
    
    
    void afforestation3(TreeNode* root) {
        if(root) {
            std::deque<TreeNode*> queue;
            queue.push_back(root);
            while(not queue.empty()) {
                TreeNode* front = queue.front();
                queue.pop_front();
                
                if(front->left) queue.push_back(front->left);
                if(front->right) queue.push_back(front->right);
                
                if(nums.count(front->val)) {
                    if(front->left and not nums.count(front->left->val)) forests.push_back(front->left);
                    if(front->right and not nums.count(front->right->val)) forests.push_back(front->right);
                }
                else {
                    if(front->left and nums.count(front->left->val)) front->left = nullptr;
                    if(front->right and nums.count(front->right->val)) front->right = nullptr;
                }
                
            }
            if(root and not nums.count(root->val)) forests.push_back(root);
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int n: to_delete) {
            nums.insert(n);
        }
        
        //afforestation2(root, true);
        afforestation3(root);
        
        
        
        return(forests);
    }
    
    
    
    
    
    
    
    
    
};