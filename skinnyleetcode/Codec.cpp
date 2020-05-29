/*
 *	https://leetcode.com/problems/serialize-and-deserialize-bst/submissions/
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


class Codec {
public:
    void postorder(TreeNode* root, std::string& str) {
        if(root) {
            postorder(root->left, str);
            postorder(root->right, str);
            str += to_string(root->val) + '+';
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string encoded; 
        if(root==nullptr) return encoded;        
        postorder(root, encoded);
        encoded.pop_back();
        return encoded;
    }
    
    std::vector<int> str2vec(std::string data) {
        std::vector<int> v;
        int j = 0;
        int length = data.length();
        for(int i = 0; i < length; i++) {
            if(data[i]=='+') {
                int l = i-j;
                std::string s = data.substr(j, l);
                v.push_back(stoi(s));
                j = i+1;
            }
        }
        std::string s = data.substr(j);
        v.push_back(stoi(s));
        return v;
    }
    
    TreeNode* vec2bst(std::vector<int>& vec, int low, int high) {
        if(vec.empty()) return nullptr;
        
        int value = vec.back(); 
        //printf("%d %d %d\n", value , low, high);
        if(value<low or value > high) return nullptr;
        vec.pop_back();
        TreeNode* root = new TreeNode(value);
        root->right = vec2bst(vec, value, high);
        root->left = vec2bst(vec, low, value);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        std::vector<int> v = str2vec(data);
        //for(auto i: v) printf("%d ", i); printf("\n");
        //printf("%s %d\n", data.c_str(), v.size());
        return vec2bst(v, INT_MIN, INT_MAX);
    }
};


class Codec1 {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string data;
        if(root == nullptr) return data;
        std::queue<TreeNode*> queue;
        queue.push(root);
        while(not queue.empty()) {
            TreeNode* front = queue.front(); queue.pop();
            std::string s = front ? to_string(front->val) : "n";
            data += (s + '+');
            if(front) {
                queue.push(front->left);
                queue.push(front->right);
            }
        }
        return data;
    }
    
    int extract(std::string& data, int& i) {
        int j = i;
        while(data[i] != '+') i++;
        std::string t = data.substr(j, i-j);
        i++;
        int v = (t=="n") ? -1 : stoi(t);
        return v;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        int index = 0;
        TreeNode* root = new TreeNode(extract(data, index));
        std::queue<TreeNode*> queue; queue.push(root);
        int len = data.length();
        while(index < len) {
            TreeNode* front = queue.front(); queue.pop();
            int left = extract(data, index);
            int right = extract(data, index);
            if(left>=0) { front->left = new TreeNode(left); queue.push(front->left); }
            if(right>=0) { front->right = new TreeNode(right); queue.push(front->right); }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));