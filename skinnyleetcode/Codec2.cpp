/*
 * https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */
 

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    void preorder_node2str(Node* root, std::string& s) {
        if(root==nullptr) return;
        s += to_string(root->val) + '+' + to_string(root->children.size()) + '+';
        for(Node* child: root->children) {
            preorder_node2str(child, s);
        }
    }
    
    string serialize(Node* root) {
        if(root==nullptr) return std::string();
        
        std::string s;
        preorder_node2str(root, s); 
        //printf("%s\n", s.c_str());
        return s;
    }
    
    std::vector<int> str2vec(std::string s) {
        std::vector<int> ans;
        int len = s.length();
        int j = 0;
        for(int i = 0; i < len; i++) {
            if(s[i] == '+') {
                std::string t = s.substr(j, i-j);
                ans.push_back(stoi(t));
                j=i+1;
            }
        }
        return ans;
    }
    
    Node* preorder_str2node(std::vector<int> vec, int& i) {
        Node* root = new Node();
        root->val = vec[i++];
        int size = vec[i++];
        root->children.resize(size);
        for(int j = 0; j < size; j++) { root->children[j] = preorder_str2node(vec, i); }
        return root;
    }
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.empty()) return nullptr;
        std::vector<int> vec = str2vec(data);
        //for(int v: vec) printf("%d ", v); printf("\n");
        int i = 0;
        return preorder_str2node(vec, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));