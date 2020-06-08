/*
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
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
class Codec {
public:

    // Encodes a tree to a single string.
    
    std::string tree2str(TreeNode* root) {
        //root->val=10;
        if(root == nullptr) return "#";

        return  tree2str(root->left) + "+" + tree2str(root->right) + "+" + to_string(root->val);
    }
    
    
    string serialize(TreeNode* root) {
        //root->val=10;
        return tree2str(root);
    }

    TreeNode* str2tree(std::string str, int& i) {
        //printf("%d %d\n", i, str.size());
        int size = str.size();
        //if(i<0) return nullptr;
        int j = i-1;
        while(j>=0 and str[j]!='+') j--;
        std::string t = j>=0 ? str.substr(j+1, i-j) : str.substr(0, i-j);
        //printf("%d %d %s\n", i, j, t.c_str());
        TreeNode* root = t=="#" ? nullptr : new TreeNode(stoi(t));
        i=j-1;
        if(root) { 
            root->right = str2tree(str, i);
            root->left = str2tree(str, i);
        }
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //printf("%s\n", data.c_str());
        int i = data.length()-1;
        TreeNode* root = nullptr;
        root = str2tree(data, i);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));