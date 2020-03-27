/*
 *  https://leetcode.com/problems/n-ary-tree-preorder-traversal/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
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
class Solution {
public:
    std::vector<int> path;
    
    void preorder1(Node* root) {
        if(root) {
            path.push_back(root->val);
            if(not root->children.empty()) {
                for(auto child: root->children) {
                    preorder1(child);
                }
            }
        }        
    }
    
        
    void dfs(Node* root) {
        if(root){
            std::vector<Node*> stack;
            stack.push_back(root);
            while(not stack.empty()) {
                Node* node = stack.back();
                
                stack.pop_back();
                
                path.push_back(node->val);
                if(not node->children.empty()) {
                    for(int i = node->children.size()-1; i >= 0; i--) {
                    //for(auto child: node->children) {
                        stack.push_back(node->children[i]);
                    }
                }
            }
        }
    }
    
    vector<int> preorder(Node* root) {
        //preorder1(root);
        dfs(root);
        return(path);
    }
};